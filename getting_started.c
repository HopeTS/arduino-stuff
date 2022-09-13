#include <avr/io.h>
#include <util/delay.h>

// Reference code from https://www.youtube.com/watch?v=j4xw8QomkXs
// Gotta look into 'bitwise math'

int main(void)
{
    // set PORTB5 as an output (0 = input, 1 = output)
    DDRB = DDRB | (1 << DDB5);

    while (1)
    {
        // set PORTB5
        PORTB = PORTB | (1 << PORTB5);

        // wait
        _delay_ms(1000);

        // unset PORTB5 (1's compliment, opposite of the set equation)
        PORTB = PORTB & ~(1 << PORTB5);

        // wait again
        _delay_ms(1000)
    }
}