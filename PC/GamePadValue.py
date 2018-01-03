import pygame
import serial
import time


#init serial
arduino =serial.Serial("/dev/ttyACM0",9600,timeout=5)


def move(fb, rl):

        arduino.write(chr(100).encode())
        arduino.write(chr(fb).encode())
        arduino.write(chr(rl).encode())



time.sleep(1)
print('init serial')

#init gamepad
pygame.display.init()
pygame.joystick.init()
pygame.joystick.Joystick(0).init()
print('init gamepad')


while True:

        pygame.event.pump()
        bx = int((pygame.joystick.Joystick(0).get_axis(3))*50+50)
        ay = int((pygame.joystick.Joystick(0).get_axis(1))*50+50)
        print(str(ay)+'  '+str(bx))
        move(ay,bx)
        time.sleep(.1)



