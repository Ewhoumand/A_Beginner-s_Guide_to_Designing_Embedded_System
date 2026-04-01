#include "mbed.h"
/* user boutton to command led1,led2 and led3 
   just need to update LED in the code
*/ 


int main()
{
    DigitalIn B1_USER(BUTTON1);

    DigitalOut LD3(LED3);

    while (true) {
        LD3 = B1_USER;
    }
}
