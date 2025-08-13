const int braillePins[6] = {14, 27, 26, 25, 33, 32};  // Braille vibration motor pins
const int buttonPin = 22;
const int buzzerPin = 23;
bool lastButtonState = LOW;

// Braille patterns for A-Z (dot positions 1 to 6)

const bool brailleMap[26][6] = {
{1,0,0,0,0,0}, // A
{1,1,0,0,0,0}, // B
{1,0,0,1,0,0}, // C
{1,0,0,1,1,0}, // D
{1,0,0,0,1,0}, // E
{1,1,0,1,0,0}, // F
{1,1,0,1,1,0}, // G
{1,1,0,0,1,0}, // H
{0,1,0,1,0,0}, // I
{0,1,0,1,1,0}, // J
{1,0,1,0,0,0}, // K
{1,1,1,0,0,0}, // L
{1,0,1,1,0,0}, // M
{1,0,1,1,1,0}, // N
{1,0,1,0,1,0}, // O
{1,1,1,1,0,0}, // P
{1,1,1,1,1,0}, // Q
{1,1,1,0,1,0}, // R
{0,1,1,1,0,0}, // S
{0,1,1,1,1,0}, // T
{1,0,1,0,0,1}, // U
{1,1,1,0,0,1}, // V
{0,1,0,1,1,1}, // W
{1,0,1,1,0,1}, // X
{1,0,1,1,1,1}, // Y
{1,0,1,0,1,1} // Z
};
void playBuzzer() {
tone(buzzerPin, 1000); // Play 1kHz tone
delay(200);
noTone(buzzerPin); // Stop tone
}
void setup() { 
Serial.begin(9600);
// Initialize braille motor pins
for (int i = 0; i < 6; i++) {
pinMode(braillePins[i], OUTPUT);
digitalWrite(braillePins[i], LOW);
}
pinMode(buzzerPin, OUTPUT);
pinMode(buttonPin, INPUT_PULLUP); // Internal pull-up resistor
}
void loop() {
// Detect button press (falling edge)
bool currentButton = digitalRead(buttonPin);
if (lastButtonState == HIGH && currentButton == LOW) {
Serial.println("#START"); // Notify Python to begin voice input
playBuzzer(); // Audible feedback
delay(500); // Debounce delay
}
lastButtonState = currentButton;
// Handle incoming characters
if (Serial.available()) {
char received = Serial.read();
if (isAlpha(received)) {
char letter = toupper(received);
int index = letter - 'A';
if (index >= 0 && index < 26) {
// Vibrate Braille pattern
for (int i = 0; i < 6; i++) {
digitalWrite(braillePins[i], brailleMap[index][i]);
}
playBuzzer(); // Buzzer feedback after showing letter
delay(800); // Allow user to feel vibration
for (int i = 0; i < 6; i++) {
digitalWrite(braillePins[i], LOW);
}
delay(200); // Brief pause before next letter
}
}
}
}
