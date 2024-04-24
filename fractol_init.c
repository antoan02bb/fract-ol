#include "include/fractol.h"

/**
 * @brief Initializes the fractal (both fractol and image structs)
*/
void init_fractol(t_fractol *fractal, double cx, double cy, char *name)
{        
    // Initialize the MLX library
    fractal->name = name;
    fractal->x = 0;
    fractal->y = 0;
    fractal->zx = 0;
    fractal->zy = 0;         //   
    fractal->cx = cx;        // real part of the complex number
    fractal->cy = cy;        // imaginary part of the complex number
    fractal->zoom = 1;       // zoom level of the fractal
    fractal->min_x = -2.0;
    fractal->max_x = 2.0;
    fractal->min_y = -2.0;
    fractal->max_y = 2.0;
    fractal->offset_x = 0;
    fractal->offset_y = 0;
    fractal->max_iterations = 100;
    fractal->color = 0;

}