/////////////////////////////
//    Coffee Mug Final
//      By Adele Parsons
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
#define NUMPIXELS      6

// Set neopixel global variable
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip2 = Adafruit_NeoPixel(NUMPIXELS, pintwo, NEO_GRB + NEO_KHZ800);


void setup() {
  Serial.begin(9600);
  Serial.println("This board is running coffee machine final.");
  pinMode (recvPin, INPUT_PULLUP);   // Initialize recvPin as input
  pinMode (ledPin, OUTPUT);   // Initialize ledPin as an output

  // Initialize neopixel strips 1 & 2
  strip.begin();
  strip2.begin();
  strip.show(); // Initialize all pixels to 'off'
  strip2.show(); // Initialize all pixels to 'off'
}

//Main code to run repeatedly
void loop() {
  int sense = digitalRead(recvPin); // Reads digital pin
  
  if (sense == LOW) {
    Serial.println("Received a LOW signal.");
    digitalWrite(ledPin, LOW);

    // Using colorWipe function to showcase "filling"
    colorWipe(strip.Color(255, 0, 0), 20); // Red
    colorWipe(strip2.Color(255, 0, 0), 20); // Red
  } else if(sense == HIGH){
    digitalWrite(ledPin, HIGH);
    // Sets "not filling" mode to green
    colorWipe(strip.Color(0, 150, 0), 20); // green
    colorWipe(strip2.Color(0, 150, 0), 20); // green  
  }
}

// Fill the dots one after the other with a color
void colorWipe(uint32_t c, int wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, c);
      strip.show();
      strip2.setPixelColor(i, c);
      strip2.show();
      delay(wait);
  }
}
 
