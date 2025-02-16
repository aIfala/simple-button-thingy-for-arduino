// butt is button for short (lmfao xDDDDDD

// demo goal: add 3 button at pin 8, 9, 10 (the another side of the button
//is connected to GND) that add 1, minus 0.5, and reset to 0.

// make an array to save details of our butts
unsigned int butt_pin_[] = {8, 9, 10}; // this is the pin number
//               butt id =  0, 1, 2

// just a random variable for demonstration
float x = 0;

// get how many butts did we add
int buttInit_arraySize = sizeof(butt_pin_)/sizeof(butt_pin_[0]);

void setup() {
  Serial.begin(9600);
  // FL stands for "for loop"
  for (int buttInit_FL_index = 0; buttInit_FL_index < buttInit_arraySize; buttInit_FL_index++) {
    // set the pinMode so we can do digitalRead() on the pin of our butts
    pinMode(butt_pin_[buttInit_FL_index], INPUT_PULLUP);
  }
}

void loop() {
  // check if butts are being pressed
  for (int buttCheck_FL_index = 0; buttCheck_FL_index < buttInit_arraySize; buttCheck_FL_index++) {
    checkButt(buttCheck_FL_index);
  }
  delay(10);
}

void checkButt(int butt_id) {
  long butt_t = -1; // for checking if this is the first moment pressing the butt
  // digitalRead it will output 0 when it is being pressed
  while (digitalRead(butt_pin_[butt_id]) == 0) {
    if (butt_t == -1) {
      doButtStuff(butt_id);
      butt_t = millis(); // set the time to now
    } else {
      // the time you need to hold for it to goes brrrrrrrrr
      if ((millis() - butt_t) > 750) {
        doButtStuff(butt_id);
        delay(50); // time between each loop
      }
    }
    // remove if you need high precision
    //its only to prevent some weird situations
    delay(1);
  }
}

void doButtStuff(int butt_id) {
  // add uses for your butts here
  switch (butt_id) {
    case 0:
      x += 1;
      Serial.println(x);
      break;
    case 1:
      x -= 0.5;
      Serial.println(x);
      break;
    case 2:
      x = 0;
      Serial.println(x);
      break;
  }
}