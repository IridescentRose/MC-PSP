#pragma once

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
			//dialog params
			pspUtilityMsgDialogParams dialog;
			void ConfigureDialog(pspUtilityMsgDialogParams *dialog, size_t dialog_size);

			//memory
			u32 ramAvailableMax (void);

			//input
			SceCtrlData oldPadData,newPadData;

		public:
			void Init();

			//memory
			u32 freeMemory (void);

			//system dialogs
			void ShowMessage(const char *message);
			void ShowMessageError(const char *message,int error);
			int ShowMessageYesNo(const char *message);
			int ShowOSK(unsigned short *descritpion,unsigned short *outtext,int maxtextinput);
			
			//input
			void InputUpdate();
			bool KeyPressed(PspCtrlButtons button);
			bool KeyHold(PspCtrlButtons button);
			float GetAnalogX();
			float GetAnalogY();

		};

		extern SystemManager g_System;
	}
}
