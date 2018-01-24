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


#define backpwm  5
#define frontpwm  6
#define backenable 7
#define frontenable 4
#define brk_c 3
#define brk_d 2

//break

long delay_Micros = 1800; // Set value
long currentMicros = 0; long previousMicros = 0;
int counter = 0;


int userInput[3];
int startbyte;
int fb, brk_key, brk_release_key, center, rl, i;

int isbreak = 0;
int isbreak_release = 0;




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
  pinMode(brk_c, OUTPUT);
  pinMode(brk_d, OUTPUT);


}

void loop()
{

  // Wait for serial input (min 3 bytes in buffer)
  if (Serial.available() > 5) {
    // Read the first byte
    startbyte = Serial.read();
    // If it's really the startbyte (100) ...
    if (startbyte == 100) {
      // ... then get the next  bytes
      for (i = 0; i < 5; i++) {
        userInput[i] = Serial.read();
      }
      // First byte = font back to move
      fb = userInput[0];
      // Second byte = which right left
      rl = userInput[1];

      brk_key =  userInput[2];
      brk_release_key =  userInput[3];
      center =  userInput[4];

      if ( brk_key == 1)
      {
      //  if(isbreak_release == 0)

      //  {
        //   isbreak = 1;
           brk();
        //   isbreak_release = 1;

        //  }


      }

      if ( brk_release_key == 1)
      {
       // if (isbreak == 1)
      //  {
          break_release();
        //  isbreak ==0;
       //   isbreak_release =0;

        //  }



      }



      if (fb == 50)
      {

        back_nutral() ;

      }
      else if (fb < 50)
      {
        forward();
      }
      else if (fb > 50)
      {

        backward() ;

      }


      //front

      if (rl == 50)
      {
        front_nutral();


      }
      else if (rl < 50)
      {

        left() ;


      }
      else if (rl > 50)
      {

        right() ;

      }



    }
  }
}






void forward()
{


  analogWrite(backpwm, 130 - fb);
  digitalWrite(backenable, HIGH);

}

void back_nutral()
{
  analogWrite(backpwm, 0);

}


void backward()
{

  digitalWrite(backenable, LOW);
  analogWrite(backpwm, 40 + fb);


}
void front_nutral()
{
  analogWrite(frontpwm, 0);

}

void right() {

  digitalWrite(frontenable, HIGH);
  analogWrite(frontpwm, 130);


}
void left()
{

  digitalWrite(frontenable, LOW);
  analogWrite(frontpwm, 130);


}


void brk() {
  digitalWrite(brk_c, HIGH);
  digitalWrite(brk_d, LOW);
  delay(500);
  digitalWrite(brk_c, LOW);
  digitalWrite(brk_d, LOW);


}

void break_release() {

  digitalWrite(brk_c, LOW);
  digitalWrite(brk_d, HIGH);
  delay(500);
  digitalWrite(brk_c, LOW);
  digitalWrite(brk_d, LOW);


}