

#include "AXS15231B.h"
#include <Arduino.h>
#include <TFT_eSPI.h>
// For bitmap encoding: use Image2lcd, 16bit true colour, MSB First, RGB565, don't include head data, be sure to set max image size, save as .h file.

TFT_eSPI tft = TFT_eSPI();
TFT_eSprite sprite = TFT_eSprite(&tft);


void draw()
{
 sprite.fillSprite(TFT_CYAN);
 sprite.setTextColor(TFT_NAVY, TFT_CYAN );
 sprite.drawString("YO2LDK OP. ALEX KN05WH",160,20,4);
 sprite.fillRect(210,100,60,60,TFT_BLUE);
 sprite.fillRect(280,100,60,60,TFT_YELLOW);
 sprite.fillRect(350,100,60,60,TFT_RED);


 
 lcd_PushColors_rotated_90(0, 0, 640, 180, (uint16_t*)sprite.getPointer());
}

    
void setup() {
    pinMode(TFT_BL, OUTPUT);
    digitalWrite(TFT_BL, LOW);        // turn off backlight asap to minimise power on artifacts
    Serial.begin(115200); 
    axs15231_init();
    //lcd_setRotation(2);             // 180 degree hardware rotate if you want reset / boot buttons at the bottom
    sprite.createSprite(640, 180);    // full screen landscape sprite in psram
    sprite.setSwapBytes(1);
    lcd_fill(0,0,180,640,0x00);       // clear screen
    digitalWrite(TFT_BL, HIGH);       // turn on backlight
}


void loop() {     

    draw();
    delay(4000);

    sprite.fillSprite(TFT_CYAN);
    lcd_PushColors_rotated_90(0, 0, 640, 180, (uint16_t*)sprite.getPointer());
    delay(500);

    sprite.fillSprite(TFT_ORANGE);
    lcd_PushColors_rotated_90(0, 0, 640, 180, (uint16_t*)sprite.getPointer());
    delay(500);
    
    sprite.fillSprite(TFT_VIOLET);
    lcd_PushColors_rotated_90(0, 0, 640, 180, (uint16_t*)sprite.getPointer()); 
    delay(500);
    
    check_for_memory_leaks();
 }


void check_for_memory_leaks() {

    Serial.print(F("Total heap  ")); Serial.println(ESP.getHeapSize());
    Serial.print(F("Free heap   ")); Serial.println(ESP.getFreeHeap());
    Serial.print(F("Total psram ")); Serial.println(ESP.getPsramSize());
    Serial.print(F("Free psram  ")); Serial.println(ESP.getFreePsram());
}
