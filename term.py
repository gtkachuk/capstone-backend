#! /usr/bin/python
import serial, sys

try:
    s = serial.Serial("/dev/ttyACM0", 57600, timeout=1)
    while 1:
        sys.stdout.write(s.readline())
#        ser.write(raw_input())
except KeyboardInterrupt:
    s.close()

