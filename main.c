#include "include/fractol.h"
#include "libft/libft.h"
#include <stdio.h>
#include <unistd.h>

int	main(int argc, char *argv[])
{	
	t_fractol	*fractol = malloc(sizeof(t_fractol));
	if (!fractol)
	{
		ft_putendl_fd("Error in malloc", 1);
		return (1);
	}

	mlx_t *mlx = mlx_init(WIDTH, HEIGHT, "My fractol", false);
	if (!mlx)
	{
		ft_putendl_fd("Error in mlx_init", 1);
		return (1);
	}

	mlx_image_t *img = mlx_new_image(mlx, WIDTH, HEIGHT);

	fractol->mlx = mlx;
	fractol->img = img;
	//mlx_cursor_hook
	init_fractol(fractol);


	if (argc == 2 && ft_strncmp(argv[1], "mandelbrot", 10) == 0)
	{
		draw_fractal(fractol, argv[1], 0, 0);
		mlx_image_to_window(mlx, img, 0, 0);
		
	}
	else if (argc == 4 && (ft_strncmp(argv[1], "julia", 5) == 0))
	{
		fractol->cxj = atof(argv[2]);
		fractol->cyj = atof(argv[3]);

		draw_fractal(fractol, argv[1], fractol->cxj, fractol->cyj);
		mlx_image_to_window(mlx, img, 0, 0);
	}
	else
	{
		ft_putendl_fd("Available fractals: mandelbrot, julia", 1);
		return (1);
	}
	printf("Before mlx_scroll_hook\n");

	mlx_key_hook(mlx, key_handler, fractol);

	mlx_scroll_hook(mlx, mouse_handler, fractol);

	//mlx_cursor_hook(mlx, cursor_handler, fractol);

	printf("After mlx_scroll_hook\n");
	mlx_loop(fractol->mlx);
	mlx_terminate(fractol->mlx);
	printf("After if statement\n");

	return (EXIT_SUCCESS);
}

	
