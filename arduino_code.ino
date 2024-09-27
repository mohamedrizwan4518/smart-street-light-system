// Program for Smart Street Light

//Setup Pin Ports 

void setup() {
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(5, INPUT);    //  1 IR Sensr
  pinMode(7, INPUT);    //  2 IR
  pinMode(4, INPUT);    //  3 IR
  pinMode(2, INPUT);    //  4 IR
  digitalWrite(3, 1);
  digitalWrite(5, 1);
  digitalWrite(9, 1);
  digitalWrite(6, 1);
  Serial.begin(9600);
}

//Logic Part

void loop() {
  int  ldr = analogRead(A0);
  int  ir1 = digitalRead(5);
  int  ir2 = digitalRead(7);
  int  ir3 = digitalRead(4);
  int  ir4 = digitalRead(2);

  Serial.print(ldr);
  Serial.print("   ");
  Serial.print(ir1);
  Serial.print("  ");
  Serial.print(ir2);
  Serial.print("  ");
  Serial.print(ir3);
  Serial.print("  ");
  Serial.println(ir4);

  // Checks whether it is Day time or Night using LDR values

  if (ldr > 300) {
    if (ir1 == 0)
    {

      analogWrite(3, 255);
      delay(10);
    }
    else
    {
      analogWrite(3, 2);

    }
    if (ir2 == 0)
    {
      analogWrite(5, 255);
      delay(10);
    }
    else
    {
      analogWrite(5, 2);

    }
    if (ir3 == 0)
    {
      analogWrite(6, 255);
      delay(10);
    }
    else
    {
      analogWrite(6, 2);

    }
    if (ir4 == 0)
    {
      analogWrite(9, 255);
      delay(10);
    }
    else
    {
      analogWrite(9, 2);

    }
  }
  else
  {
    digitalWrite(3, 0);
    digitalWrite(5, 0);
    digitalWrite(9, 0);
    digitalWrite(6, 0);
  }

}

// Program Ends