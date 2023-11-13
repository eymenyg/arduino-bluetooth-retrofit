int key0, key2, key3;

int KEY0 = A0;
int KEY2 = A2;
int KEY3 = A3;

int PlayPause = 2;
int Next = 3;
int Prev = 4;

void setup() {
  // put your setup code here, to run once:
  pinMode(A0, INPUT); //Next-Prev Mode (KEY0)
  pinMode(A2, INPUT); //CD (key2)
  pinMode(A3, INPUT); //CD (key2)
  
  pinMode(PlayPause, OUTPUT); //PlayPause
  pinMode(Next, OUTPUT); //Next
  pinMode(Prev, OUTPUT); //Prev

  Serial.begin(9600);

}

void checkPlayPause() {
  if((key0 <= 300) && (key2 <= 300) && (key3 >= 850)) {
    // Serial.print("PP: KEY0: ");
    // Serial.print(key0, DEC);
    // Serial.print(" KEY2: ");
    // Serial.print(key2, DEC);
    // Serial.print(" KEY3: ");
    // Serial.println(key3, DEC);
    Serial.println("PP triggered");
    digitalWrite(PlayPause, HIGH);
    delay(200);
    digitalWrite(PlayPause, LOW);
  }
}

void checkPrev() {
  if((key0 >= 900) && (key2 <= 150) && (key3 <= 40)) {
    // Serial.print("Prev: KEY0: ");
    // Serial.print(key0, DEC);
    // Serial.print(" KEY2: ");
    // Serial.print(key2, DEC);
    // Serial.print(" KEY3: ");
    // Serial.println(key3, DEC);
    Serial.println("Prev triggered");
    digitalWrite(Prev, HIGH);
    delay(200);
    digitalWrite(Prev, LOW);
  }
}


void checkNext() {
  if((key0 <= 300) && (key2 >= 900) && (key3 <= 160)) {
    // Serial.print("Next: KEY0: ");
    // Serial.print(key0, DEC);
    // Serial.print(" KEY2: ");
    // Serial.print(key2, DEC);
    // Serial.print(" KEY3: ");
    // Serial.println(key3, DEC);
    Serial.println("Next triggered");
    digitalWrite(Next, HIGH);
    delay(200);
    digitalWrite(Next, LOW);
  }
}

void loop() {
  delay(50);
  key0 = analogRead(A0);
  key2 = analogRead(A2);
  key3 = analogRead(A3);

  // Serial.print("A0: ");
  // Serial.println(key0, DEC);

  // Serial.print("A2: ");
  // Serial.println(key2, DEC);

  // Serial.print("A3: ");
  // Serial.println(key3, DEC);

  // Serial.println();

  if(!(key0 == 0 && key2 == 0 && key3 == 0)) {
    checkPrev();
    checkNext();
    checkPlayPause();

    Serial.print("A0: ");
  Serial.println(key0, DEC);

  Serial.print("A2: ");
  Serial.println(key2, DEC);

  Serial.print("A3: ");
  Serial.println(key3, DEC);
  Serial.println();

  }

  
}
