/*

   AnalogDebouncer.h - Library for debouncing a very slow analog
   signal.
   Created by David Frascone, August 8, 2016

   This was originally created to be able to use a signal from
   an automotive turn signal that bounced about twice a second.
*/

#ifndef AnalogDebouncer_h
#define AnalogDebouncer_h

#include <MilliDebouncer.h>

class AnalogDebouncer {
    private:
        MilliDebouncer _debouncer;          // Our debouncer
        int            _pin;                // Analog pin being read
        double         _analogThreshold;    // Values above the threshold are "true"

    public:
        AnalogDebouncer(int pin, bool initial_state=false,
                int millis_to_reset=1000, double analog_threshold=0.1);

        bool getDebouncedState();
};

#endif /* AnalogDebouncer_h */
