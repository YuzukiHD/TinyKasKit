#include <types.h>
#include <io.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <endian.h>
#include <byteorder.h>
#include <config.h>
#include <sys-uart.h>
#include <sys-clock.h>
#include <sys-dram.h>
#include <uart.h>

void show_banner() {
  sys_uart_printf("    ___                    \r\n");
  sys_uart_printf("   /   |____  ___  ____ ___ \r\n");
  sys_uart_printf("  / /| /_  / / _ \\/ __ `__ \\\r\n");
  sys_uart_printf(" / ___ |/ /_/  __/ / / / / /\r\n");
  sys_uart_printf("/_/  |_/___/\\___/_/ /_/ /_/ \r\n");
  sys_uart_printf("=======================================\r\n");
  sys_uart_printf("Version: %s, Commit: %s\r\n", PROJECT_VER, PROJECT_GIT_HASH);
  sys_uart_printf("=======================================\r\n");
}

int main() {
  sys_uart_init();  // init UART0
  sys_clock_init(); // init System Clock
  show_banner();
  sys_dram_init();  // init DRAM
}
