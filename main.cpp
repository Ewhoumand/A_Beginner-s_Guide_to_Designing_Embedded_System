#include "mbed.h"
// user boutton to command led 1

int main()
{
    DigitalIn B1_USER(BUTTON1);

    DigitalOut LD1(LED1);

    while (true) {
        LD1 = B1_USER;
    }
}
