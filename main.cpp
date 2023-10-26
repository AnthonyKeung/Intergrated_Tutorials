/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"


// Blinking rate in milliseconds
#define BLINKING_RATE     500ms
// Initialise the digital pin LED1 as an output
#ifdef LED1
    DigitalOut led(LED1);
    DigitalIn mySwitch(BUTTON1);
#else
    bool led;
#endif

int main()
{
    mySwitch.mode(PullUp);
    led = 0 ;
    while (true) 
    {
        if (mySwitch == 1)
        {
            led = 1;
        }
        else if(mySwitch == 0)
        {
            led = 1;
        }
    }
    return 0;
}
