#include "common.h"
#include "mini_uart.h"
//call this from our boot assembly file
void kernel_main(){
    uart_init();
    uart_send_string("RazPi Bare Metal Initializing\n");
#if RPI_VERSION == 3
    uart_send_string("\tBoard: RazPi3");
#endif

uart_send_string("\n\nDONE\n");
    while(1){//infinite loop to send back input user types
        uart_send(uart_recv());
    }
}