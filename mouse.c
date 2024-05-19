#include "include/fractol.h"

/**
 * @param x - the x coordinate of the mouse
 * @param y - the y coordinate of the mouse
 * @brief I remove fractol as argument because mlx_scroll_hoot takes a void * instead
*/
/**
 * @param x - the x coordinate of the mouse
 * @param y - the y coordinate of the mouse
 * @brief I remove fractol as argument because mlx_scroll_hoot takes a void * instead
*/
void mouse_handler(double delta_x, double delta_y, void *param)
{
    // mlx_get_mouse_pos needs to take int32_t as arguments
    // int32_t x;
    // int32_t y;
    t_fractol *fractol;

    (void)delta_x; // unused
    fractol = (t_fractol *)param;

    double zoom_factor = 1.1;
    //mlx_get_mouse_pos(fractol->mlx, &x, &y);


    // if the mouse is moving up
    if (delta_y < 0 )
        //zoom(fractol, x, y, fractol->zoom_factor);
        fractol->zoom *= zoom_factor;

    // if the mouse is moving down 
    else if (delta_y > 0 )
        //zoom(fractol, x, y, 1 / fractol->zoom_factor);
        fractol->zoom /= zoom_factor;
        
    // refresh
    draw_fractal(fractol, fractol->name, fractol->cx, fractol->cy);
}
