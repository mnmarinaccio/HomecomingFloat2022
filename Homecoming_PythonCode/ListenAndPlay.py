#!/usr/bin/env python3
import serial
import time
from pygame import mixer

mixer.init()
GIGAWATTS=mixer.Sound('GIGAWATTS_FINAL.wav')
ROADS=mixer.Sound('ROADS_FINAL.wav')
soundPlaying = 1
gigaWattsStop = 0
roadsStop = 0

if __name__ == '__main__':
    ser=serial.Serial('/dev/ttyACM0', 9600, timeout=1)
    ser.reset_input_buffer()
    
    while True:
        if ser.in_waiting>0:
            line=ser.readline().decode('utf-8').strip()
            print(line)
            if line == "GIGAWATTS":
                gigaWattsStop = 1
                while (soundPlaying == 1):
                    print(line)
                    print('Playing GIGAWATTS Sound\n')
                    GIGAWATTS.play()
                    soundPlaying = 0
            if line == "ROADS":
                roadsStop = 1
                while (soundPlaying == 1):
                    print(line)
                    print('Playing ROADS Sound\n')
                    ROADS.play()
                    soundPlaying = 0
            if line == "STOP" and gigaWattsStop == 1:
                gigaWattsStop = 0
                GIGAWATTS.stop()
            if line == "STOP" and roadsStop == 1:
                roadsStop = 0
                ROADS.stop()
            soundPlaying=1
            ser.flushInput()
            
