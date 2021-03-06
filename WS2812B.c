#include <xc.h>
#include "WS2812B.h"

void InitWS2812(void) {
    //Data line for LED is RD4
    LATDbits.LATD4 = 0;
    TRISDbits.TRISD4 = 0;
    TRISDbits.TRISD5 = 1;
    TRISDbits.TRISD6 = 0;
    //Uncomment lines below if using a pullup resistor on data line
    //Doesn't seem to be necessary
    //WDTCONbits.ADSHR = 1;
    //ODCON3bits.SPI2OD = 1;
    //WDTCONbits.ADSHR = 0;
    SSP2STATbits.CKE = 1;
    SSP2CON1bits.CKP = 0; //SPI mode 0,0
    SSP2CON1bits.SSPM = 0b0000; //SPI Master - FOSC/4 = 8 MHz
    SSP2CON1bits.SSPEN = 1; //Enable MSSP
    PIR3bits.SSP2IF = 0;
}

void SetColor(RGB color) {
    char b;
    for (char led = 0; led < LEDS; ++led) {
        unsigned char value = color.G;
        b = 8;
        while (b > 0) {
            PIR3bits.SSP2IF = 0;
            if (value & 0b10000000) {
                SSP2BUF = 0b11111000;
            } else {
                SSP2BUF = 0b11000000;
            }
            --b;
            value <<= 1;
            while (!PIR3bits.SSP2IF);
        }
        value = color.R;
        b = 8;
        while (b > 0) {
            PIR3bits.SSP2IF = 0;
            if (value & 0b10000000) {
                SSP2BUF = 0b11111000;
            } else {
                SSP2BUF = 0b11000000;
            }
            --b;
            value <<= 1;
            while (!PIR3bits.SSP2IF);
        }
        value = color.B;
        b = 8;
        while (b > 0) {
            PIR3bits.SSP2IF = 0;
            if (value & 0b10000000) {
                SSP2BUF = 0b11111000;
            } else {
                SSP2BUF = 0b11000000;
            }
            --b;
            value <<= 1;
            while (!PIR3bits.SSP2IF);
        }
    }
    __delay_us(50);
}

void SetColors(RGB *colors) {
    char b;
    for (char led = 0; led < LEDS; ++led) {
        unsigned char value = colors[led].G;
        b = 8;
        while (b > 0) {
            PIR3bits.SSP2IF = 0;
            if (value & 0b10000000) {
                SSP2BUF = 0b11111000;
            } else {
                SSP2BUF = 0b11000000;
            }
            --b;
            value <<= 1;
            while (!PIR3bits.SSP2IF);
        }
        value = colors[led].R;
        b = 8;
        while (b > 0) {
            PIR3bits.SSP2IF = 0;
            if (value & 0b10000000) {
                SSP2BUF = 0b11111000;
            } else {
                SSP2BUF = 0b11000000;
            }
            --b;
            value <<= 1;
            while (!PIR3bits.SSP2IF);
        }
        value = colors[led].B;
        b = 8;
        while (b > 0) {
            PIR3bits.SSP2IF = 0;
            if (value & 0b10000000) {
                SSP2BUF = 0b11111000;
            } else {
                SSP2BUF = 0b11000000;
            }
            --b;
            value <<= 1;
            while (!PIR3bits.SSP2IF);
        }
    }
    __delay_us(50);
}