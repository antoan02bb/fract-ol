#include "include/fractol.h"

// typedef void (*mlx_keyfunc)(mlx_key_data_t keydata, void *param)

void key_handler(mlx_key_data_t keydata, void *param)
{
    t_fractol *fractol;

    fractol = (t_fractol *)param;
    // If we press the ESC key, we close the window
    if (keydata.key == MLX_KEY_ESCAPE)
    {
        mlx_close_window(fractol->mlx);
        printf("Window closed\n");
    }

    // mlx_close_hook(fractol->mlx);
    // printf("Window closed manualy\n");

}