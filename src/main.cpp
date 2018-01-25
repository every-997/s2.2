#include <mbed.h>

DigitalOut blue(LED_BLUE);
DigitalOut red(LED_RED);
DigitalOut green(LED_GREEN);

Ticker  pit;

void flash(void) {
   static unsigned int phase=0;

   if(phase==0) blue.write(0); /* on */
   if(phase==1) blue.write(1); /* off */
   if(phase==2) red.write(0); /* on */
   if(phase==3) red.write(1); /* off */
   if(phase==4) green.write(0); /*on */
   if(phase==5) green.write(1); /* off */

   phase++;
   if(phase==6) phase=0;
}

int main(void) {
  pit.attach(flash,0.2);
  while(1);
}
