# p5js arduino send receive

Small project to test speed of serial communication between p5js and arduino, sending over rgb colors for a 10x10 led matrix.
For 1201 characters, it takes approx. 300ms to send and receive data back with a baudrate of 115200.

* Data is send as a long string like 100;100;100+100;100;101+100;100;102+|
* The + is used for marking a new led color 3-pair and | is used for marking end of data message
* 255;255;255+ is 12 characters, so for 100 leds that would make up for 1200 characters. 
* Include the ending character | and you'll need 1201 characters for the dataSize variable in `arduino.ino`.

# install
* install the https://github.com/p5-serial/p5.serialport app to be able to map the serial bus to a web socket so p5js can communicate.
