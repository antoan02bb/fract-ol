#ifndef FRACTOL_H
# define FRACTOL_H

#include "../MLX42/include/MLX42/MLX42.h"
#include <math.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <math.h>

// Window size
#define WIDTH 1000
#define HEIGHT 1000
#define MAX_ITERATIONS 50


// Image structure

/**
 * @param x - the real part of the complex number
 * @param y - the imaginary part of the complex number
*/
typedef struct s_fractol
{
    mlx_t           *mlx;
    mlx_image_t     *img;

    char    *name;

    int  x; // real part of the complex number
    int  y; // imaginary part of the complex number

    double zx; // real part
    double zy; // imaginary part

    double cx; // real part
    double cy; // imaginary part

    double cxj;
    double cyj;

    double zoom;

    double zoomCenterX;
    double zoomCenterY;

    // range of real nums
    double min_r; 
    double max_r;

    // range of imag nums
    double min_i;
    double max_i;

    double offset_x; // x offset is the distance from the left side of the screen to the left side of the fractal
    double offset_y; // y offset is the distance from the top of the screen to the top of the fractal

    int max_iterations;

    // color variable
    int color;

    double zoom_factor;

}               t_fractol;

// fractols
void calculate_mandelbrot(t_fractol *fractal);
void calculate_julia(t_fractol *fractal, double cx, double cy);

// fractol.c
void    create_image(t_fractol *fractal);
void    display_image(t_fractol *fractal);
int     draw_fractal_pixels(t_fractol *fractal, char *str, double cx, double cy);
int     draw_fractal(t_fractol *fractal, char *input, double cx, double cy);
void    init_fractol(t_fractol *fractol);


// mouse.c
void zoom(t_fractol *fractol, int x, int y, double zoom_factor);
void mouse_handler(double delta_x, double delta_y, void *param);

void key_handler(mlx_key_data_t keydata, void *param);

//int get_color(int i);

int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a);

#endif