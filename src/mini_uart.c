#include "gpio.h"
#include "utils.h"
#include "peripherals/auxRegs.h"

#include "mini_uart.h"

#define TXD 14
#define RXD 15


void uart_init(){
    gpio_pin_set_fun(TXD, GFALt5);
    gpio_pin_set_fun(RXD, GFALt5);

    REGS_AUX->enables = 1;
    REGS_AUX->mu_control = 0;
    REGS_AUX->mu_ier = 0;
    REGS_AUX->mu_lcr = 3;
    REGS_AUX-mu_mcr = 0;
#if RPI_VERSION == 3
    REGS_AUX->mu_baud_rate = 270;
#endif

#if RPI_VERSION == 4
    REGS_AUX->mu_baud_rate = 541;
#endif

REGS_AUX -> mu_control = 3;
uart_send('\r');
uart_send('\n');
uart_send('\n');
}

void uart_send(char c){
    while (!(REGS_AUX->mu_lsr & 0x20));
    
    REGS_AUX->mu_io = c;

}
char uart_recv(){
    while (!(REGS_AUX-> mu_lsr &1));
    return REGS_AUX->mu_io & 0xff;
}
void uart_send_string(char *str){
    while (*str){
        if (*str == '\n'){
            uart_send('\r');
        }
        uart_send(*str);
        ++str;
    }

}