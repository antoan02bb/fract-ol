/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonie <aantonie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 20:20:36 by aantonie          #+#    #+#             */
/*   Updated: 2024/04/30 00:32:57 by aantonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fractol.h"
#include "libft/libft.h"
/**
 * @brief Draws the fractal
 */
int	draw_fractal(t_fractol *fractal, char *input, double cx, double cy)
{
	mlx_delete_image(fractal->mlx, fractal->img);
	
	fractal->img = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);

	mlx_image_to_window(fractal->mlx, fractal->img, 0, 0);
	
	fractal->x = 0;
	fractal->y = 0;
	
	while (fractal->x < WIDTH)
	{
		while (fractal->y < HEIGHT)
		{
			if (ft_strncmp(input, "mandelbrot", 10) == 0)
			{ 
				calculate_mandelbrot(fractal);
			} 
			else if (ft_strncmp(input, "julia", 5) == 0)
			{
				calculate_julia(fractal, cx, cy);
			}
			else
			{
				ft_putendl_fd("Available fractals: mandelbrot, julia 444", 1);
				return (-1);
			}
			//mlx_put_pixel(fractal->img, fractal->x, fractal->y, fractal->color);
			fractal->y++;
		}
		fractal->x++;
		fractal->y = 0;
	}

	return (0);
}
