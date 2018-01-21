//    Copyright (C) 2018 Soikat Hasan Ahmed
//
//    Project Name:
//    Author: Soikat Hasan Ahmed
//    Author's Email: soikathasan15@gmail.com
//
//    Redistribution and use in source and binary forms, with or without modification,
//    are permitted provided that the following conditions are met:
//
//    1. Redistributions of source code must retain the above copyright notice, this
//       list of conditions and the following disclaimer.
//
//    2. Redistributions in binary form must reproduce the above copyright notice, this
//       list of conditions and the following disclaimer in the documentation and/or
//       other materials provided with the distribution.
//
//    3. Neither the name of the copyright holder nor the names of the contributors may
//       be used to endorse or promote products derived from this software without
//       specific prior written permission.
//
//    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
//    ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
//    WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
//    IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
//    INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING
//    BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
//    DATA, OR PROFITS; OR BUSINESS INTERRUPTIONS) HOWEVER CAUSED AND ON ANY THEORY OF
//    LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
//    OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
//    OF THE POSSIBILITY OF SUCH DAMAGE.


#define backpwm  9
#define frontpwm  10
#define backenable 7
#define frontenable 6



int userInput[3];
int startbyte;
int fb;
int rl;
int i;

void setup() {
  // start serial port at 9600 bps and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }


  pinMode(backpwm, OUTPUT);
  pinMode(frontpwm, OUTPUT);
  pinMode(backenable, OUTPUT);
  pinMode(frontenable, OUTPUT);


}

void loop()
{

  // Wait for serial input (min 3 bytes in buffer)
  if (Serial.available() > 2) {
    // Read the first byte
    startbyte = Serial.read();
    // If it's really the startbyte (100) ...
    if (startbyte == 100) {
      // ... then get the next two bytes
      for (i = 0; i < 2; i++) {
        userInput[i] = Serial.read();
      }
      // First byte = font back to move?
      fb = userInput[0];
      // Second byte = which right left?
      rl = userInput[1];
      // Packet error checking and recovery




      if (fb == 50) {
        analogWrite(backpwm,0);



      }
      else if (fb < 50) {
         analogWrite(backpwm,130-fb);
         digitalWrite(backenable,HIGH);

      }
      else if (fb>50) {
         digitalWrite(backenable,LOW);
         analogWrite(backpwm,40+fb);


      }


    //front

      if (rl == 50) {
        analogWrite(frontpwm,0);


      }
      else if (rl < 50) {
        digitalWrite(frontenable,HIGH);
        delay(5);
         analogWrite(frontpwm,130);



      }
      else if (rl>50) {
         digitalWrite(frontenable,LOW);
         delay(5);
         analogWrite(frontpwm,130);


      }



    }
  }
}