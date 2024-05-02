#include "include/fractol.h"

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

/**
 * @param x The x-coordinate of the point the user wants to zoom into
 * @param y The y_coordinate of the point the user wants to zoom into
*/
// void zoom(t_fractol *fractol, int x, int y, double zoom_factor)
// {
//     //fractol->zoom_factor = zoom_factor;

//     // 1. Declare variables for the coordinates of the mouse position
//     // репрезентират единични точки, не обхвати. 
//     double old_x_coord;
//     double old_y_coord;

//     // 2. Declare variables for the new range of x and y value after zooming
//     double new_x_range;
//     double new_y_range;

//     // 2. Calculate the current coordinates
//     old_x_coord = fractol->min_r + ((double)x / WIDTH) * (fractol->max_r - fractol->min_r); 
//     old_y_coord = fractol->min_i + (1 - (double)y / HEIGHT) * (fractol->max_i - fractol->min_i);

//     // 3. Caculate the new coordinates
//     new_x_range = (fractol->max_r - fractol->min_r) / zoom_factor;
//     new_y_range = (fractol->max_i - fractol->min_i) / zoom_factor;

//     // 4. Update the display ranges
//     fractol->min_r = old_x_coord - ((double)x / WIDTH) * new_x_range;
//     fractol->max_r = fractol->min_r + new_x_range; 
//     fractol->min_i = old_y_coord - ((double)y / HEIGHT) * new_y_range;
//     fractol->max_i = fractol->min_i + new_y_range;
// }

//from pixels to fractol's coordinates = mouse_pos : window_size 

/*
 * Callback function used to handle scrolling.
 * 
 * @param[in] xdelta The mouse x delta.
 * @param[in] ydelta The mouse y delta.
 * @param[in] param Additional parameter to pass on to the function.
 *
typedef void (*mlx_scrollfunc)(double xdelta, double ydelta, void* param)
*/