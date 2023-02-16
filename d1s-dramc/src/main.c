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
  sys_uart_printf("    ____ ________    ____  ____  ___    __  ___\r\n");
  sys_uart_printf("   / __ <  / ___/   / __ \\/ __ \\/   |  /  |/  /\r\n");
  sys_uart_printf("  / / / / /\\__ \\   / / / / /_/ / /| | / /|_/ / \r\n");
  sys_uart_printf(" / /_/ / /___/ /  / /_/ / _, _/ ___ |/ /  / /  \r\n");
  sys_uart_printf("/_____/_//____/  /_____/_/ |_/_/  |_/_/  /_/   \r\n");
  sys_uart_printf("======================================================\r\n");
  sys_uart_printf("YuzukiTsuru <gloomyghost@gloomyghost.com>\r\n");
  sys_uart_printf("Commit: %x\r\n", PROJECT_GIT_HASH);
  sys_uart_printf("======================================================\r\n");
}

int main() {
  sys_uart_init();  // init UART0
  sys_clock_init(); // init System Clock

  show_banner();    // Show banner
  
  sys_dram_init();
}
