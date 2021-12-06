#define BuzzerPin 4 // 22 on the breadboard
#define ButtonPinEasy 5 // 23 on the breadboard
#define ButtonPinMedium 6 // 24 on the breadboard
#define ButtonPinHard 7 // 25 on the breadboard

void Countdown();
void EasyMode();
void MediumMode();
void HardMode();

int ButtonStateEasy = 0;
int ButtonStateMedium = 0;
int ButtonStateHard = 0;

void setup() 
{  
  Serial.begin(9600);
  pinMode(ButtonPinEasy, INPUT_PULLUP);
  pinMode(ButtonPinMedium, INPUT_PULLUP);
  pinMode(ButtonPinHard, INPUT_PULLUP);
}

void loop()
{
  ButtonStateEasy = digitalRead(ButtonPinEasy);
  ButtonStateMedium = digitalRead(ButtonPinMedium);
  ButtonStateHard = digitalRead(ButtonPinHard);
  
  if(ButtonStateEasy == LOW)
  {
      Serial.print("Easy Mode Selected");
      Serial.print('\n');
      EasyMode();
  }

  if(ButtonStateMedium == LOW)
  {
      Serial.print("Medium Mode Selected");
      Serial.print('\n');
      MediumMode();
  }

  if(ButtonStateHard == LOW)
  {
      Serial.print("Hard Mode Selected");
      Serial.print('\n');
      HardMode();
  }
}

void Countdown()
{
  Serial.print("CountDown loop started: ");
  Serial.print('\n');

  for(int i = 0; i < 2; i++)
  {
    tone(BuzzerPin, 1000, 200);
    delay(1000);
    tone(BuzzerPin, 1000, 200);
    delay(1000);
    tone(BuzzerPin, 1000, 600);
    delay(1000);
  }
    Serial.print("Countdown done");
    Serial.print('\n');
}

void EasyMode()
{
  Countdown();
  for(int i = 0; i < 15; i++)
  {
    Serial.print("Starting first reps");
    Serial.print('\n');
    delay(30000);
    tone(BuzzerPin, 1000, 1500);
    delay(30000);
    Serial.print("Finish first rep, prepare for next countdown");
    Serial.print('\n');
    Countdown();
  }
}

void MediumMode()
{
  Countdown();
  for(int i = 0; i < 15; i++)
  {
    Serial.print("Starting first reps");
    Serial.print('\n');
    delay(40000);
    tone(BuzzerPin, 1000, 1500);
    delay(20000);
    Serial.print("Finish first rep, prepare for next countdown");
    Serial.print('\n');
    Countdown();
  }
}

void HardMode()
{
  Countdown();
  for(int i = 0; i < 15; i++)
  {
    Serial.print("Starting first reps");
    Serial.print('\n');
    delay(45000);
    tone(BuzzerPin, 1000, 1500);
    delay(15000);
    Serial.print("Finish first rep, prepare for next countdown");
    Serial.print('\n');
    Countdown();
  }
}


// Countdown buzzer function 
  // Buzz then get quicker as it countsdown


// Easy mode function
  // 45 seconds workout, 15 seconds rest
  // Repeat 15 times
