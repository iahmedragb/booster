 /**
 Author      : Ahmed Ragab
 Assignment  : Task 5
 ========================================================
 *Code Skeleton for a car
 *Speed and Direction are controlled by 4 buttons
 *Use 2 motors to apply movements

 ============================================================================
*/

/***
1st layer                   APP Layer
2nd layer        [buttons 1/2/3/4][     motors   ]
3rd layer        [      DIO      ][ PWM ][ Timer ]
4th layer               MICROCONTROLLER
*/

#include "App.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main()
{
    ///initialization the application
    APP_init();
    while(1)
    {
                ///Get system STATE based on SM
                ///Decide the proper output
                ///Set system OUTPUT STATE based on SM
                APP_update();

    }
    return 0;
}
