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
  '$', '@', 0x8, 0xa, 0x9, ' '
};

//const char morse_chars[] PROGMEM = {
//  KEY_A, KEY_B, KEY_C, KEY_D, KEY_E, KEY_F, KEY_G, KEY_H, KEY_I, KEY_J, KEY_K, KEY_L, KEY_M, 
//  KEY_N, KEY_O, KEY_P, KEY_Q, KEY_R, KEY_S, KEY_T, KEY_U, KEY_V, KEY_W, KEY_X, KEY_Y, KEY_Z, 
//  KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_0,
//};


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
const char morse_BACKSPACE[] PROGMEM = "----";
const char morse_RETURN[] PROGMEM = "-.-.-";
const char morse_TAB[] PROGMEM = "...-.-";
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

        morse_BACKSPACE,
        morse_RETURN,
        morse_TAB,
        morse_SPACE
};
