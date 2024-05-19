#include "include/fractol.h"

int get_color(unsigned int i)
{
    int r = (int)(127.5 * (1 + sin(0.03 * i + 4)));
    int g = (int)(127.5 * (1 + sin(0.02 * i + 2)));
    int b = (int)(127.5 * (1 + sin(0.01 * i)));
    int a = 255;

    //return (r << 16) | (g << 8) | b;
    return ft_pixel(r, g, b, a);
}