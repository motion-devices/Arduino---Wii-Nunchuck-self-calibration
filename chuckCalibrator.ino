/*
 * WiiChuckCalibration for Joystick
 * 2014 https://github.com/motion-devices/
 */

#include <Wire.h>
#include "nunchuck_funcs.h"
int loop_cnt=0;
int Xmin=70,Ymin=70,Xmax=215,Ymax =215,x0=128,y0=128;
int sensitivity = 10;




void setup()
{
    Serial.begin(19200);
    nunchuck_setpowerpins();
    nunchuck_init();
}

void loop()
{
    if( loop_cnt > 100 ) { // every 100 msecs get new data
        loop_cnt = 0;
        nunchuck_get_data();
        
int xRAW = nunchuck_joyx();   // Sensorwerte
int yRAW = nunchuck_joyy();
if(nunchuck_zbutton()==1){Xmax=200;Ymax=200;y0=yRAW;x0=xRAW;} // Calibration of Zero-Positions
int x = xRAW+128-x0;          // Sensorvalues shiftet to archive 128 is the zero Position
int y = yRAW+128-y0;
Xmin = min(Xmin,x);          // needed for outputscale parameters
Ymin = min(Ymin,y);
Xmax = max(Xmax,x);
Ymax = max(Ymax,y);

double xMul = (255.0/(Xmax-Xmin));        //scale parameters
double yMul = (255.0/(Ymax-Ymin));       
int     x_output= ((x-Xmin)*xMul);
int     y_output= ((y-Ymin)*yMul);
if(x_output<(128+sensitivity)&&(x_output>(128-sensitivity))){x_output=128;}
if(y_output<(128+sensitivity)&&(y_output>(128-sensitivity))){y_output=128;}
        Serial.print("  X: "); Serial.print(x_output);
        Serial.print("  Y: "); Serial.print(y_output);
        Serial.print("  Xsensor:"); Serial.print(x);
        Serial.print("  Ysensor:"); Serial.print(y);
        Serial.print("  Xmin: "); Serial.print(Xmin);
        Serial.print("  Xmax: "); Serial.print(Xmax);
        Serial.print("  Ymin: "); Serial.print(Ymin);
        Serial.print("  Ymax: "); Serial.print(Ymax);
        Serial.print("  y0: "); Serial.print(y0);
        Serial.print("  x0: "); Serial.print(x0);
        Serial.print("  xMul: "); Serial.print(xMul);
        
        Serial.println();
        
        analogWrite(3, x_output); 
        analogWrite(5, y_output); 
        
    }
    loop_cnt++;
    delay(1);

}
