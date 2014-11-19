
/*
Bluetooth morse code keyboard
http://zunkworks.com/BluetoothMorseKeyboard
 */

#include <avr/pgmspace.h>
#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>

#include "morsekeyboardconfig.h"

 
//standard Arduino code starts here:
int led_pin = 13;
int dit_pin = 22;
int dah_pin = 23;
int audio_pin = 20;

unsigned int sidetone = 650; //in Hz


float wpm = 25.0; //set the speed here in words per min

float dit_time = 1200.0/(wpm); //dit time is in microseconds
unsigned long codestarttime;
byte state = 0; //0=idle 1=dit 2=dah 3 = ditdah
byte prev_state = 0;
byte ind = 0;

String code = String();
int i = 0;



// GUItool: begin automatically generated code
AudioSynthWaveformSine   sine1;          //xy=111,225
AudioEffectEnvelope      envelope1;      //xy=255,225
AudioOutputAnalog        dac1;           //xy=393,225
AudioConnection          patchCord1(sine1, envelope1);
AudioConnection          patchCord2(envelope1, dac1);
// GUItool: end automatically generated code


void setup() {                
  AudioMemory(12);
  // initialize the digital pin as an output.
  // Pin 13 has an LED connected on most Arduino boards:
  pinMode(led_pin, OUTPUT);     
  pinMode(dit_pin, INPUT_PULLUP);
  pinMode(dah_pin, INPUT_PULLUP);
  analogWriteResolution(12);
  
  Serial.begin(115200);
  
  //Delays for 15 seconds blinking LED. To allow for starting of debug terminal
//  for (int i=0; i < 15; i++) {
//    digitalWrite(led_pin, HIGH);
//    delay(500);
//    digitalWrite(led_pin, LOW);
//    delay(500);
//  }
 
  Serial.println("HELLO");
  //Serial.println(dit_time);
//  if (ind){
//    //configures the WT12, security is set to lowest possible which requires no user interaction
//    Serial.println("set profile hid on");
//    Serial.println("reset");
//
//    Serial.println("set bt class 00540");
//    Serial.println("set bt ssp 3 0");
//    Serial.println("set bt auth * 0000");
//    Serial.println("reset");
//    ind = 1;
//  }


  sine1.amplitude(1.0);
  sine1.frequency(650);
  envelope1.attack(1.5);
  envelope1.hold(0);
  envelope1.decay(0);
  envelope1.sustain(1.0);
  envelope1.release(1.5);
}



void loop() {
  boolean dit = digitalRead(dit_pin);
  boolean dah = digitalRead(dah_pin);
  prev_state = state;  
  
  if ( dit != dah){
   
    if (dit == LOW){ 
      digitalWrite(13, HIGH);   // set the LED on
      tone(audio_pin,sidetone);
      envelope1.noteOn();
      delay(dit_time); 
      digitalWrite(13, LOW);
      noTone(audio_pin);
      envelope1.noteOff();
      delay(dit_time);
      state = 1;
      code = code + ".";
      Serial.print(".");
    }
    if (dah == LOW){ 
     digitalWrite(13, HIGH);   // set the LED on
     tone(audio_pin,sidetone);
     envelope1.noteOn();
     delay(dit_time*3); 
     digitalWrite(13, LOW);
     noTone(audio_pin);
     envelope1.noteOff();
     delay(dit_time);
     state = 2;
     code = code + "-";
     Serial.print("-");
    }
  } else if (dah == LOW){ //iambic function
      digitalWrite(13, HIGH);   // set the LED on
      tone(audio_pin,sidetone);
      envelope1.noteOn();
      delay(dit_time); 
      digitalWrite(13, LOW);
      noTone(audio_pin);
      envelope1.noteOff();
      delay(dit_time);
      digitalWrite(13, HIGH);   // set the LED on
      tone(audio_pin,sidetone);
      envelope1.noteOn();
      delay(dit_time*3); 
      digitalWrite(13, LOW);
      noTone(audio_pin);
      envelope1.noteOff();
      delay(dit_time);
      state = 3;
      code = code + ".-";
      Serial.print(".-");
  } else {
    if (state != 0){
    state = 0;
    codestarttime = millis();
    }
  }
  //this bit is tricky
  if ((millis()-codestarttime > dit_time*3) && (code != "") && (state == 0)){ //if we reached character time-out then search for a match
    //Serial.println(code);
    char buffer[16];
    char code_num;
    char found = 0;
      for (code_num = 0 ; code_num < 58  ; code_num++) { //search for a code match
        strcpy_P(&buffer[0], (char *)pgm_read_word(&(morse_table[code_num])));
        if (code == &buffer[0]) {
          found = 1;
          break;
        }
      }

  if (found == 1){
    Keyboard.print(char(pgm_read_byte_near(morse_chars + code_num)));
    Serial.print(pgm_read_byte_near(morse_chars + code_num));
  } else {
    Serial.println("???");
  }
  
    code = "";
  }
  
}



























