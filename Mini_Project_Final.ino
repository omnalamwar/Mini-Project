#include <Servo.h>            // Include the Servo library
#include <LiquidCrystal.h>    // Include the Servo library

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
Servo Servo1;                 // Create a servo object

//int contrast = 20;            //Setting Contrast
int trig = 8;                 // Declare trig pin of ultrasonic
int echo = 9;                 // Declare echo pin of ultrasonic
int servoPin = 10;            // Declare the Servo pin
int counter=0;                // Declare counter
int currentState = 0;
int previousState = 0;

void setup() 
{
  //analogWrite(6,contrast);
  Servo1.write(90); 
  Servo1.attach(servoPin);    // Attach Servo to the pin
  lcd.begin(16, 2);
  Serial.begin(9600);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  lcd.setCursor(4,0);
  lcd.print("Counter");
  delay(2000);
  lcd.clear();
  
  lcd.setCursor(0,0);
  lcd.print("Please wait.");
  delay(200);
  lcd.clear();
  lcd.print("Please wait..");
  delay(200);
  lcd.clear();
  lcd.print("Please wait...");
  delay(200);
  lcd.clear();
  lcd.print("Please wait....");
  delay(200);
  lcd.clear();
  lcd.print("Please wait.....");
  delay(200);
  lcd.clear();
  
  lcd.setCursor(0,0);
  lcd.print("Visitor Counter");
  delay(2500);
  lcd.clear();
}

void loop() {

  Servo1.write(90);
  lcd.setCursor(0,0);
  lcd.print("People Entered:");
  
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);  
  long duration = pulseIn(echo,HIGH);
  long distance = duration*0.034/2;


  if (distance <= 20){
    currentState = 1;
  }
  else {
    currentState = 0;
  }

  if(currentState == 1 && previousState == 0)
  {
    counter = counter + 1;
    
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("People Entered:");
    lcd.setCursor(7,1);
    lcd.print(counter);
  }
  previousState = currentState;

      //If counter becomes 100
      if (counter == 5)
      {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Full Capacity");
        delay(1500);

        Servo1.write(0);
        
        unsigned long starttime = millis();
        unsigned long endtime = starttime;

        // Do this loop for up to 5000mS
        while ((endtime - starttime) <= 5000)
        {
          lcd.setCursor(0,0);
          lcd.print("Please wait.");
          delay(200);
          lcd.clear();
          lcd.print("Please wait..");
          delay(200);
          lcd.clear();
          lcd.print("Please wait...");
          delay(200);
          lcd.clear();
          lcd.print("Please wait....");
          delay(200);
          lcd.clear();
          lcd.print("Please wait.....");
          delay(200);
          lcd.clear();
          endtime = millis();
        }
      counter = 0;
      }
}
 
