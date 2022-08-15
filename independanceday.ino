
//#include <LEDMatrix.h>
#include <LEDText.h>
#include <FontMatrise.h>#include "FastLED.h"
CRGB leds[256];
int speakerPin = 7;
int length = 149;
char notes[] = "cdeeeeeeeeedef eeedddbdc ccgggggggggaf fffffeddf eedeedeggaff eeeeeddbdc cdeeeedf efgggfedfe feeeddbdc ccggggeggggga fffffedfe egc bab aga ccddeedef "; // a space represents a rest
int beats[] = { 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1,
                2, 1, 1, 2, 1, 1, 1, 1, 1, 1,
                2, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1,
                2, 1, 1, 2, 1, 1, 1, 1, 1, 1,
                2, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1,
                2, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1,
                1, 1, 1, 1, 2, 2, 2, 1, 1,
                1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1,
                2, 2, 1, 1, 1, 1, 1, 1, 1, 1,
                1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 1,
                2, 1, 1, 2, 1, 1, 1, 1, 1, 1,
                1, 1, 4, 1, 1, 1, 4, 1, 1, 1, 4, 1,
                1, 1, 1, 1, 1, 1, 1, 1, 4, 1
              };
int tempo = 200;
const long flag[] PROGMEM = {
  0xff4500,  0xff4500, 0xff4500, 0xff4500, 0xff4500, 0xff4500, 0xff4500, 0xff4500, 0xff4500, 0xff4500, 0xff4500, 0xff4500, 0xff4500, 0xff4500, 0xff4500, 0xff4500,
  0xff4500, 0xff4500, 0xff4500, 0xff4500, 0xff4500, 0xff4500, 0xff4500, 0xff4500, 0xff4500, 0xff4500, 0xff4500, 0xff4500, 0xff4500, 0xff4500, 0xff4500, 0xff4500,
  0xff4500, 0xff4500, 0xff4500, 0xff4500, 0xff4500, 0xff4500, 0xff4500, 0xff4500, 0xff4500, 0xff4500, 0xff4500, 0xff4500, 0xff4500, 0xff4500, 0xff4500, 0xff4500,
  0xff4500, 0xff4500, 0xff4500, 0xff4500, 0xff4500, 0xff4500, 0xff4500, 0xff4500, 0xff4500, 0xff4500, 0xff4500, 0xff4500, 0xff4500, 0xff4500, 0xff4500, 0xff4500,
  0xff4500, 0xff4500, 0xff4500, 0xff4500, 0xff4500, 0xff4500, 0xff4500, 0xff4500, 0xff4500, 0xff4500, 0xff4500, 0xff4500, 0xff4500, 0xff4500, 0xff4500, 0xff4500,
  0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0x000080,  0x000080,  0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff,
  0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0x000080,  0x000080,  0x000080,  0x000080,  0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff,
  0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0x000080,  0x000080,  0x000080,  0x000080,  0x000080,  0x000080,  0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff,
  0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0x000080,  0x000080,  0x000080,  0x000080,  0x000080,  0x000080,  0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff,
  0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0x000080,  0x000080,  0x000080,  0x000080,  0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff,
  0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0x000080,  0x000080,  0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff, 0xffffff,
  0x32cd32, 0x32cd32, 0x32cd32, 0x32cd32, 0x32cd32, 0x32cd32, 0x32cd32, 0x32cd32, 0x32cd32, 0x32cd32, 0x32cd32, 0x32cd32, 0x32cd32, 0x32cd32, 0x32cd32, 0x32cd32,
  0x32cd32, 0x32cd32, 0x32cd32, 0x32cd32, 0x32cd32, 0x32cd32, 0x32cd32, 0x32cd32, 0x32cd32, 0x32cd32, 0x32cd32, 0x32cd32, 0x32cd32, 0x32cd32, 0x32cd32, 0x32cd32,
  0x32cd32, 0x32cd32, 0x32cd32, 0x32cd32, 0x32cd32, 0x32cd32, 0x32cd32, 0x32cd32, 0x32cd32, 0x32cd32, 0x32cd32, 0x32cd32, 0x32cd32, 0x32cd32, 0x32cd32, 0x32cd32,
  0x32cd32, 0x32cd32, 0x32cd32, 0x32cd32, 0x32cd32, 0x32cd32, 0x32cd32, 0x32cd32, 0x32cd32, 0x32cd32, 0x32cd32, 0x32cd32, 0x32cd32, 0x32cd32, 0x32cd32, 0x32cd32,
  0x32cd32, 0x32cd32, 0x32cd32, 0x32cd32, 0x32cd32, 0x32cd32, 0x32cd32, 0x32cd32, 0x32cd32, 0x32cd32, 0x32cd32, 0x32cd32, 0x32cd32, 0x32cd32, 0x32cd32, 0x32cd32

};
void playTone(int tone, int duration) {
  for (long i = 0; i < duration * 1000L; i += tone * 2) {
    digitalWrite(speakerPin, HIGH);
    delayMicroseconds(tone);
    digitalWrite(speakerPin, LOW);
    delayMicroseconds(tone);
  }
}
void playNote(char note, int duration) {
  char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
  int tones[] = { 956, 851, 758, 716, 638, 568, 1014, 478 };
  for (int i = 0; i < 8; i++) {
    if (names[i] == note) {
      playTone(tones[i], duration);
    }
  }
}
//

