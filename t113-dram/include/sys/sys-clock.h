#ifndef __SYS_CLOCK_H__
#define __SYS_CLOCK_H__

#include <byteorder.h>
#include <config.h>
#include <endian.h>
#include <io.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <types.h>

void sys_clock_init();

void sdelay(int loops);

#endif // __SYS_CLOCK_H__
