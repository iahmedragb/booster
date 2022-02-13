#include "buttons.h"
void BUTTONS_init(void){
    DIO_init();

}
void BUTTONS_update(void){
    //update buttons state
    DIO_read();
    //set buttons state
}
void BUTTONS_get_state(void){
    ///static global value
}
