#include <MilliDebouncer.h>
#include <DigitalDebouncer.h>
#include <AnalogDebouncer.h>

void setup() {
    MilliDebouncer milli();
    AnalogDebouncer  analog(A0);
    DigitalDebouncer  digital(13);
}

void loop() {
}
