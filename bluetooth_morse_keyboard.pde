/*
Bluetooth morse code keyboard
http://zunkworks.com/BluetoothMorseKeyboard
 */

 #include <avr/pgmspace.h>

//Characters we can type over bluetooth kbd
//change this section to modifiy the morse-code to keyboard/mouse controls
//you'll also need to change the next two sections as well since all 3 work together.
//elements in each section need to be in order with eachother, i.e. order of section 1 must match order of section 2 and 3


 const char morse_chars[] PROGMEM = {
  'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h',
  'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
  'q', 'r', 's', 't', 'u', 'v', 'w', 'x',
  'y', 'z',
  '0', '1', '2', '3', '4', '5', '6', '7',
  '8', '9',
  '.', ',', '?', '\'', '!', '/', '(', ')',
  '&', ':', ';', '=', '+', '-', '_', '"',
  '$', '@', 0x8, 0xa, 0xa, ' '
};


//Morse codes
const char morse_A[] PROGMEM = ".-";
const char morse_B[] PROGMEM = "-...";
const char morse_C[] PROGMEM = "-.-.";
const char morse_D[] PROGMEM = "-..";
const char morse_E[] PROGMEM = ".";
const char morse_F[] PROGMEM = "..-.";
const char morse_G[] PROGMEM = "--.";
const char morse_H[] PROGMEM = "....";
const char morse_I[] PROGMEM = "..";
const char morse_J[] PROGMEM = ".---";
const char morse_K[] PROGMEM = "-.-";
const char morse_L[] PROGMEM = ".-..";
const char morse_M[] PROGMEM = "--";
const char morse_N[] PROGMEM = "-.";
const char morse_O[] PROGMEM = "---";
const char morse_P[] PROGMEM = ".--.";
const char morse_Q[] PROGMEM = "--.-";
const char morse_R[] PROGMEM = ".-.";
const char morse_S[] PROGMEM = "...";
const char morse_T[] PROGMEM = "-";
const char morse_U[] PROGMEM = "..-";
const char morse_V[] PROGMEM = "...-";
const char morse_W[] PROGMEM = ".--";
const char morse_X[] PROGMEM = "-..-";
const char morse_Y[] PROGMEM = "-.--";
const char morse_Z[] PROGMEM = "--..";
const char morse_0[] PROGMEM = "-----";
const char morse_1[] PROGMEM = ".----";
const char morse_2[] PROGMEM = "..---";
const char morse_3[] PROGMEM = "...--";
const char morse_4[] PROGMEM = "....-";
const char morse_5[] PROGMEM = ".....";
const char morse_6[] PROGMEM = "-....";
const char morse_7[] PROGMEM = "--...";
const char morse_8[] PROGMEM = "---..";
const char morse_9[] PROGMEM = "----.";
const char morse_PERIOD[] PROGMEM = ".-.-.-";
const char morse_COMMA[] PROGMEM = "--..--";
const char morse_QUESTION[] PROGMEM = "..--..";
const char morse_APOSTROPHE[] PROGMEM = ".----.";
const char morse_EXCLAMATION[] PROGMEM = "-.-.--";
const char morse_SLASH[] PROGMEM = "-..-.";
const char morse_PARENO[] PROGMEM = "-.--.";
const char morse_PARENC[] PROGMEM = "-.--.-";
const char morse_AMPER[] PROGMEM = ".-...";
const char morse_COLON[] PROGMEM = "---...";
const char morse_SEMICOLON[] PROGMEM = "-.-.-.";
const char morse_EQUALS[] PROGMEM = "-...-";
const char morse_PLUS[] PROGMEM = ".-.-.";
const char morse_MINUS[] PROGMEM = "-....-";
const char morse_UNDER[] PROGMEM = "..--.-";
const char morse_QUOTE[] PROGMEM = ".-..-.";
const char morse_DOLLAR[] PROGMEM = "...-..-";
const char morse_AT[] PROGMEM = ".--.-.";
const char morse_ERROR[] PROGMEM = "----";
const char morse_START[] PROGMEM = "-.-.-";
const char morse_END[] PROGMEM = "...-.-";
const char morse_SPACE[] PROGMEM = "..--";

