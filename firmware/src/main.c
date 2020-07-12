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
#include <inttypes.h>
#include "definitions.h"                // SYS function prototypes



static volatile uint16_t seconds = 0;
static volatile uint16_t counter2 = 0;

//TMR2 for PWM, called each 1ms
void TIMER2_EventHandler(uint32_t status, uintptr_t context)
{
    counter2++;
    // each second change brightness of LED
    if (counter2 == 1000){
        seconds ++;
        OC1RS = 8000;
    }
    if (counter2 == 2000){
        seconds ++;
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
    int old_seconds = 0;
    char c = ' ';
    /* Initialize all modules */
    SYS_Initialize ( NULL );
    
    OCMP1_Enable();
    
    TMR2_CallbackRegister(TIMER2_EventHandler,(uintptr_t)NULL);     
    TMR2_Start();

    printf("Starting... Build time: %s\r\n", __TIMESTAMP__);
    
    while ( true )
    {
        if (old_seconds != seconds){
            old_seconds = seconds;
            printf("OC1RS=%" PRIu16  " c=%c\r\n",OC1RS,c);
            c++;
            if (c>=127){
                c=' ';
            }
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

