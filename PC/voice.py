
#    Copyright (C) 2018 Soikat Hasan Ahmed
#
#    Project Name:
#    Author: Soikat Hasan Ahmed
#    Author's Email: soikathasan15@gmail.com
#
#    Redistribution and use in source and binary forms, with or without modification,
#    are permitted provided that the following conditions are met:
#
#    1. Redistributions of source code must retain the above copyright notice, this
#       list of conditions and the following disclaimer.
#
#    2. Redistributions in binary form must reproduce the above copyright notice, this
#       list of conditions and the following disclaimer in the documentation and/or
#       other materials provided with the distribution.
#
#    3. Neither the name of the copyright holder nor the names of the contributors may
#       be used to endorse or promote products derived from this software without
#       specific prior written permission.
#
#    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
#    ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
#    WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
#    IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
#    INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING
#    BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
#   DATA, OR PROFITS; OR BUSINESS INTERRUPTIONS) HOWEVER CAUSED AND ON ANY THEORY OF
#    LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
#    OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
#    OF THE POSSIBILITY OF SUCH DAMAGE.

import pygame

import pyttsx3
engine = pyttsx3.init()

#talk
talkfront_back = False
talkright_left = False




#    Copyright (C) 2018 Soikat Hasan Ahmed
#
#    Project Name:
#    Author: Soikat Hasan Ahmed
#    Author's Email: soikathasan15@gmail.com
#
#    Redistribution and use in source and binary forms, with or without modification,
#    are permitted provided that the following conditions are met:
#
#    1. Redistributions of source code must retain the above copyright notice, this
#       list of conditions and the following disclaimer.
#
#    2. Redistributions in binary form must reproduce the above copyright notice, this
#       list of conditions and the following disclaimer in the documentation and/or
#       other materials provided with the distribution.
#
#    3. Neither the name of the copyright holder nor the names of the contributors may
#       be used to endorse or promote products derived from this software without
#       specific prior written permission.
#
#    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
#    ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
#    WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
#    IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
#    INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING
#    BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
#   DATA, OR PROFITS; OR BUSINESS INTERRUPTIONS) HOWEVER CAUSED AND ON ANY THEORY OF
#    LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
#    OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
#    OF THE POSSIBILITY OF SUCH DAMAGE.


#init gamepad

def voice():
        pygame.display.init()
        pygame.joystick.init()
        pygame.joystick.Joystick(0).init()
        print('init gamepad')




        while True:

                pygame.event.pump()
                bx = int((pygame.joystick.Joystick(0).get_axis(2))*50+50)
                ay = int((pygame.joystick.Joystick(0).get_axis(1))*50+50)
                brk = int(pygame.joystick.Joystick(0).get_button(5))

                if ay == 50:
                        talkfront_back = True
                elif ay<50 and talkfront_back == True :
                        talkfront_back = False
                        engine.say('Going forward')
                        engine.runAndWait()
                elif ay > 50 and talkfront_back == True :
                        talkfront_back = False
                        engine.say('Going backward')
                        engine.runAndWait()
                if bx == 50  :
                        talkright_left = True
                elif bx < 50 and talkright_left == True  :
                        talkright_left = False
                        engine.say('turning left')

                        engine.runAndWait()
                elif bx > 50 and talkright_left == True :
                        talkright_left = False
                        engine.say('turning right')
                        engine.runAndWait()

                if brk == 1:

                        engine.say('breaking')
                        engine.runAndWait()

