/*
 * File:   main.c
 * Author: hojun
 *
 * Created on 2016년 11월 2일 (수), 오후 2:21
 */

#include <xc.h>

// CONFIG1
#pragma config FOSC = INTOSC    // Oscillator Selection Bits (INTOSC oscillator; I/O function on CLKIN pin)
#pragma config WDTE = ON        // Watchdog Timer Enable (WDT enabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable (PWRT disabled)
#pragma config MCLRE = ON       // MCLR Pin Function Select (MCLR/VPP pin function is MCLR)
#pragma config CP = OFF         // Flash Program Memory Code Protection (Program memory code protection is disabled)
#pragma config BOREN = ON       // Brown-out Reset Enable (Brown-out Reset enabled)
#pragma config CLKOUTEN = OFF   // Clock Out Enable (CLKOUT function is disabled. I/O or oscillator function on the CLKOUT pin)

// CONFIG2
#pragma config WRT = OFF        // Flash Memory Self-Write Protection (Write protection off)
#pragma config PPS1WAY = ON     // PPSLOCK bit One-Way Set Enable bit (PPSLOCKED Bit Can Be Cleared & Set Once)
#pragma config PLLEN = OFF      // PLL Enable (4x PLL disabled)
#pragma config STVREN = ON      // Stack Overflow/Underflow Reset Enable (Stack Overflow or Underflow will cause a Reset)
#pragma config BORV = LO        // Brown-out Reset Voltage Selection (Brown-out Reset Voltage (Vbor), low trip point selected.)
#pragma config LPBOREN = OFF    // Low Power Brown-out Reset enable bit (LPBOR is disabled)
#pragma config LVP = ON         // Low-Voltage Programming Enable (Low-voltage programming enabled)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#define _XTAL_FREQ 1000000 
// just for compiler. To change the osc speed, change OSCCON register

void main(void) {
    // default setup: internal low freq, 
    
    OSCCON = 0b01011000;  // SPLLEN = 0, IRCF = 1 MHz, SCS = 0 -> 1MHz setting
    WDTCON = 0b00011000;  // 4s interval for watchdog timer
    CLRWDT();
    TRISCbits.TRISC3 = 0;
    while(1)
    {
        PORTCbits.RC3 = 1;
        __delay_ms(50);
        PORTCbits.RC3 = 0;
        __delay_ms(10);
        SLEEP();
        
        // sleep
    
        // wakeup
    }
    return;
}
