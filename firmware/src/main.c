/*******************************************************************************
  Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This file contains the "main" function for a project.

  Description:
    This file contains the "main" function for a project.  The
    "main" function calls the "SYS_Initialize" function to initialize the state
    machines of all modules in the system
 *******************************************************************************/

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <string.h>                     // strlen(3)
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include "definitions.h"                // SYS function prototypes



static const char *MSG_INIT="Init...\r\n";

static volatile uint16_t counter2 = 0;

//TMR2 for PWM, called each 1ms
void TIMER2_EventHandler(uint32_t status, uintptr_t context)
{
    counter2++;
    // each second change brightness of LED
    if (counter2 == 1000){
        OC1RS = 8000;
    }
    if (counter2 == 2000){
        OC1RS = 2000;
        counter2 = 0;
    }
} 

// *****************************************************************************
// *****************************************************************************
// Section: Main Entry Point
// *****************************************************************************
// *****************************************************************************

int main ( void )
{
    char c = ' ';
    int c_send = 0;
    /* Initialize all modules */
    SYS_Initialize ( NULL );
    
    OCMP1_Enable();
    
    TMR2_CallbackRegister(TIMER2_EventHandler,(uintptr_t)NULL);     
    TMR2_Start();

    puts(MSG_INIT);
    
    while ( true )
    {
        if (counter2 == 1000 && !c_send){
            putchar(c);
            c++;
            if (c>=127){
                c=' ';
            }
            c_send = 1;
        }
        if (counter2 != 1000){
            c_send = 0;
        }
        /* Maintain state machines of all polled MPLAB Harmony modules. */
        SYS_Tasks ( );
    }

    /* Execution should not come here during normal operation */

    return ( EXIT_FAILURE );
}


/*******************************************************************************
 End of File
*/

