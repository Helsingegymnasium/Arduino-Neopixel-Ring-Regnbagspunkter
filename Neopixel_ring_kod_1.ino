//NEOPIXEL RING "TÄVLANDE REGNBÅGSPUNKTER"

//Neopixel ring har 16 WS2812 RGB LEDs
//Arduino Uno portar i bruk: 5V, GND, digital port 6
//FastLED 3.2 library används, den kan laddas ner i Arduino library-managern

#include <FastLED.h>

#define NUM_LEDS 16 //vi anger antalet LEDs i Neopixeln
#define DATA_PIN 6 //vi anger dataporten i bruk

int xhue = 0; //variabel för färgen på LEDn
float dot1 = 0; //float-värde för första punkten
float dot2 = 8; //float-värde för andra punkten

CRGB leds[NUM_LEDS]; //

void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  Serial.begin(9600);
}

void loop() {

    //ljuspositionsvärdet
    int dot1int = int(dot1); //vi omvandlar float-variablerna dot1 och dot2 till ints
    int dot2int = int(dot2); //ints används för leds[]

    //vi ger 2 leds på motsatta sidor samma färg
    leds[dot1int] = CHSV(xhue,255,255); //xhue styr färgen, ljusstyrkan och mättningen är maxvärde
    leds[dot2int] = CHSV(xhue,255,255);
            
    //Serial.println("Hue = "); Serial.println(xhue); //värdet av xhue printas
            
    FastLED.show();
            
    //vi gör leden som just fått färg svart igen
    leds[dot1int] = CRGB::Black;
    leds[dot2int] = CRGB::Black;

    //de två punkternas positionsvärde uppdateras
    dot1 += 0.4;
    dot2 += 0.5;

    //vi testar för när float-värdet på dot1 och dot2 överskrider 16 och resettar det till 0
    if(dot1 >= 16) { 
      dot1 = 0;
    }
    
    if(dot2 >= 16) {
      dot2 = 0;
    }
            
    xhue += 2; //xhue får +4 i värdet varje omgång
    
    if(xhue == 255) { //vi testar för om xhue har gått över maxvärdet och omdefinierar det som 0
      xhue = 0;
    }

    delay(60); //cykeln uppdateras med 100 ms mellanrum
    
}
