#include "gpio.h"

void gpio_pin_set_function(u8 pinNumber, GpioFunc func){
    u8 bitStart = (pinNumber *3)% 30;
    u8 reg = pinNumber / 10;

    u32 selector = REGS_GPIO-> func_select[regs];
    selector &= ~(7 << bitStart);// clear out 3 bits for that bit section and shift it over
    selector |= (func << bitStart);// OR in value we want to turn on bits in specific register

    REGS_GPIO->func_select [reg] = selector;// now we write to the register with the new value
}

void gpio_pin_enable (u8 pinNumber){
    REGS_GPIO -> pupd_enable = 0;
    delay (150);
    REGS_GPIO->pupd_enable_clocks[pinNumber/32]= 1 << (pinNumber%32);
    delay(150);
    REGS_GPIO->pupd_enable = 0;
    REGS_GPIO->pupd_enable_clocks[pinNumber/32]= 0;
}