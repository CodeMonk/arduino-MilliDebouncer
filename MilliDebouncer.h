/*

   MilliDebouncer.h - Library for debouncing a very slow signal.
   Created by David Frascone, August 8, 2016

   This was originally created to be able to use a signal from
   an automotive turn signal that bounced about twice a second.
*/

#ifndef MilliDebouncer_h
#define MilliDebouncer_h

#include <elapsedMillis.h>

class MilliDebouncer {
    private:
        int            _pin;                // Analog pin being read
        bool           _prev;               // if true, pin was on the last read
        elapsedMillis  _elapsed;            // Number of ticks we've been off for
        int            _millisToReset;      // Number of ticks to call the signal off
        double         _analogThreshold;    // Values above the threshold are "true"

    public:
        MilliDebouncer(int pin, bool initial_state=false,
                int millis_to_reset=1000, double analog_threshold=0.1);

        bool getDebouncedState();
};

#endif /* MilliDebouncer_h */
