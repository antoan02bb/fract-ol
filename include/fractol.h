#ifndef FRACTOL_H
# define FRACTOL_H

#include "../MLX42/include/MLX42/MLX42.h"
#include <math.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

// Colors
#define COLOR_BLACK     BlackPixel(display, screen)   // Represents the color black
#define COLOR_WHITE     WhitePixel(display, screen)   // Represents the color white

// Window size
#define WIDTH 800
#define HEIGHT 800


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

    double zoom;

    double min_x;
    double max_x;
    double min_y;
    double max_y;

    double offset_x; // x offset is the distance from the left side of the screen to the left side of the fractal
    double offset_y; // y offset is the distance from the top of the screen to the top of the fractal

    int max_iterations;

    // color variable
    int color;

}               t_fractol;

// fractols
void calculate_mandelbrot(t_fractol *fractal);
void calculate_julia(t_fractol *fractal, double cx, double cy);

// fractol.c
void create_image(t_fractol *fractal);
void display_image(t_fractol *fractal);
int draw_fractal_pixels(t_fractol *fractal, char *str, double cx, double cy);
int draw_fractal(char **args);


// init_fractol.c
void init_fractol(t_fractol *fractal, double cx, double cy, char *name);

#endif