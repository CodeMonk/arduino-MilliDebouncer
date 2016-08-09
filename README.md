# arduino-MilliDebouncer

This tiny arduino library will debounce an intermittent signal, to make it more boolean.

I was trying to use the output of a turn signal light as the trigger for a device.  However, the singal was on
the wrong side of the flasher, so, it would turn off and on every half second or so.

This library allows you to read the noisy signal, and still treat the signal like a boolean.

# Prerequesites

This library depends on the [ElapsedMillis](http://playground.arduino.cc/Code/ElapsedMillis) library.  Please download
it before attempting to compile this library.

# Usage

After allocating a bouncer:

    #include <MilliDebouncer.h>
    
    MilliDebouncer input(A0, false, 1500, 1000);

You can then call getDebouncedState() to return a usable value:

    bool on = input.getDebouncedState();
    if (on) {
        doSomething();
    }

# Reference

This is a fairly simple library, with a constructor and a getter for the debounced state.  This section will
document the values of the constructor.


    MilliDebouncer(int pin, bool initial_state=false,
        int millis_to_reset=1000, double analog_threshold=0.1);

* pin - Specifies the pin you are reading from.  We assume an analog pin here, so, it will be analogRead()
* initial_state - true = initially on, false = initially off
* millis_to_reset - How many thousanths of a second have to pass before we count an "off" value.  For example: if You
    set this value to 1000, then, a signal would have to be below analog_threshold for an entire second before
    getDebouncedState() will return false
* analog_threshold - Analog values equal or above this are assumed to be "on". I've found 1000 works great for 5v,
    which returns 1023


# Examples

You will find an example in the examples directory, that should blink the led based on analog input 0.  Just 
connect a wire to A0, and move it between 5v and ground.  Note: I had to put the threshold pretty high -- a
floating input will float REALLY high.  Especially if you touch the contact.
