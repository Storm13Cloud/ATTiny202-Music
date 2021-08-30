#include <avr/io.h> //or <xc.h> if using xc8 compiler
#define F_CPU 3333333
#include <util/delay.h>
#include "notes_1.h"

 



void init(){
    PORTA.DIRSET = PIN3_bm;
    TCA0.SINGLE.CTRLB = TCA_SINGLE_CMP0EN_bm | TCA_SINGLE_WGMODE_FRQ_gc;
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
    tone(G5, 100, 100);
    tone(Fs5, 100, 100);
    tone(E5, 100, 100);
    tone(E5, 100, 100);
    tone(Fs5, 150, 750);
    
    tone(A4, 100, 100);
    tone(G5, 100, 100);
    tone(Fs5, 100, 100);
    tone(E5, 100, 100);
    tone(E5, 100, 300);
    tone(Fs5, 100, 500);
    tone(D5, 100, 300);
    tone(E5, 100, 100);
    tone(A4, 150, 750);
    
    tone(A4, 100, 100);
    tone(E5, 100, 300);
    tone(Fs5, 100, 100);
    tone(G5, 100, 500);
    tone(E5, 100, 100);
    tone(Cs5, 100, 300);
    tone(D5, 100, 500);
    tone(E5, 100, 300);
    tone(A4, 100, 100);
    tone(A4, 100, 100);
    tone(Fs5, 150, 750);
    
    tone(G5, 100, 100);
    tone(Fs5, 100, 100);
    tone(E5, 100, 100);
    tone(E5, 100, 100);
    tone(Fs5, 150, 750);
    
    tone(A4, 100, 100);
    tone(G5, 100, 100);
    tone(Fs5, 100, 100);
    tone(E5, 100, 100);
    tone(E5, 100, 500);
    tone(Fs5, 100, 100);
    tone(D5, 100, 500);
    tone(E5, 100, 100);
    tone(A4, 150, 750);
    
    tone(E5, 250, 100);
    tone(Fs5, 100, 100);
    tone(G5, 200, 250);
    tone(E5, 100, 100);
    tone(Cs5, 200, 250);
    tone(D5, 100, 100);
    tone(E5, 200, 250);
    
    tone(A4, 100, 100);
    tone(D5, 100, 100);
    tone(E5, 100, 100);
    tone(F5, 100, 100);
    tone(E5, 100, 100);
    tone(D5, 100, 100);
    tone(C5, 100, 300);
    // start here
    tone(A4, 100, 100);
    tone(As4, 100, 100);
    tone(C5, 100, 250);//F4
    tone(F5, 100, 250);//A4 C5
    tone(E5, 100, 100);//C5 G4
    tone(D5, 100, 100);
    tone(D5, 100, 100);//G4
    tone(C5, 100, 100);
    tone(D5, 100, 100);//As4 F4
    tone(C5, 100, 100);
    tone(C5, 100, 250);//As4 F4
    tone(C5, 150, 500);//A4 F4
    
    tone(A4, 100, 100);
    tone(As4, 100, 100);
    tone(C5, 100, 250);//A4 F4
    tone(F5, 100, 250);//F5 A4
    tone(E5, 100, 100);//C5 G5
    tone(F5, 100, 100);
    tone(E5, 100, 100);//C5
    tone(D5, 100, 100);
    tone(D5, 100, 100);//As4 F4
    tone(E5, 100, 100);
    tone(F5, 100, 250);//As4
    tone(F5, 100, 250);//C5 A4
    
    tone(G5, 100, 100);
    tone(A5, 100, 100);
    tone(As5, 100, 100);//F5 D5
    tone(As5, 100, 100);
    tone(F5, 100, 250);//A5 F5 D5-
    tone(E5, 100, 250);//G5 E5-
    
    tone(F5, 100, 100);
    tone(G5, 100, 100);
    tone(A5, 100, 100);//F5 C5
    tone(A5, 100, 100);
    tone(E5, 100, 250);//G5 E5 C5-
    tone(D5, 100, 250);//F5 A4 D5-
    
    tone(D5, 100, 100);  
    tone(C5, 100, 100);
    tone(D5, 100, 100);//As4 F4
    tone(F5, 100, 100);
    tone(F5, 100, 100);//D5 As4
    tone(E5, 100, 100);
    tone(A4, 100, 100);//A4 Cs5
    tone(E5, 100, 100);//E5 A4 Cs5
    tone(Fs5, 100, 100);
    tone(Fs5, 100, 100);
    
    

    
}