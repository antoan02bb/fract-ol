// Linear interpolation - Линейна интерполация

#include "fractol.h"

/**
 * [0..799] -> [-2..+2]
*/
double map(double unscaled_num, double new_min, double new_max, double old_min, double old_max)
{
    return (new_max - new_min) * (unscaled_num - old_min) / (old_max - old_min) + new_min;
}

/**
 * @brief sums a real and and an imaginary number together
*/
t_complex complex_sum(t_complex z1, t_complex z2)
{
    t_complex result;

    result.x = z1.x + z2.x;  // real num
    result.y = z1.y + z2.y;  // imaginary num

    return result;
}

/**
 * @brief 1. squares a complex number
 * @brief 2. (x^2 - y^2) - real value
 * @brief 3. 2xyi        - imaginary value
 * @brief 4. (x_real + y_imaginary)^2 = x^2 + 2*x*y + y^2
*/
t_complex complex_square(t_complex z)
{
    t_complex result;

    
    result.x = z.x * z.x - z.y * z.y;   // real
    result.y = 2*z.x*z.y;               // imaginary
}






