#include <avr/io.h> //or <xc.h> if using xc8 compiler
#define F_CPU 3333333
#include <util/delay.h>
#include "notes.h"

 



void init(){
    //PA3 = WO0 = output
    PORTA.DIRSET = PIN3_bm;
//    PORTA.DIRSET = PIN6_bm;
//    PORTA.OUTSET = PIN6_bm;
//    PORTA.OUTCLR = PIN6_bm;
    //TCA0 (SINGLE means using a single 16bit counter, 3 outputs available)

     //set period, default reset value is 0xFFFF, so no need to set in this case
    //TCA0.SINGLE.PER = 0xFFFF;
    //enable CMP0 output (PA3,WO0), use mode SINGLESLOPE PWM
    TCA0.SINGLE.CTRLB = TCA_SINGLE_CMP0EN_bm | TCA_SINGLE_WGMODE_FRQ_gc;
    
    //initialize servo to mid position (if wanted)
    //TCA0.SINGLE.CMP0 = DUTY_MIN;
    //enable TCA0, using clock default DIV1
    TCA0.SINGLE.CTRLA = TCA_SINGLE_ENABLE_bm;
}

int delay_ms(uint16_t milliseconds)
{
   while(milliseconds > 0)
   {
      milliseconds--;
      _delay_ms(1);
   }
}

void tone(uint16_t Hz, uint16_t timeOn, uint16_t timeOff){
    TCA0.SINGLE.CTRLB = TCA_SINGLE_CMP0EN_bm | TCA_SINGLE_WGMODE_FRQ_gc;
    TCA0.SINGLE.CMP0 = Hz;
    delay_ms(timeOn);
    TCA0.SINGLE.CTRLB &= ~TCA_SINGLE_CMP0EN_bm;
    delay_ms(timeOff);
}

int main(){

    init();
    
    _delay_ms(80);
    tone(G5, 100, 80);
    tone(Fs5, 100, 80);
    tone(E5, 100, 80);
    tone(E5, 100, 80);
    tone(Fs5, 100, 80);
    

    
}