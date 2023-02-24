#pragma once

//define init methods, read and write functions
//used throughout the program
void uart_init();// inititialize char
char uart_recv();// recieve a char
void uart_send (char c);// send a char
void uart_send_string(char * str);//send a full string