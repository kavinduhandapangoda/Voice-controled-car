/*
 
 Voice Controlled Robot
created by kavindu handapangoda
2019:03:04
used app : Arduino bluetooth control

*/

// 1 -- car run forward 
// 2 -- car run forward 
// 3 -- car turn right 
// 4 -- car turn left
// 5 -- car stopping


#include <AFMotor.h>
AF_DCMotor motor1 (1, MOTOR12_1KHZ);
AF_DCMotor motor2 (2, MOTOR12_1KHZ);

// car motor speeds
int sp = 100;
int sp2 = 80;


void setup()
{
   Serial.begin(9600);
  Serial.println("listning");
   
}

void loop()
{
   while (Serial.available()){
    delay(10);
    char c = Serial.read();  // get code from BT
      Serial.print(c);      // print code for help to devolop

      
   // checking the code 
   if(c == '1'){
    Serial.println(" car running forward");
    forward();
  }

  if(c == '2'){
    Serial.println(" car running backward");
    backward();
  }

  if(c == '3'){
    Serial.println(" car turning right");
    Tright();
    delay(500);
    pause();
  }

  if(c == '4'){
    Serial.println(" car turning left");
    Tleft();
    delay(500);
    pause();
  }

  if(c == '5'){
    Serial.println("stop");
    pause();
  }

  if(c == '6'){
    Serial.println(" car rotating");
    Tright();
  }
  
 }
 }

// --------------------------------- car moving functions ---------------------------------

void backward(){
motor1.setSpeed(sp);
motor2.setSpeed(sp);

 motor1.run(FORWARD);
 motor2.run(FORWARD);
   }

  void forward(){
motor1.setSpeed(sp);
motor2.setSpeed(sp);

 motor1.run(BACKWARD);
 motor2.run(BACKWARD);
   }

void Tleft(){
  motor1.setSpeed(sp);
  motor2.setSpeed(sp2);
  
  motor1.run(FORWARD);
  motor2.run(BACKWARD);
   }  

  void Tright(){
  motor1.setSpeed(sp2);
  motor2.setSpeed(sp);
  
  motor1.run(BACKWARD);
  motor2.run(FORWARD);
     }

  void pause(){
  motor1.setSpeed(00);
  motor2.setSpeed(00);
    }


  
