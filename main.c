#include "fractol.h"

int main(int argc, char **argv)
{
    t_fractal fractal;

    // Conditions evaluate to either true or false
    if (argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10)
        || argc == 4 && ft_strncmp(argv[1], "julia", 5))
    {
        fractal.name = argv[1];

        



        //
        fractal_init(&fractal);

        fractal_render(&fractal);


    }
    
    
}