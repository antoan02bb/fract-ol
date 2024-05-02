#include "include/fractol.h"

void calculate_julia(t_fractol *fractal, double cx, double cy)
{
    int i;
    double temp;

    fractal->name = "julia";
    i = 0;

    // fractal->zx = 0.0;
    // fractal->zy = 0.0;

    // set the c coordinates to the current point
    fractal->cx = cx;
    fractal->cy = cy; 
    
    // // set the z coordinates to the current point
    // fractal->zx = (fractal->min_r + (fractal->max_r - fractal->min_r) * (fractal->x) / WIDTH);
    // fractal->zy = (fractal->max_i - (fractal->max_i - fractal->min_i) * (fractal->y) / HEIGHT);

    fractal->zx = fractal->min_r + (fractal->max_r - fractal->min_r) * (fractal->x) / WIDTH;
    fractal->zy = fractal->min_i + (fractal->max_i - fractal->min_i) * (fractal->y) / HEIGHT;

    while (i < MAX_ITERATIONS)
    {
        if (fractal->zx * fractal->zx + fractal->zy * fractal->zy > 4.0)
            break;

        temp = 2 * fractal->zx * fractal->zy + fractal->cyj;

        fractal->zx = fractal->zx * fractal->zx - fractal->zy * fractal->zy + fractal->cxj;

        fractal->zy = temp;

        i++;
    }

//     int julia(t_fractol *f)
// {
//     int     n;
//     double  temp;
//     n = 0;
//     while (n < f->max_iter && ((f->cy * f->cy + f->cx * f->cx) < 4.0))
//     {
//         temp = 2 * f->cx * f->cy + f->j_cy;
//         f->cx = f->cx * f->cx - f->cy * f->cy + f->j_cx;
//         f->cy = temp;
//         n++;
//     }
// }

    int color;
    if (i == MAX_ITERATIONS)
        // green
        color = 0x0000AAFF;
    else
        color = 0x0000FFFF; //get_color(i);

    // Draw the pixel to the image
    mlx_put_pixel(fractal->img, fractal->x, fractal->y, color);
}