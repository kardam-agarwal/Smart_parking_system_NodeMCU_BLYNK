#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "qqcltIf7wZQMUdcU1nhwvk_khauTjLN1";
char ssid[] = "k27";
char password[] = "987654321";

int ir11=16;
int ir22=5;

WidgetLCD lcd(V1);
WidgetLED led1(V2);
WidgetLED led2(V3);

void setup()
{  
  Serial.begin(115200);

  pinMode(ir11,INPUT);
  pinMode(ir22,INPUT);
  // Connect to WiFi network
  Serial.println(); 
  Serial.print("Connecting to ");
  Serial.println(ssid);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");

 
  Blynk.begin(auth, ssid, password);
  lcd.clear();
  
}


void loop()
{
  Blynk.run();

  int  ir1=digitalRead(ir11);
  int  ir2=digitalRead(ir22);
  
  
   if (ir1==LOW && ir2==LOW )
   {
    lcd.clear();
    lcd.print(0,0,"Slot 1 : Empty  Slot 2 : Empty");
    led1.off();
    led2.off();
    Blynk.email("kardam.agarwal@gmail.com","SMART PARKING","Slot 1 : Empty  Slot 2 : Empty");
    delay(400);
    
   }
   else if (ir1==LOW && ir2==HIGH)
   {
    lcd.clear();
    lcd.print(0,0,"Slot 1 : Empty  Slot 2 : Full");
    led1.off();
    led2.on();
    Blynk.email("kardam.agarwal@gmail.com","SMART PARKING","Slot 1 : Empty  Slot 2 : Full");
    delay(400);
    
   }
   else if (ir1==HIGH && ir2==LOW)
   {
    lcd.clear();
    lcd.print(0,0,"Slot 1 : Full   Slot 2 : Empty");
    led1.on();
    led2.off();
    Blynk.email("kardam.agarwal@gmail.com","SMART PARKING","Slot 1 : Full  Slot 2 : Empty");
    delay(400);
   }
   else if (ir1==HIGH && ir2==HIGH)
   {
    lcd.clear();
    lcd.print(0,0,"Slot 1 : Full   Slot 2 : Full");
    led1.on();
    led2.on();
    Blynk.email("kardam.agarwal@gmail.com","SMART PARKING","Slot 1 : Full  Slot 2 : Full");
    delay(400);
    
   }
  
}
