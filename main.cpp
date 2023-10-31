#include "mbed.h"
#include <cstdio>

I2C i2c(PB_9, PB_8);
BufferedSerial mypc(USBTX, USBRX); 

const int addr = 0x9A; // define the I2C Address for TC74-A5

int main()
{
    int temp = 0;
    char data[2];
    wait_us(10000); //Make sure system is fully initialized

    FILE* mypcFile1 = fdopen(&mypc, "r+");

    //\033[2J: This is another ANSI escape sequence that clears the screen. 
    //It clears the entire screen and positions the cursor at the top-left corner.
    fprintf(mypcFile1,"\033[2J I2C Searching!\n\n\n"); 

    // int count = 0;
    // for (int address=0; address<256; address+=2) 
    // {
    //     if (!i2c.write(address, NULL, 0)) 
    //     { // 0 returned is ok
    //         fprintf(mypcFile1,"I2C address 0x%02X\n", address);
    //         count++;
    //     }
    // }
    // fprintf(mypcFile1,"\n\n%d devices found\n", count); 
    // wait_us(50000); 

    while(1)
    {
        i2c.read(addr, data, 1); 
        wait_us(100000); 
        fprintf(mypcFile1,"Device with address 0x%x with\r\n", addr); 
        fprintf(mypcFile1,"Method 1 :: %d\n\r", data[0]);
        wait_us(100000);
    }
} 



