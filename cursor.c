#include "include/fractol.h"

void cursor_handler(double x, double y, void *param)
{
    t_fractol *fractol;

    fractol = (t_fractol *)param;
    printf("cursor position is: (%f, %f)\n", x, y);
}