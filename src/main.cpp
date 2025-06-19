#include <Arduino.h>
#include <BleKeyboard.h>
#include "ControllerManager.h"
#include "config.h" // realmente necessário?

BleKeyboard bleKeyboard;


void setup() {
  Serial.begin(115200);
  Serial.println("Starting BLE work!");
  bleKeyboard.begin();

  ControlerBegin();

  // pinMode(2,OUTPUT);
}

void loop() {

  if(bleKeyboard.isConnected()) {
        if (buttonManager.isPressed(0)) { // 0 é o índice do botão UP (PIN_UP)
        bleKeyboard.print("Hello world");
        // bleKeyboard.write(KEY_LEFT_ARROW);
        // digitalWrite(2,HIGH);
        }
    
    // delay(100);
    // Serial.println("Sending Enter key...");
    // bleKeyboard.write(KEY_RETURN);

    // delay(1000);

    // Serial.println("Sending Play/Pause media key...");
    // bleKeyboard.write(KEY_MEDIA_PLAY_PAUSE);

    // delay(1000);
    
   //
   // Below is an example of pressing multiple keyboard modifiers 
   // which by default is commented out. 
   // 
   /* Serial.println("Sending Ctrl+Alt+Delete...");
    bleKeyboard.press(KEY_LEFT_CTRL);
    bleKeyboard.press(KEY_LEFT_ALT);
    bleKeyboard.press(KEY_DELETE);
    delay(100);
    bleKeyboard.releaseAll();
    */

  }
  delay(20);


  // getControlerData();


  // if(bleKeyboard.isConnected()) {
  //   Serial.println("Sending 'Hello world'...");

    
  //   if (buttonManager.isPressed(0)) { // 0 é o índice do botão UP (PIN_UP)
  //       Serial.println("Botão Pressionado!");
  //       digitalWrite(2,HIGH);
  //       bleKeyboard.write(KEY_LEFT_ARROW);
  //   }

  //   if (buttonManager.isPressed(1)) { // 1 é o índice do botão DOWN (PIN_DOWN)
  //       Serial.println("Botão Pressionado!");
  //       digitalWrite(2,LOW);
  //       bleKeyboard.write(KEY_DOWN_ARROW);
  //   }

  //   if (buttonManager.isPressed(2)) { // 2 é o índice do botão LEFT (PIN_LEFT)
  //       Serial.println("Botão Pressionado!");
  //       bleKeyboard.write(KEY_LEFT_ARROW);
  //   }

  //   if (buttonManager.isPressed(3)) { // 3 é o índice do botão RIGHT (PIN_RIGHT)
  //       Serial.println("Botão Pressionado!");
  //       bleKeyboard.write(KEY_UP_ARROW);
  //   }
    

  // } 
  // delay(50);
}