#include "include/fractol.h"

/**
 * @brief Initializes the fractal (both fractol and image structs)
*/
void init_fractol(t_fractol *fractol)
{        
    // Initialize the MLX library
    // fractal->name;
    // fractal->x;
    // fractal->y;
    // fractal->zx;
    // fractal->zy;           
    // fractal->cx;            // real part of the complex number
    // fractal->cy;            // imaginary part of the complex number
    // fractal->zoom;          // zoom level of the fractal
 
    // fractal->offset_x;
    // fractal->offset_y;
    // fractal->max_iterations;
    // fractal->color;
    
    fractol->min_r = -2.0;
    fractol->max_r = 2.0;
    fractol->min_i = -2.0;
    fractol->max_i = 2.0;
    fractol->x = 0;
	fractol->y = 0;
	fractol->zoom = 1; // This will cover the range [-2.0, 0.5] over the width of the image
    // fractol->zoom_factor = 1.2;

    // color is purple
    fractol->color = 0x800080;

}

// static void events_init(t_fractol *fractol)
// {
//     mlx_scroll_hook(fractol->mlx, mouse_handler, fractol);
// }