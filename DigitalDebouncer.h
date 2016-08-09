/*

   DigitalDebouncer.h - Library for debouncing a very slow analog
   signal.
   Created by David Frascone, August 8, 2016

   This was originally created to be able to use a signal from
   an automotive turn signal that bounced about twice a second.
*/

#ifndef DigitalDebouncer_h
#define DigitalDebouncer_h

#include <MilliDebouncer.h>

class DigitalDebouncer {
    private:
        MilliDebouncer _debouncer;          // Our debouncer
        int            _pin;                // Digital pin being read

    public:
        DigitalDebouncer(int pin, bool initial_state=false,
                unsigned millis_to_reset=1000);

        bool getDebouncedState();
};

#endif /* DigitalDebouncer_h */
