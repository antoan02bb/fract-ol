#include <stdio.h>

/**
 * @brief simple linear mapping function
 * @param unscaled_num  number I want to scale
 * @param new_min       specifies the minimum value of the new range [new_min, new_max]
 * @param new_max       specifies the maximum value of the new range [new_min, new_max]
 * @param old_min       specifies the minimum value of the old range [old_min, old_max]
 * @param new_min       pecifies the maximum value of the old range [old_min, old_max]
*/
double scale(double unscaled_num, double new_min, double new_max, double old_min, double old_max)
{
    return (new_max - new_min) * (unscaled_num - old_min) / (old_max - old_min) + new_min;
}

int main()
{
    int i = 0;

    while (i < 800)
    {
        printf("%d -> %f\n", i, scale((double)i, -6, +2, 0, 799));
        i++;
    }
}