//lookup table of morse codes, above gets stored in this array
const char *morse_table[] PROGMEM = {
        morse_A,
        morse_B,
        morse_C,
        morse_D,
        morse_E,
        morse_F,
        morse_G,
        morse_H,
        morse_I,
        morse_J,
        morse_K,
        morse_L,
        morse_M,
        morse_N,
        morse_O,
        morse_P,
        morse_Q,
        morse_R,
        morse_S,
        morse_T,
        morse_U,
        morse_V,
        morse_W,
        morse_X,
        morse_Y,
        morse_Z,
        morse_0,
        morse_1,
        morse_2,
        morse_3,
        morse_4,
        morse_5,
        morse_6,
        morse_7,
        morse_8,
        morse_9,

        morse_PERIOD,
        morse_COMMA,
        morse_QUESTION,
        morse_APOSTROPHE,
        morse_EXCLAMATION,
        morse_SLASH,
        morse_PARENO,
        morse_PARENC,
        morse_AMPER,
        morse_COLON,
        morse_SEMICOLON,
        morse_EQUALS,
        morse_PLUS,
        morse_MINUS,
        morse_UNDER,
        morse_QUOTE,
        morse_DOLLAR,
        morse_AT,

        morse_ERROR,
        morse_START,
        morse_END,
        morse_SPACE
};
 
 
//standard Arduino code starts here:

int dit_pin = 8;
int dah_pin = 5;

float wpm = 15.0; //set the speed here in words per min

float dit_time = 1200.0/(wpm); //dit time is in microseconds
unsigned long codestarttime;
byte state = 0; //0=idle 1=dit 2=dah 3 = ditdah
byte prev_state = 0;
byte ind = 0;

String code = String();
int i = 0;


void setup() {                
  // initialize the digital pin as an output.
  // Pin 13 has an LED connected on most Arduino boards:
  pinMode(13, OUTPUT);     
  pinMode(dit_pin, INPUT);
  pinMode(dah_pin, INPUT);
  Serial.begin(115200);
  //Serial.println("HELLO");
  //Serial.println(dit_time);
  if (ind){
    //configures the WT12, security is set to lowest possible which requires no user interaction
    Serial.println("set profile hid on");
    Serial.println("reset");

    Serial.println("set bt class 00540");
    Serial.println("set bt ssp 3 0");
    Serial.println("set bt auth * 0000");
    Serial.println("reset");
    ind = 1;
  }
}



void loop() {
  boolean dit = digitalRead(dit_pin);
  boolean dah = digitalRead(dah_pin);
  prev_state = state;  
  
  if ( dit != dah){d
   
    if (dit == HIGH){ 
      digitalWrite(13, HIGH);   // set the LED on
      delay(dit_time); 
      digitalWrite(13, LOW);
      delay(dit_time);
      state = 1;
      code = code + ".";
    }
    if (dah == HIGH){ 
     digitalWrite(13, HIGH);   // set the LED on
     delay(dit_time*3); 
     digitalWrite(13, LOW);
     delay(dit_time);
     state = 2;
     code = code + "-";
    }
  } else if (dah == HIGH){ //iambic function
      digitalWrite(13, HIGH);   // set the LED on
      delay(dit_time); 
      digitalWrite(13, LOW);
      delay(dit_time);
      digitalWrite(13, HIGH);   // set the LED on
      delay(dit_time*3); 
      digitalWrite(13, LOW);
      delay(dit_time);
      state = 3;
      code = code + ".-";
  } else {
    if (state != 0){
    state = 0;
    codestarttime = millis();
    }
  }
  //this bit is tricky
  if ((millis()-codestarttime > dit_time*3) && (code != "") && (state == 0)){
    //Serial.println(code);
    char buffer[16];
    char code_num;
    char found = 0;
      for (code_num = 0 ; code_num < 64  ; code_num++) {
        strcpy_P(&buffer[0], (char *)pgm_read_word(&(morse_table[code_num])));
        if (code== &buffer[0]) {
          found = 1;
          break;
        }
      }

  if (found ==1){
    Serial.print(pgm_read_byte_near(morse_chars + code_num));
  } else {
    Serial.print("???");
  }
  
    code = "";
  }
  
}
