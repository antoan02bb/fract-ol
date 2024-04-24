#include "include/fractol.h"
#include <stdio.h>
#include <unistd.h>

int	main(int argc, char *argv[])
{
	char		*fractal_name;
	double		cx;
	double		cy;
	t_fractol	*fractol;
	mlx_t		*mlx;
	mlx_image_t	*mlx_img;

/*
	if (argc == 2 && ft_strncmp(argv[1], "mandelbrot", 10)
		|| argc == 4 && ft_strncmp(argv[1], "julia", 5))
	{
		
	}
*/

	mlx = mlx_init(WIDTH, HEIGHT, "My fractol", true);

	fractol = (t_fractol *)malloc(sizeof(t_fractol));
    if (!fractol)
        return (-1);

	init_fractol(fractol, cx, cy, fractal_name);

	fractol->mlx = mlx;
	mlx_img = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
	fractol->img = mlx_img;

	int result = draw_fractal(fractol, cx, cy);
	if (result == -1)
	{
		printf("Error in draw_fractals %d\n", result);
		return (1);
	
	}
	
	// Even after the image is being displayed, we can still manipulate it
	mlx_put_pixel(fractol->img, 0, 0, 0x00FF0000);
	
	mlx_loop(fractol->mlx);
	
}
// Register a hook and pass the mlx pointer as a parameter

	

// mlx_terminate(fractol.mlx);


// (draw_fractal(fractol, fractal_name, cx, cy) == -1)