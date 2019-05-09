#include <OneWire.h>
#include <DallasTemperature.h>

// ---------- Initialisation des variables ---------------------

// Variables propres au DS18B20 capteurs de temp
const int DS18B20_PIN=11;
const int DS18B20_ID=0x28;

// Data wire is plugged into digital pin 2 on the Arduino
#define ONE_WIRE_BUS 11

// Setup a oneWire instance to communicate with any OneWire device
OneWire oneWire(ONE_WIRE_BUS);  

// Pass oneWire reference to DallasTemperature library
DallasTemperature sensors(&oneWire);

int deviceCount = 0;
float cap_int;
float cap_ext;

int lux = analogRead(A0);

 //moteur
int buttonState6 = 0;  //moteur fermer
int fdcfermer=2; //moteur fermer
#define RELAY1 6
#define RELAY2 7
int buttonState7= 0;//moteur ouvrir
int fdcouvert=3;//moteur ouvrir
int w;

void setup() {
 sensors.begin();  // Start up the library
 Serial.begin(9600);
 // locate devices on the bus
 Serial.print("Locating devices...");
 Serial.print("Found ");
 deviceCount = sensors.getDeviceCount();
 Serial.print(deviceCount, DEC);
 Serial.println(" devices.");
 Serial.println("");

  Serial.begin(9600);

   ouvrir();
  fermer();
  lame_0();
  lame_90();
  lame_180();

    pinMode(RELAY1, OUTPUT);//moteur
  pinMode(RELAY2, OUTPUT);//moteur
  digitalWrite(RELAY2,LOW);
  digitalWrite(RELAY1,LOW);
  
  pinMode(fdcouvert, INPUT);//moteur fdc
  pinMode(fdcfermer, INPUT);//moteur fdc

}
  int ouvrir(){
  buttonState7 = digitalRead(fdcouvert);
  if (buttonState7==LOW){
    digitalWrite(RELAY2,LOW);
    return 1;
  }
  else{
    lux = analogRead(A0);
    if(lux > 150){
      digitalWrite(RELAY2,LOW);
      return 1;
    } 
    digitalWrite(RELAY2,HIGH);
  }
}


int fermer() {
  buttonState6 = digitalRead(fdcfermer);
    if (buttonState6==LOW){
      digitalWrite(RELAY1,LOW);
      return 1;
    } 
    else{
      lux = analogRead(A0);
      if(lux < 150){
        digitalWrite(RELAY1,LOW);
        return 1;
      }    
      digitalWrite(RELAY1,HIGH);
    }  
}


void lame_0() {
   // displayColor(COLOR_BLEU);
    //delay(1000);
    //displayColor(COLOR_RIEN);
}

void lame_90() {
  //displayColor(COLOR_ROUGE);
  //delay(1000);
  //displayColor(COLOR_RIEN);
}

void lame_180() {
  //displayColor(COLOR_VERT);
  //delay(1000);
  //displayColor(COLOR_RIEN);
}

void loop() {
  Serial.print("lux");
  Serial.print(" : ");
  Serial.println(lux);
  lux = analogRead(A0);
  sensors.requestTemperatures();
  cap_ext = sensors.getTempCByIndex(0);
  cap_int = sensors.getTempCByIndex(1);
  Serial.println(cap_ext);
  Serial.println(cap_int);

  w = 0;
  if (lux < 150) {
    while (w == 0){
    w = ouvrir();
      if (buttonState7==LOW){
      lame_90() ;
      }
      else {  
      }
    }
  }
  w = 0;
  if (lux >= 150){
    if ( cap_ext > 25.00) {
      if (lux >= 750){ // ou 800 ou 700 
        while (w==0){
        w = fermer();
          if (buttonState6==LOW){
          lame_90() ;
          }
          else {
          }
        }
      }
      if (lux < 750) {
        while (w==0){
        w = fermer();
          if (buttonState6==LOW){
          lame_180() ;
          }
          else {
          }
        }
      }
    }
    if (cap_ext <= 25.00) {
       while (w==0){
        w = ouvrir();
          if (buttonState7==LOW){
          lame_0() ;
          }
          else {
          }
        }
     }
   }
 }
