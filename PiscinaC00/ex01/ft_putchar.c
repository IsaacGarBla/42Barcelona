#include <unistd.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

/* Test function*/

int     main(void)
{
    ft_putchar('3');
    return (0);
}
