#ifndef Aurealis_SYSTEMMANAGER_H
#define Aurealis_SYSTEMMANAGER_H

#include <malloc.h>
#include <pspkernel.h>
#include <pspctrl.h>
#include <psputility.h>
#include <string.h>

#include <Aurealis/Graphics/RenderManager.h>

#define RAM_BLOCK      (1024 * 1024)

namespace Aurealis
{
	namespace System
	{
		class SystemManager
		{
		private:

			//static access
			static SystemManager m_SystemManager;

			//dialog params
			pspUtilityMsgDialogParams dialog;
			pspUtilityNetconfData networkData;
			void ConfigureDialog(pspUtilityMsgDialogParams *dialog, size_t dialog_size);

			//memory
			u32 ramAvailableLineareMax (void);

			//input
			SceCtrlData oldPadData,newPadData;

		public:


			static SystemManager* Instance();

			void Init();

			//memory
			u32 ramAvailable (void);

			//system dialogs
			void ShowMessage(const char *message);
			void ShowMessageError(const char *message,int error);
			int ShowMessageYesNo(const char *message);
			int ShowOSK(unsigned short *descritpion,unsigned short *outtext,int maxtextinput);
			bool ShowNetworkDialog();

			//input
			void InputUpdate();
			bool KeyPressed(PspCtrlButtons button);
			bool KeyHold(PspCtrlButtons button);
			float GetAnalogX();
			float GetAnalogY();

		};
	}
}

#endif

