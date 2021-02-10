#include <DHT.h>
#include <DHT_U.h>

#include <Wire.h>
#include <Adafruit_NeoPixel.h>

#define DHTTYPE DHT11     // DHT 11
#define SLAVE_ADDRESS 0x12
#define NUMPIXELS 39

bool reservoirVide = false;

  //PIN analogique

  int PIN_LUM = A3;
  int PIN_NIV_EAU = A2;
  int PIN_H_TERRE_1 = A1;
  int PIN_H_TERRE_2 = A0;


  //PIN Digital

  int PIN_DHT11 = 3;
  int PIN_LED_ETAT = 4;
  int PIN_RELAIS_1 = 5;
  int PIN_RELAIS_2 = 6;
  int PIN_RUBAN_LED = 7;
 

  //Valeur
  
  int VAL_HTERRE_1 = 0;
  int VAL_HTERRE_2 = 0;
  int VAL_H = 0;
  int VAL_T = 0;
  int VAL_LUM = 0;
  int VAL_NIV_EAU = 0;
  int i = 0;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, PIN_RUBAN_LED, NEO_RGB + NEO_KHZ800);
DHT dht(PIN_DHT11, DHTTYPE);


void setup() {
  Serial.begin(9600); 
  dht.begin();

  pinMode(PIN_RELAIS_1, OUTPUT);
  pinMode(PIN_RELAIS_2, OUTPUT);
  
  pinMode(PIN_H_TERRE_1, INPUT);
  pinMode(PIN_H_TERRE_2, INPUT);
  pinMode(PIN_LED_ETAT, OUTPUT);
  digitalWrite(PIN_LED_ETAT, HIGH);

  strip.begin();
  strip.show();

  Wire.begin(SLAVE_ADDRESS);
  //Wire.onReceive(receiveData);
  Wire.onRequest(sendData);
}


  /** ------------- DHT 11 ------------- **/
  void Capteur_dht(){
    float VAL_Hf = dht.readHumidity();
    // Lecture de la température en Celcius
    float VAL_Tf = dht.readTemperature();
  
    VAL_H = (int)VAL_Hf;
    VAL_T = (int)VAL_Tf;
    // Pour lire la température en Fahrenheit
    float f = dht.readTemperature(true);
    
    // Stop le programme et renvoie un message d'erreur si le capteur ne renvoie aucune mesure
    if (isnan(VAL_H) || isnan(VAL_T) || isnan(f)) {
      Serial.println("Echec de lecture !");
    }
    else{
      Serial.println(VAL_T);
    }
  }

  // VARIABLE : VAL_T & VAL_H

  /** ------------- Humidité terre 1 ------------- **/
  void Humidite_t1(){
    VAL_HTERRE_1= analogRead(PIN_H_TERRE_1);
    VAL_HTERRE_1 = map(VAL_HTERRE_1,580,280,0,100);
    
    Serial.print("Valeur humidité 1 : ");
    Serial.println(VAL_HTERRE_1);
  }
  // VARIABLE : VAL_HTERRE_1
  
  /** ------------- Humidité terre 2 ------------- **/
  void Humidite_t2(){
    VAL_HTERRE_2 = analogRead(PIN_H_TERRE_2);
    VAL_HTERRE_2 = map(VAL_HTERRE_2,580,280,0,100);
    
   Serial.print("Valeur humidité 2 : ");
   Serial.println(VAL_HTERRE_2);
  }
  // VARIABLE : VAL_HTERRE_2

  /** ------------- ARROSAGE ------------- **/

  void Arrosage(){
    if(VAL_HTERRE_1 < 65 && reservoirVide == false){
    digitalWrite(PIN_RELAIS_1, LOW);
    delay(400);
    digitalWrite(PIN_RELAIS_1, HIGH);
    }
    else{
      digitalWrite(PIN_RELAIS_1, HIGH);
    }
    
    if(VAL_HTERRE_2 < 65 && reservoirVide == false){
      digitalWrite(PIN_RELAIS_2, LOW);
      delay(400);
      digitalWrite(PIN_RELAIS_2, HIGH);
    }
    else{
      digitalWrite(PIN_RELAIS_2, HIGH);
    }
  }

  /** ------------- NIVEAU D'EAU ------------- **/

  void NiveauEau(){
    VAL_NIV_EAU = analogRead(PIN_NIV_EAU); 
  
    Serial.print("Valeur niveau eau : "); 
    Serial.println(VAL_NIV_EAU); 
  
    if(VAL_NIV_EAU < 170){ 
      digitalWrite(PIN_LED_ETAT,HIGH); 
      reservoirVide = true;
    }else{ 
      digitalWrite(PIN_LED_ETAT,LOW); 
      reservoirVide = false;
    } 
  }

  //VARIABLE : VAL_NIV_EAU  

  /** ------------- LUMINOSITÉ ------------- **/

  void Luminosite(){
    VAL_LUM = analogRead(PIN_LUM); // lecture de la valeur analogique, qu'on enregistre dans analog_lum
    VAL_LUM = map(VAL_LUM,0,1024,0,100);
  
    //VARIABLE : VAL_LUM
  
    VAL_LUM = analogRead(PIN_LUM);
    VAL_LUM = map(VAL_LUM,0,1024,0,100);
    Serial.print("Valeur luminosité : ");
    Serial.println(VAL_LUM);
  }
  /** ------------- ALLUMAGE BANDE LED  ------------- **/

  void AllumageLed(){
    if(VAL_LUM<30){
      for(int i=0; i<NUMPIXELS; i++) {
        strip.setPixelColor(i, strip.Color(255, 249, 253));
        strip.setBrightness(50);
        strip.show();
      }
    }
     
    else if(VAL_LUM<20){
      for(int i=0; i<NUMPIXELS; i++) {
        strip.setPixelColor(i, strip.Color(255, 249, 253));
        strip.setBrightness(75);
        strip.show();
      }
    }
    else if(VAL_LUM<10){
      for(int i=0; i<NUMPIXELS; i++) {
        strip.setPixelColor(i, strip.Color(255, 249, 253));
        strip.setBrightness(255);
        strip.show();
      }
    }
    else if(VAL_LUM>30){
        for(int i=0; i<NUMPIXELS; i++) {
        strip.setPixelColor(i, strip.Color(0, 0, 0));
        strip.setBrightness(0);    
        strip.show();
      }
    }
  }

void loop(){
  Capteur_dht();
  Humidite_t1();
  Humidite_t2();
  Arrosage();
  NiveauEau();
  Luminosite();
  AllumageLed();
  delay(3000);  
}

void sendData(){
    if(i==5){
      sendniveaueau();
    }
    if(i==4){
      sendluminosite();
    }
    if(i==3){
      sendtemperature();
    }
    if(i==2){
      sendhumidity();
    }
    if(i==1){
      sendhterre_2();
    }
    if(i==0){
      sendhterre_1();
    }
    i++;
    if(i==5){
      i=0;
    }
    Serial.print(i);

}

void sendhterre_1(){
    Wire.write(VAL_HTERRE_1);
}
void sendhterre_2(){
    Wire.write(VAL_HTERRE_2);
}
void sendhumidity(){
    Wire.write(VAL_H);
}
void sendtemperature(){
    Wire.write(VAL_T);
}
void sendluminosite(){
    Wire.write(VAL_LUM);
}
void sendniveaueau(){
    Wire.write(VAL_NIV_EAU);
}
