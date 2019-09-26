#include <mclib/network/Network.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
namespace mc {
namespace network {

class NetworkInitializer {
private:
public:
    MCLIB_API NetworkInitializer();
    MCLIB_API ~NetworkInitializer();

    NetworkInitializer(const NetworkInitializer& rhs) = delete;
    NetworkInitializer& operator=(const NetworkInitializer& rhs) = delete;
};

#ifdef _WIN32
NetworkInitializer::NetworkInitializer() {
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);
}
NetworkInitializer::~NetworkInitializer() {
    WSACleanup();
}
#else
NetworkInitializer::NetworkInitializer() {

}
NetworkInitializer::~NetworkInitializer() {

}
#endif

NetworkInitializer initializer;

IPAddresses Dns::Resolve(const std::string& host) {
    //TODO: RESOLVE DNS TO IP!
	
	IPAddresses list;
    
    return list;
}

} // ns network
} // ns mc
