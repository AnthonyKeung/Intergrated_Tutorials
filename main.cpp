#include "mbed.h"
#include <cstdio>

int main()
{
    BufferedSerial mypc(USBTX, USBRX); 
    FILE* mypcFile1 = fdopen(&mypc, "r+");

    for (int sec = 0; sec <10; sec++)
    {
        fprintf(mypcFile1, "The number of seconds passed is %d\n" ,sec);
        wait_us(1000000);
    }
    return 0;
}
