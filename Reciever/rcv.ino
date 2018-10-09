#include <RCSwitch.h>
//#include <LiquidCrystal.h>

//LiquidCrystal lcd(4, 5, 11, 12, 13, 14);
RCSwitch mySwitch = RCSwitch();

float level;

int TankSize=20;

// int BUZZER = 10 ;

void setup() {
  mySwitch.enableReceive(0);
  Serial.begin(9600);

 // lcd.begin(16, 2);
  //lcd.print("WATER LEVEL INDI");
  Serial.print("WIRELESS WATER LEVEL INDICATOR");
  Serial.print('\n');
  
 //pinMode(BUZZER,OUTPUT);
}

void loop() {
  if (mySwitch.available()) {
     //Serial.print( mySwitch.getReceivedValue() );
    
    level = mySwitch.getReceivedValue();
    level = TankSize-level;
    /*if (level<1) {Serial.print("Out Of Range Of Water Tank Size ");
    Serial.print('\n');}*/
    
    level = level/TankSize;
    level = level*100;
    if (level>=80) {Serial.print("Tank Is Full");
    Serial.print('\n');}
    if (level<=0) {Serial.print("Tank Is Empty");
    Serial.print('\n');}

    //if (level>100) {level=100;}
    
   // Serial.setCursor(0, 1);
   if (level>0 && level<80){
    Serial.print("LEVEL ");
    Serial.print(level);
    Serial.print(" %       ");
     Serial.print('\n');

   /* lcd.setCursor(0, 1);
    lcd.print("LEVEL ");
    lcd.print(level);
    lcd.print(" %       ");*/
   }

    
    
    mySwitch.resetAvailable();
   
    
  }   
 /* digitalWrite(BUZZER,HIGH);
  if (level > 99) {digitalWrite(BUZZER,HIGH); delay(100); digitalWrite(BUZZER,LOW); delay(100);}
  else  {digitalWrite(BUZZER,LOW);}*/
}
