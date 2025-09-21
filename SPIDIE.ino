

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>


int count = 0;
char ssid[] = "";
char pass[] = "";

// Blynk Auth Token
char auth[] = BLYNK_AUTH_TOKEN;

// PCA9685 setup
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(); // Default I2C address 0x40

// Servo min/max pulse (adjust if needed)
#define SERVO_MIN  102  // Minimum pulse length out of 4096 (0°)
#define SERVO_MAX  512  // Maximum pulse length out of 4096 (180°)

void setServoAngle(uint8_t channel, uint8_t angle)
{
  if (angle > 180) angle = 180;
  int pulse = map(angle, 0, 180, SERVO_MIN, SERVO_MAX);
  pwm.setPWM(channel, 0, pulse);
}

// 3 - left back hip
// 2 - left back ankle
// 0 - right back hip
// 1 - right back ankle
// 7 - right front hip
// 8- right front ankle
// 11- left front hip
// 9- left front ankle

void setup() {
  Serial.begin(115200);

  Blynk.begin(auth, ssid, pass);

  Wire.begin(); // Initialize I2C
  pwm.begin();  // Initialize PCA9685
  pwm.setPWMFreq(50);  // Analog servos run at ~50 Hz
  delay(10);
}

// Convert angle (0–180) to pulse (min–max)
int angleToPulse(int angle) {
  return map(angle, 0, 180, SERVO_MIN, SERVO_MAX);
}
void sleep(){
   //hips
   setServoAngle(3,0);
   setServoAngle(11,90);
   setServoAngle(7,0);
   setServoAngle(0,90);

   //ankle
   setServoAngle(1,90);
   setServoAngle(8,90);
   setServoAngle(9,90);
   setServoAngle(2,90);

//setServoAngle(,);
}
void getup(){
  //hips
  setServoAngle(11,45);
  delay(200);
  setServoAngle(7,45);
  delay(200);
  setServoAngle(3,45); 
  delay(200);
  setServoAngle(0,45);


  delay(200);

  //ankle
  setServoAngle(9,45);
   delay(200);
  setServoAngle(8,45);
   delay(200);
  setServoAngle(2,45);
   delay(200);
  setServoAngle(2,45);

}

void turn_left(int n){
  for(int i =1;i<=n;i++){
   setServoAngle(8,45);
   setServoAngle(2,45);
   delay(500);
   setServoAngle(7,90);
   setServoAngle(3,90);
   delay(500);
   setServoAngle(8,0);
   setServoAngle(2,0);
   delay(500);
   setServoAngle(1,45);
   setServoAngle(9,45);
   delay(500);
   setServoAngle(11,90);
   setServoAngle(0,90);
   delay(500);
   setServoAngle(1,0);
   setServoAngle(9,0);
   delay(200);

   setServoAngle(0,45);
   setServoAngle(11,45);
   setServoAngle(3,45);
   setServoAngle(7,45);
   delay(500);
  }
}

void hi(int n){
  setServoAngle(1,45);
  delay(500);
  setServoAngle(11,90);
  delay(500);
  for (int i =1;i<=n;i++){
    setServoAngle(9,180);// change ankle orientation
    delay(200);
    setServoAngle(9,90);
    delay(200);
  }
  setServoAngle(1,0);
  delay(200);
  setServoAngle(11,90);
  delay(200);
  setServoAngle(9,0);
}

void dance(int n){
    setServoAngle(0,90);
    delay(200);
    setServoAngle(11,90);
    delay(200);
    setServoAngle(7,0);
    delay(200);
    setServoAngle(3,0);   
    setServoAngle(1,45);
    setServoAngle(8,45);
  for(int i=1;i<=n;i++){   
    delay(500);
    setServoAngle(1,90);
    setServoAngle(8,90);
    setServoAngle(9,45);
    setServoAngle(2,45);
    delay(500);
    setServoAngle(1,45);
    setServoAngle(8,45);
    setServoAngle(9,90);
    setServoAngle(2,90); 
  }
    setServoAngle(0,45);
    delay(200);
    setServoAngle(11,45);
    delay(200);
    setServoAngle(7,45);
    delay(200);
    setServoAngle(3,45);  
}

void walk(){
  
}


void loop() 
{
  sleep();
  getup();
  turn_left(1);
  hi(1);
}
