/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"


// Blinking rate in milliseconds
#define BLINKING_RATE     500ms
// Initialise the digital pin LED1 as an output
#ifdef LED1
    DigitalOut led(PC_0);
    DigitalIn mySwitch(BUTTON1);
#else
    bool led = 0;
#endif

int main()
{
    mySwitch.mode(PullUp);
    while (true) 
    {
        if (mySwitch == 0)
        {
            led = 1;
        }
        else
        {
            led = 0;
        }
    }
    return 0;
}
