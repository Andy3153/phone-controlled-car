// vim: set fenc=utf-8 ts=4 sw=0 sts=0 sr et si tw=0 fdm=marker fmr={{{,}}}:

// {{{ Libraries
#include <L298NX2.h> // motor driver module
// }}}

// {{{ Variables
// {{{ Declare pins
const int IN1 = 2,
          IN2 = 3,
          IN3 = 4,
          IN4 = 5;
// }}}

// {{{ Declare motors on the L298N
L298NX2 motors(IN1, IN2, IN3, IN4);
// }}}

// {{{ Bluetooth state
int state;
// }}}
// }}}

// {{{ Setup
void setup()
{
    // {{{ Set pin modes
    // For the L298N inputs
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
    // }}}

    // {{{ Initialize serial communication
    Serial.begin(9600);
    // }}}
}
// }}}

// {{{ Loop
void loop()
{
    if(Serial.available() > 0) state = Serial.read(); // save the state into a varable

    switch(state)
    {
        // {{{ Move forward
        case 'N':
            motors.forward();
            break;
        // }}}

        // {{{ Move backward
        case 'S':
            motors.backward();
            break;
        // }}}

        // {{{ Rotate right
        case 'E':
            motors.forwardA();
            motors.backwardB();
            break;
        // }}}

        // {{{ Rotate left
        case 'W':
            motors.backwardA();
            motors.forwardB();
            break;
        // }}}

        // {{{ Stop motors
        case '0':
            motors.stop();
            break;
        // }}}
    }
}
// }}}
