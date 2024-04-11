#include "fractol.h"

/**
 * @brief The mandelbrot set lives within a specific set:
 *      x [-2..0.5]*
 *      y [-1..1]*
 * 
 *      z = z^2 + c (both are complex numbers)
 *      z is initially (0, 0)
 *      c is the actual point
*/

void handle_pixel(int x, int y, t_fractal *fractal)
{
    t_complex z;
    t_complex c;

    // first iteration
    z.x = 0.0;
    z.y = 0.0;

    // pixel coordinates x and y scaled to fit mandelbrot range
    c.x = map(x, -2, +2, 0, WIDTH);
    c.y = map(y, +2, -2, 0, HEIGHT);

    // - Now we have to iterate these numbers, to check if they escape to infinity or stay bounded.
    // - How many times do we iterate z^2 + c to check if the pointer escaped?
    while (?????)
    {
        // actual z^2 + c
        // the reason we use z is because it's a convetion and represents complex numbers
        z = complex_sum(complex_square(z), c); //TODO: implement complex_square and complex_sum


        // Did the value escape/
        if (????)
        {

        }
    }
    
}

/**
 * @brief How to scale down a range of numbers with a known min and max value
*/
void fractal_render(t_fractal fractal)
{
    int x;
    int y;
}