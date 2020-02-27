TARGET = mediaengine
OBJS = main.o me.o

INCDIR = 
CFLAGS = -O2 -G0 -Wall
CXXFLAGS = $(CFLAGS) -fno-exceptions -fno-rtti
ASFLAGS = $(CFLAGS)

LDFLAGS = -nostartfiles
LIBS = -lpspkernel
USE_KERNEL_LIBC=1
USE_KERNEL_LIBS=1

BUILD_PRX = 1
PSP_FW_VERSION=500

PSPSDK=$(shell psp-config --pspsdk-path)
include $(PSPSDK)/lib/build.mak