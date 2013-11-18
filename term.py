#! /usr/bin/python
"""
First, setup change terimanl line seting with following command:
    stty -F /dev/ttyACM0 cs8 57600 ignbrk -brkint -icrnl -imaxbel -opost -onlcr -isig -icanon -iexten -echo -echoe -echok -echoctl -echoke noflsh -ixon -crtscts
Assuming /dev/ttyACM0 is the arduino board and 57600 is the required baud rate.
Command above taken from: http://playground.arduino.cc/Interfacing/LinuxTTY
"""
import serial, sys

try:
    s = serial.Serial("/dev/ttyACM0", 57600, timeout=0)
    while 1:
        sys.stdout.write(s.readline())
        s.write(raw_input())
except KeyboardInterrupt:
    s.close()

