#include "lemin.h"
#include "libft.h"

int check_link(char *str)
{
    int i;
    int tmp;

    i = 0;
    while (str[i] && str[i] != '-' && str[i] != ' ')
        i++;
    if (i < 1 || str[i] != '-')
        return (0);
    i++;
    tmp = 0;
    while (str[i] && str[i] != ' ')
    {
        i++;
        tmp++;
    }
    if (i < 1 && str[i] != '\0')
        return (0);
   // write(1, "link\n", 5);
    return (1);
}

int check_room(char *str)//rewrite!!!!!!!!!!
{
	int i;
	int tmp;

	i = 0;
	while (str[i] != '\0' && str[i] != ' ')
		i++;
	if (i < 1 || str[i] == '\0')
		return (0);
	tmp = 0;
	i++;
	while (str[i] != '\0' && str[i] != ' ')
	{
		if (str[i] > '9' || str[i] < '0')
			return (0);
		tmp++;
		i++;
	}
	if (tmp < 1 || str[i] == '\0')
		return (0);
	tmp = 0;
	i++;
	while (str[i] != '\0' && str[i] != ' ')
	{
		if (str[i] > '9' || str[i] < '0')
			return (0);
		tmp++;
		i++;
	}
	if (tmp < 1)
		return (0);
	if (str[i] != '\0')
		return (0);
	return (1);
}

int check_comment(char *str)
{
	if (str[0] == '#' && (str[1] == '\0' || str[1] != '#'))
		return (1);
	return (0);
}

int check_command(char *str)
{
	if (str[0] == '#' && str[1] == '#')
		return(1);
	return (0);
}