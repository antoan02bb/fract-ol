#include "include/fractol.h"


/**
 * @brief The mandelbrot set lives within a specific set:
 *      x [-2..0.5] and y [-1..1]
 *      z = z^2 + c (both are complex numbers)
 *      z is initially (0, 0)
 *      c is the actual point
*/

void calculate_mandelbrot(t_fractol *fractal)
{

    int i;
    double x_temp;

    fractal->name = "Mandelbrot";
    i = 0;

    // set the z coordinates to 0
    fractal->zx = 0.0; // real part
    fractal->zy = 0.0; // imaginary part

    // set the c coorfinates to the current point
    fractal->cx = (fractal->x / fractal->zoom) + fractal->offset_x;
    fractal->cy = (fractal->y / fractal->zoom) + fractal->offset_y;

    while (++i < fractal->max_iterations)
    {
        // x_temp = zx^2 - zy^2 + cx
        x_temp = fractal->zx * fractal->zx - fractal->zy * fractal->zy + fractal->cx;

        // zy = 2 * zx * zy + cy
        fractal->zy = 2 * fractal->zx * fractal->zy + fractal->cy;

        // zx = x_temp
        fractal->zx = x_temp;

        // if the magnitude of z is greater than 2, then the point is not in the mandelbrot set
        if (fractal->zx * fractal->zx + fractal->zy * fractal->zy >= 4.0)
            break;
    }

    int color;
    if (i == fractal->max_iterations)
        color = 0x000000;
    else
        color = fractal->color * i;

    // Draw the pixel to the image
    mlx_put_pixel(fractal->img, fractal->x, fractal->y, color);
}