#include <stdlib.h>

// skip spaces in the string
static void skip_spaces(const char *str)
{
    while(*str >= 9 && *str <= 13 || *str == 32)
        str++;
}


// convert ascii string to a float number
double ft_atof(const char *str)
{
    double result;

    double converted_value;
    int i;

    i = 0;

    //while(is_digit)

    // skip spaces

    if (str[i] == '-' || str[i] == '+')
        i++;
    // if 

    //str[i] = '\0';


    // return converted_value

    // else 

    return result;
}