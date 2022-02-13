#include "App.h"

void APP_init(void){

    BUTTONS_init();
    MOTOR_init();
}
void APP_update(void){
    //update buttons state
    BUTTONS_update();
    //get state of the buttons
    BUTTONS_get_state();
    //Set state of motor direction and speed
    MOTOR_set_direction_speed();
    //Update motor direction and speed
    MOTOR_update();
}




