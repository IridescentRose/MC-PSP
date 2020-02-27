#include <pspsdk.h>
#include <pspkernel.h>
#include <string.h>

PSP_MODULE_INFO("MediaEngine", 0x1006, 1, 1);
PSP_MAIN_THREAD_ATTR(0);

void me_run(void);
void me_end(void);

#define store_tag(index, hi, lo) __asm__ (".set push\n" \
                 ".set noreorder\n" \
                 "mtc0 %0, $28\n"   \
                 "mtc0 %1, $29\n"   \
                 ".set pop\n"       \
             ::"r"(lo),"r"(hi));    \
             __builtin_allegrex_cache(0x11, index);

void dcache_inv_all()
{
   for(int i = 0; i < 16384; i += 64) {
      store_tag(i, 0, 0);
      __builtin_allegrex_cache(0x13, i);
      __builtin_allegrex_cache(0x11, i);
   }
}

void dcache_inv_range(void *addr, int size)
{
   int i, j =(int)addr;
   for(i = j; i < size+j; i += 64)
      __builtin_allegrex_cache(0x19, i);
}

void dcache_wbinv_all()
{
   for(int i = 0; i < 8192; i += 64)
   {
      __builtin_allegrex_cache(0x14, i);
      __builtin_allegrex_cache(0x14, i);
   }
}

void dcache_wbinv_range(void *addr, int size)
{
   int i, j = (int)addr;
   for(i = j; i < size+j; i += 64)
      __builtin_allegrex_cache(0x1b, i);
}


int module_start(SceSize args, void *argp)
{
    unsigned int k1 = pspSdkSetK1(0);
    memcpy((void *)0xbfc00040, me_run, (int)(me_end - me_run));
	sceKernelDcacheWritebackAll();
	sceSysregMeResetEnable();
	sceSysregMeBusClockEnable();
	sceSysregMeResetDisable();
	pspSdkSetK1(k1);
	return 0;
}

int module_stop()
{
    unsigned int k1 = pspSdkSetK1(0);
    sceSysregMeResetEnable();
	pspSdkSetK1(k1);
	return 0;
}