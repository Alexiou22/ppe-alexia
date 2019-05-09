
int lux = analogRead(A0);

 //moteur
int buttonState6 = 0;  //moteur fermer
int fdcfermer=2; //moteur fermer
#define RELAY1 6
#define RELAY2 7
int buttonState7= 0;//moteur ouvrir
int fdcouvert=3;//moteur ouvrir
int sortie_boucle;


void setup() {
  // put your setup code here, to run once:
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
  digitalWrite(RELAY1,LOW);
  digitalWrite(RELAY2,LOW);
  lux = analogRead(A0);
  Serial.print("lux");
  Serial.print(" : ");
  Serial.println(lux);
 

  sortie_boucle = 0;
  if (lux < 150) {
    while (sortie_boucle == 0){
      sortie_boucle = ouvrir();
      if (buttonState6==LOW){
        lame_90() ;
      }
      else {
        }
      }
    
  }
  sortie_boucle = 0;
  if (lux >= 149){
    while (sortie_boucle == 0){
      sortie_boucle = fermer();
      if (buttonState6==LOW){
        lame_0() ;
      }
      else {
      }
    }
  }
}
  
