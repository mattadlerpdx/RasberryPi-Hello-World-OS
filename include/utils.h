#pragma once

#include common.h
void delay(u64 ticks); // delay number of ticks
void put32(u64 address, u32 value);
u32 get32(u64 address);// returns a 32bit address