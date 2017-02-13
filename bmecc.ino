int ledgreen1 = 3;//left
int ledgreen2 = 4;
int ledgreen3 = 5;
int ledred1=12;
int ledred2=13;
int ledred3=2;


int trigPin1 = 6;
int echoPin1 = 7;

int trigPin2 = 8;
int echoPin2 = 9;

int trigPin3 = 10;
int echoPin3 = 11;

bool isselected=false;
void setup() {
  Serial.begin (9600);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
  
  pinMode(ledgreen1, OUTPUT);
  pinMode(ledgreen2, OUTPUT);
  pinMode(ledgreen3, OUTPUT);
  pinMode(ledred1, OUTPUT);
  pinMode(ledred2, OUTPUT);
  pinMode(ledred3, OUTPUT);
}

void firstsensor(){ // This function is for first sensor.
  long duration1, distance1;
  digitalWrite (trigPin1, LOW);
  delayMicroseconds (2);
  digitalWrite (trigPin1, HIGH);
  
  delayMicroseconds (10);
  digitalWrite (trigPin1, LOW);
  duration1 = pulseIn (echoPin1, HIGH);
  distance1 = (duration1/2) / 29.1;
 
  if (distance1 < 40&&!isselected) {  // Change the number for long or short distances.
   Serial.print("Selected 'A' \n");
      digitalWrite (ledgreen1, HIGH);
      isselected=true;
    delay(200);
    if(distance1<15) {
      Serial.print("Clicked A \n");
      Serial.println("A");
      digitalWrite(ledred1, HIGH);
      delay(200);
    }
   else digitalWrite(ledred1, LOW);
  } else {
    digitalWrite (ledgreen1, LOW);
     digitalWrite(ledred1, LOW);
     isselected=false;
  }    
}
void secondsensor(){ // This function is for second sensor.
    long duration2, distance2;
  digitalWrite (trigPin2, LOW);
  delayMicroseconds (2);
    digitalWrite (trigPin2, HIGH);
    delayMicroseconds (10);
    digitalWrite (trigPin2, LOW);
    duration2 = pulseIn (echoPin2, HIGH);
    distance2 = (duration2/2) / 29.1;
  
     
     
    if (distance2 < 40&&!isselected) {  // Change the number for long or short distances.
      Serial.print("Selected 'B' \n");
      isselected=true;
      digitalWrite (ledgreen2, HIGH);
      delay(200);
      if(distance2<15) {
      Serial.print("Clicked B \n");
        digitalWrite(ledred2, HIGH);
        delay(200);
      }
    } 
    
 else {
      digitalWrite (ledgreen2, LOW);
      digitalWrite(ledred2, LOW);
      isselected=false;
    }    
}
void thirdsensor(){ // This function is for third sensor.
    long duration3, distance3;
  digitalWrite (trigPin3, LOW);
  delayMicroseconds (2);
    digitalWrite (trigPin3, HIGH);
    delayMicroseconds (10);
    digitalWrite (trigPin3, LOW);
    duration3 = pulseIn (echoPin3, HIGH);
    distance3 = (duration3/2) / 29.1;

    
   
    if (distance3 < 40&&!isselected) {  // Change the number for long or short distances.
      Serial.print("Selected 'C' \n");
       digitalWrite (ledgreen3, HIGH);
       isselected=true;
      delay(200);
   
     
     if(distance3<15) {
      Serial.print("Clicked C \n");
      digitalWrite(ledred3, HIGH);
      delay(200);
     }
    
    
    }
 else {
      digitalWrite (ledgreen3, LOW);
       digitalWrite(ledred3, LOW);
       isselected=false;
    }   
}

void loop() {
Serial.println("\n");
firstsensor();
secondsensor();
thirdsensor();
delay(100);
} 

