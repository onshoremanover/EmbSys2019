#include <stdio.h>
#include <pigpio.h>
#include <stdlib.h>


#define KC1  16
#define KC2  13
#define KC3  6

#define KR1  21
#define KR2  26
#define KR3  20
#define KR4  19

//DISPLAY CLOUMNE high
#define DC1  22
#define DC2  27
#define DC3  18
#define DC4  17
#define DC5  15

//DISPLAY REIHE low
#define DR1  8
#define DR2  11
#define DR3  25
#define DR4  9
#define DR5  10
#define DR6  24
#define DR7  23

#define LOW   0
#define HIGH  1


//----------------------------------------------------------
int main ()
{
    //Initialise
    
    if (gpioInitialise() < 0){
        fprintf(stderr, "pigpio initialisation failed\n");
        exit (EXIT_FAILURE);
    }
        
   //Set
        gpioSetMode (DC1, PI_OUTPUT);
        gpioSetMode (DC2, PI_OUTPUT);
        gpioSetMode (DC3, PI_OUTPUT);
        gpioSetMode (DC4, PI_OUTPUT);
        gpioSetMode (DC5, PI_OUTPUT);
        
        gpioSetMode (DR1, PI_OUTPUT);
        gpioSetMode (DR2, PI_OUTPUT);
        gpioSetMode (DR3, PI_OUTPUT);
        gpioSetMode (DR4, PI_OUTPUT);
        gpioSetMode (DR5, PI_OUTPUT);
        gpioSetMode (DR6, PI_OUTPUT);
    
    //WRITE
        gpioWrite (DC1, HIGH);
        gpioWrite (DC2, HIGH);
        gpioWrite (DC3, HIGH);
        gpioWrite (DC4, HIGH);
        gpioWrite (DC5, HIGH);
    
        gpioWrite (DR1, LOW);
        gpioWrite (DR2, LOW);
        gpioWrite (DR3, LOW);
        gpioWrite (DR4, LOW);
        gpioWrite (DR5, LOW);
        gpioWrite (DR6, LOW);
        
        
        
        time_sleep(20);
        
        
        
        
        
    
    //
    //Terminate
    gpioTerminate();
    
    //done
    printf ("[INFO] done.\n");
    exit (EXIT_SUCCESS);
}
//--------------------------------------------------------

