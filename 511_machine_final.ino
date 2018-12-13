/////////////////////////////
//    Coffee Machine Final
//      By Michael Lai
/////////////////////////////

// Include neopixel library
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

// Define LED & reciever pin
const int ledPin = 13;
const int recvPin = 3;

// Define Neopixel pin 
#define PIN            6
// Number of led lights located
#define NUMPIXELS      8

// Set neopixel global variable
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);


void setup() {
  Serial.begin(9600);
  Serial.println("This board is running coffee machine final.");
  pinMode (recvPin, INPUT_PULLUP);   // Initialize recvPin as input
  pinMode (ledPin, OUTPUT);   // Initialize ledPin as an output

  // Initialize neopixel
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}


//Main code to run repeatedly
void loop() {
  int sense = digitalRead(recvPin); // Reads digital pin
  
  if (sense == LOW) {
    Serial.println("Received a LOW signal.");
    digitalWrite(ledPin, HIGH);
  
    // Using colorWipe function to showcase "brewing"
    colorWipe(strip.Color(255, 0, 0), 20); // Red
    colorWipe(strip.Color(0, 255, 0), 20); // Green
    colorWipe(strip.Color(0, 0, 255), 20); // Blue
    
  } else if(sense == HIGH){
    digitalWrite(ledPin, LOW);
    // Sets "not brewing" mode to red
    colorWipe(strip.Color(255, 0, 0), 20); // Red
  }
}


// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, c);
      strip.show();
      delay(wait);
  }
}
 
