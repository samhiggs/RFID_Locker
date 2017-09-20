int ledPin = 8; //pin of red LED light
String in;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  if(Serial.available()) {;}
  in = Serial.read();
  
  if(in.equals("hello")){
    for(int i = 0;i < 5;++i){
      digitalWrite(ledPin, HIGH);
      delay(500);
      digitalWrite(ledPin, LOW);
      delay(500);
    }
  } else if(in.equals("bye")){
    digitalWrite(ledPin, HIGH);
    delay(5000);
    digitalWrite(ledPin, LOW); 
  }
}

