
#define backpwm  9

#define frontpwm  10

#define backenable 7

#define frontenable 6



int userInput[3];    // raw input from serial buffer, 3 bytes
int startbyte;       // start byte, begin reading input
int fb;           // which servo to pulse?
int rl;             // servo angle 0-180
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
         analogWrite(frontpwm,160);



      }
      else if (rl>50) {
         digitalWrite(frontenable,LOW);
         delay(5);
         analogWrite(frontpwm,170);


      }



    }
  }
}