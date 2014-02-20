Arduino Nunchuck Joystick self calibration Algorithm
=======================================

This Project is a simple self calibration algorithm for the use of a Wii Nunchuck Joystick as PWM Controller.
It uses the Nunchuck Library from Tod E. Kurt, http://todbot.com/blog/



In Standard configuration you need to wire your Cables from the Nunchuck in the following way:
Nunchuck  to  Arduino (Uno)
White     to  GND
Red       to  3.3V
Yellow    to  A5 (Analog 5)
Green     to  A4 (Analog 4)

Steps for calibration process:

1. Press Z Button on the Nunchuck to set zero positions from Stick.
2. Move the Joystick arround.

X-Axis is mapped to "Digital 3" as PWM from 0-255.
Y-Axis is mapped to "Digital 5" as PWM from 0-255.

You can look at the calibration process on the serial Monitor (press ctrl+shift+m in Arduino Software)
