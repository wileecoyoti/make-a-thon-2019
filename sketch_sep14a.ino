/*
 * 
// --- Make-A-Thon Game Robot ---//
//--- Physics Anonymous, lousy coding by rrWilhelm ---//

 * Sits in loop, waiting for button presses. Button presses corrospond to items added to an array. 
 * If last button press is 'go' then starts running items from the array, divided in to either [forward] or [+/-][rotate] commands.
 * 
 * array items:
 *  0=no item added (default), also a stop bit
 *  1=move forward
 *  2=turn
 *  3=turn the other way
 * 
 * l298n controller info:
 *  H-Bridge format
 *  pins 1-2 mean A direction, LOW-HIGH=forward, HIGH-LOW=reverse
 *  pins 3-4 mean B direction, LOW-HIGH=forward, HIGH-LOW=reverse
 *  
 *  enable A/B = PWM signals for movement
 *  
 */

/* --- Variables to adjust --- */
int moveSpeed = 255; // pwm, 0-255 where 255 is max
int moveRunTime = 500; // adjust this to get distance. This is time in milliseconds.
int rotateRunTime = 500; // adjust this to get your 90 degrees. This is time in milliseconds.
int pauseBetween = 300; // satisfying pause between moves


/* --- Variables not to adjust ---*/
int movesArray[100]; // 100 is the maximum possible number of moves. Not sure what happens when it gets overrun...

/* --- Pinout --- */
int pwmA = 9;
int dir1A = 5;
int dir2A = 6;
int pwmB = 10;
int dir1B = 7;
int dir2B = 8;
int buttonFWD = 4;
int buttonLEFT = 3;
int buttonRIGHT = 2;
int buttonGO = 1;
int buzzer = 11;


/* --- misc use --- */
int fwdVar;
int leftVar;
int rightVar;
int goVar;
int arrayPosition;

void setup() {
  /* --- pin modes --- */
  pinMode(buttonFWD, INPUT);
  pinMode(buttonLEFT, INPUT);
  pinMode(buttonRIGHT, INPUT);
  pinMode(buttonGO, INPUT);
  pinMode(pwmA, OUTPUT);
  pinMode(dir1A, OUTPUT);
  pinMode(dir2A, OUTPUT);
  pinMode(pwmB, OUTPUT);
  pinMode(dir1B, OUTPUT);
  pinMode(dir2B, OUTPUT);
  pinMode(buzzer, OUTPUT);
  
      tone(buzzer, 1000);
      delay(200);
      noTone(buzzer);
      delay(100);
      tone(buzzer, 1000);
      delay(200);
      noTone(buzzer);
      delay(100);
      tone(buzzer, 1000);
      delay(200);
      noTone(buzzer);
      delay(100);
      tone(buzzer, 1000);
      delay(200);
      noTone(buzzer);
      delay(100);
      tone(buzzer, 1000);
      delay(200);
      noTone(buzzer);
      delay(100);
}

void loop() {
  /* --- constant polling for button inputs, would be better as interrupt but whatever --- */
  fwdVar = digitalRead(buttonFWD);
  leftVar = digitalRead(buttonLEFT);
  rightVar = digitalRead(buttonRIGHT);
  goVar = digitalRead(buttonGO);
  if ((fwdVar+leftVar+rightVar+goVar) >= 1) {
    updateArray();
  }

}

void updateArray() {
  if (fwdVar) {
    movesArray[arrayPosition] = 1;
      tone(buzzer, 1000);
      delay(250);
      noTone(buzzer);
  }
  if (leftVar) {
    movesArray[arrayPosition] = 2;
      tone(buzzer, 1200);
      delay(250);
      noTone(buzzer);
  }
  if (rightVar) {
    movesArray[arrayPosition] = 3;
      tone(buzzer, 800);
      delay(250);
      noTone(buzzer);
  }
  fwdVar=0;
  leftVar=0;
  rightVar=0; // reset these so they don't auto-trigger again!
  arrayPosition++;

  
  if (goVar) {
    goVar=0;
    runPath();
  }
  delay(200); // dead button time to prevent accidental double presses
}


void runPath() {
      tone(buzzer, 1000);
      delay(200);
      noTone(buzzer);
      delay(100);
      tone(buzzer, 1000);
      delay(200);
      noTone(buzzer);
      delay(100);
      tone(buzzer, 1000);
      delay(200);
      noTone(buzzer);
      delay(100);
      tone(buzzer, 1000);
      delay(200);
      noTone(buzzer);
      delay(100);
      tone(buzzer, 1000);
      delay(200);
      noTone(buzzer);
      delay(100);
  
  /* --- do the thing --- */
  arrayPosition=0;
    while (movesArray[arrayPosition] != 0) {
      if (movesArray[arrayPosition] == 1) {
        moveForward();
      }
      if (movesArray[arrayPosition] == 2) {
        moveTurn(2);
      }
      if (movesArray[arrayPosition] == 3) {
        moveTurn(3);
      }
      delay(pauseBetween);
      arrayPosition++;
    }
  memset(movesArray, 0, sizeof(movesArray)); // clear out the array
  arrayPosition=0;

}

void moveForward() {
  digitalWrite(dir1A, HIGH);
  digitalWrite(dir2A, LOW);
  digitalWrite(dir1B, HIGH);
  digitalWrite(dir2B, LOW);

  analogWrite(pwmA, moveSpeed);
  analogWrite(pwmB, moveSpeed);

  delay(moveRunTime);

  analogWrite(pwmA, 0);
  analogWrite(pwmB, 0);
  

}

void moveTurn (int theDirection) {
  if (theDirection == 2) {
     digitalWrite(dir1A, HIGH);
    digitalWrite(dir2A, LOW);
    digitalWrite(dir1B, LOW);
    digitalWrite(dir2B, HIGH);
   
  }
  if (theDirection == 3) {
     digitalWrite(dir1A, LOW);
    digitalWrite(dir2A, HIGH);
    digitalWrite(dir1B, HIGH);
    digitalWrite(dir2B, LOW);
  }
  
  analogWrite(pwmA, moveSpeed);
  analogWrite(pwmB, moveSpeed);

  delay(rotateRunTime);

  analogWrite(pwmA, 0);
  analogWrite(pwmB, 0);


}
