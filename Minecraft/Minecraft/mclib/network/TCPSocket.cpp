#include <mclib/network/TCPSocket.h>

#include <mclib/common/DataBuffer.h>

#include <iostream>

#ifdef _WIN32
#define WOULDBLOCK WSAEWOULDBLOCK
#define MSG_DONTWAIT 0
#else
#define WOULDBLOCK EWOULDBLOCK
#endif

namespace mc {
namespace network {

TCPSocket::TCPSocket()
    : Socket(Socket::TCP), m_Port(0)
{
    m_Handle = INVALID_SOCKET;
}

bool TCPSocket::Connect(const IPAddress& address, unsigned short port) {
    if (this->GetStatus() == Connected)
        return true;

    
	m_Handle = socket(PF_INET, SOCK_STREAM, 0);
	struct sockaddr_in name;

	name.sin_family = AF_INET;
	name.sin_port = htons(port); //Default Port
	inet_pton(AF_INET, address.ToString().c_str(), &name.sin_addr.s_addr);
	connect(m_Handle, (struct sockaddr*) & name, sizeof(name)); //Full connection!

    this->SetStatus(Connected);
    m_RemoteIP = address;
    m_Port = port;
    return true;
}

size_t TCPSocket::Send(const unsigned char* data, size_t size) {
    if (this->GetStatus() != Connected)
        return 0;

    size_t sent = 0;

    while (sent < size) {
        int cur = ::send(m_Handle, reinterpret_cast<const char*>(data + sent), size - sent, 0);
        if (cur <= 0) {
            Disconnect();
            return 0;
        }
        sent += cur;
    }

    return sent;
}

std::size_t TCPSocket::Receive(DataBuffer& buffer, std::size_t amount) {
    buffer.Resize(amount);
    buffer.SetReadOffset(0);

    int recvAmount = recv(m_Handle, (char*)&buffer[0], amount, MSG_DONTWAIT);
    if (recvAmount <= 0) {
#if defined(_WIN32) || defined(WIN32)
        int err = WSAGetLastError();
#else
        int err = errno;
#endif
        if (err == WOULDBLOCK) {
            buffer.Clear();
            return 0;
        }

        Disconnect();
        buffer.Clear();
        return 0;
    }
    buffer.Resize(recvAmount);
    return recvAmount;
}

DataBuffer TCPSocket::Receive(std::size_t amount) {
    std::unique_ptr<char[]> buf(new char[amount]);

    int received = ::recv(m_Handle, buf.get(), amount, MSG_DONTWAIT);

    if (received <= 0) {
#if defined(_WIN32) || defined(WIN32)
        int err = WSAGetLastError();
#else
        int err = errno;
#endif
        if (err == WOULDBLOCK)
            return DataBuffer();

        Disconnect();
        return DataBuffer();
    }

    return DataBuffer(std::string(buf.get(), received));
}

} // ns network
} // ns mc
