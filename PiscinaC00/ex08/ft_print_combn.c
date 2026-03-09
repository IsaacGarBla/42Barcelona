#include <unistd.h>


void    comb(int n, int pos, char digits[], char s_num[], char num_used[], int *primero)
{
    int     x;
    if (pos == n) 
    {
        if (*primero != 1) 
        {
            write(1, "," , 1);
        }
        *primero = 0;
        write(1, s_num, n);
        return;
    }
    x = pos;
    while (x <= 10 - n + pos)
    {
        if (num_used[x] =='0')
        {
            s_num[pos] = digits[x];
            num_used[x] = '1';
            comb(n, pos + 1, digits, s_num, num_used, primero);
            num_used[x] = '0';
        }
        x++;
    }
}

void ft_print_combn(int n)
{
    int     primero;
    char    s_digits[10]    = "0123456789";
    char    s_used[10]      = "0000000000";
    char    s_num[10]; 
    
    primero = 1;
    comb(n, 0, s_digits, s_num, s_used, &primero);
    write(1, "\n", 1);
}



/* Test function*/

int     main(void)
{
    ft_print_combn(1);
    
}