#include "include/fractol.h"

void calculate_julia(t_fractol *fractal, double cx, double cy)
{
    int i;
    double temp;

    fractal->name = "Julia";

    // before calculate Julia had 3 arguments but i changed it
    // now this need to be fixed
    fractal->cx = cx;
    fractal->cy = cy; 

    i = 0;

    // set the z coordinates to the current point
    fractal->zx = (fractal->x / fractal->zoom) + fractal->offset_x;
    fractal->zy = (fractal->y / fractal->zoom) + fractal->offset_y;

    while (++i < fractal->max_iterations)
    {
        // temp = zx
        temp = fractal->zx;

        // zx = zx^2 - zy^2 + cx
        fractal->zx = fractal->zx * fractal->zx - fractal->zy * fractal->zy + fractal->cx;

        // zy = 2 * zx * zy + cy
        fractal->zy = 2 * fractal->zy * temp + fractal->cy;

        // if the magnitude of z is greater than 2, then the point is not in the mandelbrot set
        if (fractal->zx * fractal->zx + fractal->zy * fractal->zy >= 4.0)
            break;
    }

    int color;

    // if the point is in the julia set, color it green
    if (i == fractal->max_iterations)
        color = 0x00FF00;
    else
        color = fractal->color * i;

    // Draw the pixel to the image
    mlx_put_pixel(fractal->img, fractal->x, fractal->y, color);
}