#pragma once
#include <malloc.h>
#include <pspkernel.h>
#include <pspctrl.h>
#include <psputility.h>
#include <string.h>
#define RAM_BLOCK      (1024 * 1024)

namespace Shadow::System {
	u32 ramAvailableMax(void);
	u32 freeMemory(void);
}