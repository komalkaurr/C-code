/*
===============================================================================
 Name        : main.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#if defined (__USE_LPCOPEN)
#if defined(NO_BOARD_LIB)
#include "chip.h"
#else
#include "board.h"
#endif
#endif

#include <cr_section_macros.h>

// TODO: insert other include files here

// TODO: insert other definitions and declarations here

typedef struct LED_struct
{
	unsigned long int duration;
	bool red;
	bool blue;
	bool green;
};
typedef struct LED_struct LED_t;

void delay(unsigned long int del)
{
	unsigned long int i=0;
	while((i++)<del);
	return;
}

int main(void) {

#if defined (__USE_LPCOPEN)
    // Read clock settings and update SystemCoreClock variable
    SystemCoreClockUpdate();
#if !defined(NO_BOARD_LIB)
    // Set up and initialize all required blocks and
    // functions related to the board hardware
    Board_Init();
    // Set the LED to the state of "off"
    Board_LED_Set(0, false);
    Board_LED_Set(1, false);
    Board_LED_Set(2, false);
#endif
#endif

    // TODO: insert code here
    vector<LED_t>sequenceLED;
    unsigned long int loadarr_time[]={1400000,56546000,42786480,90565400,676659000,134565000};
    bool loadarr_red[]={false,true,false,true,false,true};
    bool loadarr_blue[]={true,false,true,false,true,false};
    bool loadarr_green[]={false,true,false,true,false,true};
    for(signed short int i=0;i<9;i++)
    {
    led_t temp;
    temp.duration=loadarr_time[i];
    temp.red=loadarr_red[i];
    temp.blue=loadarr_blue[i];
    temp.green=loadarr_green[i];
    sequenceLED.push_back(temp);
    }
    // Enter an infinite loop, just incrementing a counter
    while(1) {
    for(vector<LED_t>:: iterator iter = sequenceLED.begin();iter!=sequenceLED.end();iter++){
    Board_LED_Set(0, iter->red);
    Board_LED_Set(1, iter->blue);
    Board_LED_Set(2, iter->green);
    delay(iter->duration);
    }
    }

    // Force the counter to be placed into memory
    volatile static int i = 0 ;
    // Enter an infinite loop, just incrementing a counter
    while(1) {
        i++ ;
    }
    return 0 ;
}

led_sequence.cpp
Displaying led_sequence.cpp.