// Change the next 6 defines to match your matrix type and size

#define COLOR_ORDER    GRB
#define CHIPSET        WS2812B

#define MATRIX_WIDTH   16
#define MATRIX_HEIGHT  16
#define MATRIX_TYPE    HORIZONTAL_ZIGZAG_MATRIX

cLEDMatrix<MATRIX_WIDTH, MATRIX_HEIGHT, MATRIX_TYPE> leds;

cLEDText ScrollingMsg;

const unsigned char TxtDemo[] = { EFFECT_SCROLL_LEFT "            LEFT SCROLL "
                                  EFFECT_SCROLL_RIGHT "            LLORCS THGIR"
                                  EFFECT_SCROLL_DOWN "            SCROLL DOWN             SCROLL DOWN            " EFFECT_FRAME_RATE "\x04" " SCROLL DOWN            " EFFECT_FRAME_RATE "\x00" " "
                                  EFFECT_SCROLL_UP "             SCROLL UP               SCROLL UP             " EFFECT_FRAME_RATE "\x04" "  SCROLL UP             " EFFECT_FRAME_RATE "\x00" " "
                                  EFFECT_CHAR_UP EFFECT_SCROLL_LEFT "            UP"
                                  EFFECT_CHAR_RIGHT "  RIGHT"
                                  EFFECT_CHAR_DOWN "  DOWN"
                                  EFFECT_CHAR_LEFT "  LEFT"
                                  EFFECT_HSV_CV "\x00\xff\xff\x40\xff\xff" EFFECT_CHAR_UP "           HSV_CV 00-40"
                                  EFFECT_HSV_CH "\x00\xff\xff\x40\xff\xff" "    HSV_CH 00-40"
                                  EFFECT_HSV_AV "\x00\xff\xff\x40\xff\xff" "    HSV_AV 00-40"
                                  EFFECT_HSV_AH "\x00\xff\xff\xff\xff\xff" "    HSV_AH 00-FF"
                                  "           " EFFECT_HSV "\x00\xff\xff" "R" EFFECT_HSV "\x20\xff\xff" "A" EFFECT_HSV "\x40\xff\xff" "I" EFFECT_HSV "\x60\xff\xff" "N" EFFECT_HSV "\xe0\xff\xff" "B" EFFECT_HSV "\xc0\xff\xff" "O"
                                  EFFECT_HSV "\xa0\xff\xff" "W" EFFECT_HSV "\x80\xff\xff" "S " EFFECT_DELAY_FRAMES "\x00\x96" EFFECT_RGB "\xff\xff\xff" };
void setup() {
  pinMode(speakerPin, OUTPUT);
  FastLED.addLeds<NEOPIXEL, 2>(leds, 256);
  FastLED.setBrightness(15); //WiFi.begin("vighnesh","anish2012");
  FastLED.clear();

  delay(1000);

  for (int i = 0; i < 256; i++) {
    leds[i] = pgm_read_dword(&(flag[i]));
  }
  FastLED.show();
  delay(1000);
  FastLED.clear();
  FastLED.clear();
//  F
FastLED.showColor(CRGB::White);
  delay(1000);
  FastLED.show();

  ScrollingMsg.SetFont(MatriseFontData);
  ScrollingMsg.Init(&leds, leds.Width(), ScrollingMsg.FontHeight() + 1, 0, 0);
  ScrollingMsg.SetText((unsigned char *)TxtDemo, sizeof(TxtDemo) - 1);
  ScrollingMsg.SetTextColrOptions(COLR_RGB | COLR_SINGLE, 0xff, 0x00, 0xff);
}

void loop() {  //Main function
  for (int i = 0; i < length; i++) {
    if (notes[i] == ' ') {
      delay(beats[i] * tempo);
    } else {
      playNote(notes[i], beats[i] * tempo);
    }
    // pause between notes
    delay(tempo / 2);
  }

}
