int key0, key1;

int KEY0 = A0; //KEY0 on PCB connected to A0 pin via 10k resistor
int KEY1 = A1; //KEY1 on PCB connected to A1 pin via 10k resistor

int Power = 2;
int Next = 3;
int PlayPause = 4;
int Prev = 5;

int counter = 0;

bool isPowerOn;

void setup() {
  // put your setup code here, to run once:
  pinMode(A0, INPUT); //Next-Prev Mode (KEY0)
  pinMode(A1, INPUT); //CD (KEY1)
  
  pinMode(2, OUTPUT); //Power
  pinMode(3, OUTPUT); //Next
  pinMode(4, OUTPUT); //PlayPause
  pinMode(5, OUTPUT); //Prev

  isPowerOn = true;

  Serial.begin(9600);

}

void checkPrev() {
  if(key0 >= 70 && key0 <= 110) {
    Serial.print("Prev: KEY0: ");
    Serial.println(key0, DEC);
    digitalWrite(Prev, HIGH);
    delay(200);
    digitalWrite(Prev, LOW);
  }
}


void checkNext() {
  if(key0 >= 170 && key0 <= 210) {
    Serial.print("Next: KEY0: ");
    Serial.println(key0, DEC);
    digitalWrite(Next, HIGH);
    delay(200);
    digitalWrite(Next, LOW);
  }
}

void checkREW() {
  //MH-M18 Vol Down
  if(key0 >= 390 && key0 <= 430) {
    Serial.print("REV: KEY0: ");
    Serial.println(key0, DEC);
    digitalWrite(Prev, HIGH);
    delay(1000);
    digitalWrite(Prev, LOW);
  }
}

void checkFF() {
  //MH-M18 Vol Up
  if(key0 >= 490 && key0 <= 530) {
    Serial.print("FF: KEY0: ");
    Serial.println(key0, DEC);
    digitalWrite(Next, HIGH);
    delay(1000);
    digitalWrite(Next, LOW);
  }
}

void checkCDMP3() {
  if(key1 >= 290 && key1 <= 350) {
    Serial.print("CD: KEY1: ");
    Serial.println(key1, DEC);
    counter++;
    Serial.print("Counter: ");
    Serial.println(counter);
    if(counter >= 12) {
      Serial.println("Toggling power...");
      counter = 0;
      digitalWrite(Power, HIGH);
      delay(200);
      digitalWrite(Power, LOW);
      isPowerOn = !isPowerOn;
      Serial.print("Power is now ");
      Serial.println(isPowerOn ? "on" : "off");
      delay(800);
    }
  }
  else
    counter = 0;
}

void checkMidButton() {
  if(key0 >= 545 && key0 <= 590 && key1 >= 545 && key1 <= 590) {
    Serial.print("Mid KEY0: ");
    Serial.println(key0, DEC);
    Serial.print("Mid KEY1: ");
    Serial.println(key1, DEC);
    digitalWrite(PlayPause, HIGH);
    delay(200);
    digitalWrite(PlayPause, LOW);
  }
}

void loop() {
  delay(50);
  key0 = analogRead(KEY0);
  key1 = analogRead(KEY1);

  // Serial.print("KEY0: ");
  // Serial.println(key0, DEC);
  // Serial.print("KEY1: ");
  // Serial.println(key1, DEC);
  checkCDMP3();

  if(isPowerOn) {
    checkPrev();
    checkNext();
    checkREW();
    checkFF();
    checkMidButton();
  }
}
