#define YLW_LED_PIN 7
#define RED_LED_PIN 6
#define YLWBUTTON_PIN  5
#define REDBUTTON_PIN  4

bool YLWledState = LOW;
bool YLWbuttonState;
bool YLWlastButtonState = LOW;
unsigned long YLWlastDebounceTime = 0;
unsigned long YLWdebounceDelay = 50;

bool REDledState = LOW;
bool REDbuttonState;
bool REDlastButtonState = LOW;
unsigned long REDlastDebounceTime = 0;
unsigned long REDdebounceDelay = 50;


void setup() {

  pinMode(YLWBUTTON_PIN, INPUT_PULLUP);
  pinMode(REDBUTTON_PIN, INPUT_PULLUP);
  pinMode(YLW_LED_PIN, OUTPUT);
  pinMode(RED_LED_PIN, OUTPUT);

}

void loop() {

  // Debouncing of the input button
  int YLWreading = digitalRead(YLWBUTTON_PIN);
  int REDreading = digitalRead(REDBUTTON_PIN);

  if (YLWreading != YLWlastButtonState) {
    YLWlastDebounceTime = millis();
  }

  if (REDreading != REDlastButtonState) {
    REDlastDebounceTime = millis();
  }

  if ((millis() - YLWlastDebounceTime) > YLWdebounceDelay) {
    if (YLWreading != YLWbuttonState) {
      YLWbuttonState = YLWreading;
      if (YLWbuttonState == LOW) {
        YLWledState = !YLWledState;
        digitalWrite(YLW_LED_PIN, YLWledState);
      }
    }
  }

  if ((millis() - REDlastDebounceTime) > REDdebounceDelay) {
    if (REDreading != REDbuttonState) {
      REDbuttonState = REDreading;
      if (REDbuttonState == LOW) {
        REDledState = !REDledState;
        digitalWrite(RED_LED_PIN, REDledState);
      }
    }
  }

  YLWlastButtonState = YLWreading;
  REDlastButtonState = REDreading;
}
