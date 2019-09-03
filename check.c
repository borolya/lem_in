#include "lemin.h"
#include "libft.h"

int check_link(char *str)
{
    int i;
    int tmp;
    i = 0;
    while (str[i] && str[i] != '-' && str[i] == ' ')
        i++;
    if (i < 1 || str[i] != '-')
        return (-1);
    i++;
    tmp = 0;
    while (str[i] && str[i] == ' ')
    {
        i++;
        tmp++;
    }
    if (i < 1 && str[i] != '\0')
        return (-1);
   // write(1, "link\n", 5);
    return (0);
}
