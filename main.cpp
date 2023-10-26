/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include <cstdio>


// Blinking rate in milliseconds
#define BLINKING_RATE     500ms
// Initialise the digital pin LED1 as an output
#ifdef LED1
    DigitalOut led(PC_0);
    DigitalOut led2(LED1);
    DigitalIn EncoderA(PA_1);
#else
    bool led = 0;
#endif

int main()
{
    int EncoderAValue = 0;
    while (true)
    {
        EncoderAValue = EncoderA.read();
        printf("The Encoder Value is %d \n",EncoderAValue);
        wait_us(100000);
        if (EncoderAValue == 1)
        {
            led = 1;
            led2 = 0;
        }
        else
        {
            led = 0;
            led2 = 1;
        }
    }
}
