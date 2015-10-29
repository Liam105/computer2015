int interval = 1000;
int buttonPin = 3;
int ledR = 11;
int ledG = 12;
int ledState = 0;
unsigned char swState;
unsigned char swPreState;
unsigned long previousMillis = 0;
unsigned long buttonUpTime = 0;
unsigned long buttonDownTime = 0;
unsigned long preTime = 0;
boolean ledBlinkStateOne=true;
boolean ledBlinkStateTwo=true;
boolean sixOrNot = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledR,OUTPUT);
  pinMode(ledG,OUTPUT);
  ledState = 1;
  digitalWrite(ledR,LOW);
  digitalWrite(ledG,LOW);
  swState = swPreState = digitalRead(buttonPin);
  preTime = millis();
}

void loop() {
  // put your main code here, to run repeatedly:
   sixOrNot = false;
   swState=digitalRead(buttonPin);
   if(swState ==LOW && swPreState==HIGH){
     buttonDownTime = millis();
     if ( buttonDownTime - preTime < 500 ){
        sixOrNot = true;
      }
      preTime = buttonDownTime;
   }
   if(swState ==HIGH && swPreState==LOW){
      buttonUpTime = millis(); 
      if( buttonUpTime - buttonDownTime < 1000){
        if(ledState < 5) {
       ledState = ledState + 1;
     }
   }
      if( buttonUpTime - buttonDownTime >= 1000){
        ledState = 1; 
      }
   }
   if ( sixOrNot == true ){
     ledState = 6; 
   }
   swPreState = swState;
   switch (ledState){
   case 1:
     digitalWrite(ledR,LOW);
     digitalWrite(ledG,LOW);
     break;
   case 2:
     digitalWrite(ledR,LOW);
     digitalWrite(ledG,HIGH);
     break;
   case 3:
     digitalWrite(ledR,HIGH);
     digitalWrite(ledG,LOW);
     break;
   case 4:
     blinkWithoutDelayOne();
     break;
   case 5:
     blinkWithoutDelayTwo();
     break;
   case 6:
     digitalWrite(ledR,HIGH);
     digitalWrite(ledG,HIGH);
     break;
    }
 
}

void blinkWithoutDelayOne()
{
    unsigned long currentMillis = millis();
 
  if(currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED 
    previousMillis = currentMillis;   
    if ( ledBlinkStateOne ){
        digitalWrite(ledR,HIGH);   
        digitalWrite(ledG,LOW);
    }
    else{
        digitalWrite(ledG,HIGH);   
        digitalWrite(ledR,LOW);
    }
    ledBlinkStateOne = !ledBlinkStateOne;
  }

}

void blinkWithoutDelayTwo()
{
    unsigned long currentMillis = millis();
 
  if(currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED 
    previousMillis = currentMillis;   
    if ( ledBlinkStateTwo ){
        digitalWrite(ledR,HIGH);   
        digitalWrite(ledG,HIGH);
    }
    else{
        digitalWrite(ledG,LOW);   
        digitalWrite(ledR,LOW);
    }
    ledBlinkStateTwo = !ledBlinkStateTwo;
  }

}
