#include <stddef.h>

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
    size_t i;

    if (n == 0)
        return 0;

    i = 0;
    while (*s1 == *s2 && *s1 != '\0')
    {
        if (i < (n - 1))
            i++;
        else
            return 0;
    }
    return ((unsigned char)(*s1)) - (unsigned char)(*s2);
}

// #include <string.h>
// #include <stdio.h>

// int main() {
//     const char *str = "Antoand";
//     const char *str2 = "Antoand";

//     unsigned int num = 4;

//     int result = ft_strncmp(str, str2, num);
//     int result2 = strncmp(str, str2, num);

//     printf("My func: %d\n", result);
//     printf("Original: %d", result2);

//     return 0;
// }