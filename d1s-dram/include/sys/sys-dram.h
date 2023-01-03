#ifndef __SYS_DRAM_H__
#define __SYS_DRAM_H__

#include <byteorder.h>
#include <config.h>
#include <endian.h>
#include <io.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <types.h>

typedef struct dram_param {
  uint32_t dram_clk;
  uint32_t dram_type;
  uint32_t dram_zq;
  uint32_t dram_odt_en;
  uint32_t dram_para1;
  uint32_t dram_para2;
  uint32_t dram_mr0;
  uint32_t dram_mr1;
  uint32_t dram_mr2;
  uint32_t dram_mr3;
  uint32_t dram_tpr0;
  uint32_t dram_tpr1;
  uint32_t dram_tpr2;
  uint32_t dram_tpr3;
  uint32_t dram_tpr4;
  uint32_t dram_tpr5;
  uint32_t dram_tpr6;
  uint32_t dram_tpr7;
  uint32_t dram_tpr8;
  uint32_t dram_tpr9;
  uint32_t dram_tpr10;
  uint32_t dram_tpr11;
  uint32_t dram_tpr12;
  uint32_t dram_tpr13;
  uint32_t reserve[8];
} dram_param_t;

/*
 * Init System UART
 */
void sys_dram_init();

#endif // __SYS_DRAM_H__