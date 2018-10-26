
//RGB LED PİNLER
const int redLed = 11;
const int greenLed = 10;
const int blueLed = 9;

const int oneLed = 2;
const int twoLed = 3;
const int threeLed = 4;
const int fourLed = 5;

const int buttonPin = 7;
const int buzzerPin = 6;
const int potPin = A0;

bool runningMac = false;

void setup() {

  //Serial.begin(9600);
  
  //RGB LED PİN TANIMLAMA
  pinMode(redLed,OUTPUT);
  pinMode(greenLed,OUTPUT);
  pinMode(blueLed,OUTPUT);

  pinMode(oneLed,OUTPUT);
  pinMode(twoLed,OUTPUT);
  pinMode(threeLed,OUTPUT);
  pinMode(fourLed,OUTPUT);
  
  pinMode(buttonPin,INPUT);
}

void loop() {

 //changeColor("Red");
 //Serial.print(runningMac);
 
  //BAŞLAT // DURDUR
  if(digitalRead(buttonPin) == 1){
    
    runningMac = !runningMac;
    
    delay(150);
    
  }

  

  if(runningMac){
    changeColor("Green");  
    int volume = analogRead(potPin);
    volume = map(volume,0,1023,0,5);
    //Serial.print(volume);
    
    if(volume==0){
      digitalWrite(oneLed,LOW);
      digitalWrite(twoLed,LOW);
      digitalWrite(threeLed,LOW);
      digitalWrite(fourLed,LOW);
      melodi(80);
    }else if(volume==1){
      digitalWrite(oneLed,HIGH);
      digitalWrite(twoLed,LOW);
      digitalWrite(threeLed,LOW);
      digitalWrite(fourLed,LOW);
      melodi(70);
    }else if(volume==2){
      digitalWrite(oneLed,HIGH);
      digitalWrite(twoLed,HIGH);
      digitalWrite(threeLed,LOW);
      digitalWrite(fourLed,LOW);
      melodi(60);
    }else if(volume==3){
      digitalWrite(oneLed,HIGH);
      digitalWrite(twoLed,HIGH);
      digitalWrite(threeLed,HIGH);
      digitalWrite(fourLed,LOW);
      melodi(50);
    }
    else if(volume==4){
      digitalWrite(oneLed,HIGH);
      digitalWrite(twoLed,HIGH);
      digitalWrite(threeLed,HIGH);
      digitalWrite(fourLed,HIGH);
      melodi(40);
    }
    
  }else{
    changeColor("Red");
    digitalWrite(oneLed,LOW);
    digitalWrite(twoLed,LOW);
    digitalWrite(threeLed,LOW);
    digitalWrite(fourLed,LOW);
  }
  
 
}




void changeColor(String color){

  if(color == "Red"){
    
    digitalWrite(redLed,LOW);
    digitalWrite(greenLed,HIGH);
    digitalWrite(blueLed,HIGH);
    
  }else if(color == "Green"){
    
    digitalWrite(redLed,HIGH);
    digitalWrite(greenLed,LOW);
    digitalWrite(blueLed,HIGH);
    
  }else if(color == "Blue"){
    
    digitalWrite(redLed,HIGH);
    digitalWrite(greenLed,HIGH);
    digitalWrite(blueLed,LOW);
    
  }else if(color == "White"){
    
    digitalWrite(redLed,LOW);
    digitalWrite(greenLed,LOW);
    digitalWrite(blueLed,LOW);
    
  }else{
    digitalWrite(redLed,HIGH);
    digitalWrite(greenLed,HIGH);
    digitalWrite(blueLed,HIGH);
  }

  /*if(R > 255 || G > 255 || B > 255){
    
    analogWrite(redLed,255);
    analogWrite(greenLed,255);
    analogWrite(blueLed,255);
    
  }else{
    
    analogWrite(redLed,255-R);
    analogWrite(greenLed,255-G);
    analogWrite(blueLed,255-B);
  }*/
  
}

void melodi(int dly){
  tone(buzzerPin , 440);
  delay(dly);
  noTone(buzzerPin);
  delay(dly);
}
