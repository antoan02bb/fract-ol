#include "fractol.h"

void fractal_init(t_fractal *fractal)   
{
    // 1. initialize mlx_connection
    fractal->mlx_connection = mlx_init();

    // check mlx_connection
    if (fractal->mlx_connection == NULL)
        malloc_error();

    // 2. initialize mlx_window
    fractal->mlx_window = mlx_new_window(fractal->mlx_connection,
                                        WIDTH,
                                        HEIGHT,
                                        fractal->name);

    // check mlx_window
    if (fractal->mlx_window == NULL)
    {
        mlx_destroy_display(fractal->mlx_connection);
        free(fractal->mlx_connection);
    }

    // 3. creating new image
    fractal->image.addr = mlx_new_image(fractal->mlx_connection, WIDTH, HEIGHT);

    // check image addres
    if (fractal->image.addr == NULL)
    {
        mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
        mlx_destroy_display(fractal->mlx_connection);
        free(fractal->mlx_connection);
    }

    // 4. fractal image pixels
    fractal->image.bits_per_pixel = mlx_get_data_addr(fractal->mlx_connection,
                                                        t_image.)

    // useful when you need to access or manipulate pixel data within an image
}