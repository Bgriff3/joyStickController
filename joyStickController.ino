  #include<Servo.h>
  //name the servo
  Servo serv1;

  //define the joystick and attach it to pin A6
  #define joyVal A6

  // create a global variable int angle; to be used anywhere
  int angle;

  // create another global variable int joyPos; for joystick position
  int joyPos;

void setup() {
  // attach the servo to pin 3 
   serv1.attach(3);
}

void loop() {

   
   // analogRead(); converts input with changing voltage 0-5v into to 10 bits so information can be stored in numbers from 0-1023 
   // set joyPos= anlogRead(joyVal); to read the data connected the joystick connected to pin A6
    joyPos= analogRead(joyVal);

  // angle is the positon of the servo relative to the joystick
  //map tracks the joystick and converts it to motion for servo motor. Map needs 5 arguments map(valuetracked, oldLow, oldHigh, newLow, newHigh);
  angle = map(joyPos,0,1023,0,180);

  //the servo will move to the mapped position 
  serv1.write(angle);

}
