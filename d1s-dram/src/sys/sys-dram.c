#include <byteorder.h>
#include <endian.h>
#include <io.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <types.h>
#include <sys-dram.h>
#include <dram.h>
#include <uart.h>

static const struct dram_param param = {
    .dram_clk = 528,
    .dram_type = 2,
    .dram_zq = 0x07b7bf9,
    .dram_odt_en = 0x00,
    .dram_para1 = 0x000000d2,
    .dram_para2 = 0x00000000,
    .dram_mr0 = 0x00000e73,
    .dram_mr1 = 0x02,
    .dram_mr2 = 0x0,
    .dram_mr3 = 0x0,
    .dram_tpr0 = 0x00471992,
    .dram_tpr1 = 0x0131a10c,
    .dram_tpr2 = 0x00057041,
    .dram_tpr3 = 0xb4787896,
    .dram_tpr4 = 0x0,
    .dram_tpr5 = 0x48484848,
    .dram_tpr6 = 0x48,
    .dram_tpr7 = 0x1621121e,
    .dram_tpr8 = 0x0,
    .dram_tpr9 = 0x0,
    .dram_tpr10 = 0x00000000,
    .dram_tpr11 = 0x00030010,
    .dram_tpr12 = 0x00000035,
    .dram_tpr13 = 0x34000000,
};

void sys_dram_init() {
    sys_uart_printf("DRAM CLK     -> %d", param.dram_clk);
    sys_uart_printf("DRAM TYPE    -> %d", param.dram_type);
    sys_uart_printf("DRAM ZQ      -> %x", param.dram_zq);
    sys_uart_printf("Start Init DRAM...");
    init_DRAM(0, param); 
}
