#include "NetworkDriver.h"
#include "Dialogs.h"

namespace Shadow::System::Network {
	void Init() {
		//We need to load some basic kernel modules in order to use networking features

		sceUtilityLoadNetModule(PSP_NET_MODULE_HTTP);
		sceUtilityLoadNetModule(PSP_NET_MODULE_PARSEHTTP);
		sceUtilityLoadNetModule(PSP_NET_MODULE_PARSEURI);
		sceUtilityLoadNetModule(PSP_NET_MODULE_INET);
		sceUtilityLoadNetModule(PSP_NET_MODULE_COMMON);
		sceUtilityLoadNetModule(PSP_NET_MODULE_SSL);

		//Result stores our codes from the initialization process
		int result = 0;
		result = sceNetInit(128 * 1024, 42, 0, 42, 0); //Creates the network manager with a buffer
		if (result < 0) { //These If Blocks close the game on an error
			sceKernelExitGame();
		}
		result = sceNetInetInit(); //Initializes Inet
		if (result < 0) {
			sceKernelExitGame();
		}
		result = sceNetApctlInit(0x10000, 48); //Initializes Access Point Control
		if (result < 0) {
			sceKernelExitGame();
		}
		result = sceNetResolverInit(); //Initializes DNS resolver (unused)
		if (result < 0) {
			sceKernelExitGame();
		}
	}
	bool autoConnect() {
		int result = sceNetApctlConnect(1);	//Connects to your first (primary) internet connection.

		//Displays connection status
		int err;
		while (1) {
			int state;
			err = sceNetApctlGetState(&state);
			if (err != 0)
			{
				return false;
			}
			if (state == 4)
				return true;  // connected!

			sceKernelDelayThread(1000 * 50); //50 MS Delay;
		}
	}

	bool dialogConnect() {
		return Dialogs::ShowNetworkDialog();
	}

	void Cleanup() {
		
		//NET
		sceNetApctlTerm();
		sceNetResolverTerm();
		sceNetInetTerm();
		sceNetTerm();
		
		//Modules
		sceUtilityUnloadNetModule(PSP_NET_MODULE_HTTP);
		sceUtilityUnloadNetModule(PSP_NET_MODULE_PARSEHTTP);
		sceUtilityUnloadNetModule(PSP_NET_MODULE_PARSEURI);
		sceUtilityUnloadNetModule(PSP_NET_MODULE_INET);
		sceUtilityUnloadNetModule(PSP_NET_MODULE_COMMON);
	}
}