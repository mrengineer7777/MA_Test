




#ifdef ARDUINO
#include <Arduino.h>

void setup() {
    Serial.begin(115200);
    delay(2000);    //Wait for USB connection to stabilize
}

void loop() {

}

#else

int main( int argc, char **argv) {
    runtests();
    return 0;
}

#endif