#include "minilibx-linux/mlx.h"

#include <stdlib.h>

#define WIDTH 800
#define HEIGHT 800

/**
 * @brief complex numbers struct
 * @param x - real part
 * @param y - imaginary part
*/
typedef struct s_complex
{
    double x;
    double y;
}               t_complex;

/**
 * @brief We have an image and now we need to  write pixels to it. For this we need 
 * to get the memory address on which we will mutate the bytes accordingly
*/
typedef struct s_image {
    void *img;
    char *addr;
    int bits_per_pixel;
    int line_length;
    int endian;
}               t_image;

typedef struct s_fratal {
    char *name;
    void *mlx_connection;
    void *mlx_window;
    t_image image;                    
}               t_fractal;



// int ft_strncmp(const char *s1, const char *s2, unsigned int n);


double map(double unscaled_num, double new_min, double new_max, double old_min, double old_max);
