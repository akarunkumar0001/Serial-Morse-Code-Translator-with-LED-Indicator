const int ledPin = 3;

const char* morseCode[] = {
  ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..",
  "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----."
};

const char letters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("Enter a word that contains(A-Z, 0-9) to see its Morse code:");
}

void loop() {
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');
    input.toUpperCase();

    for (int i = 0; i < input.length(); i++) {
      char ch = input.charAt(i);

      if (ch >= 'A' && ch <= 'Z') {
        displayMorseCode(ch - 'A');
      } else if (ch >= '0' && ch <= '9') {
        displayMorseCode(ch - '0' + 26);
      } else {
        Serial.print("Character '");
        Serial.print(ch);
        Serial.println("' is not supported.");
        delay(1000);
      }
      
      delay(300);
    }
    
    Serial.println();
  }
}

void displayMorseCode(int index) {
  String code = morseCode[index];
  
  for (int i = 0; i < code.length(); i++) {
    if (code.charAt(i) == '.') {
      blinkLED(200);
    } else if (code.charAt(i) == '-') {
      blinkLED(600);
    }
    delay(200);
  }
  
  delay(400);
}

void blinkLED(int duration) {
  digitalWrite(ledPin, HIGH);
  delay(duration);
  digitalWrite(ledPin, LOW);
  delay(duration);
}
