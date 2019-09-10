#include "lemin.h"
#include "libft.h"

int check_comment(char *str)
{
	if (str[0] == '#' && (str[1] == '\0' || str[1] != '#'))
		return (1);
	return (0);
}

void take_aunts(char *str, t_farm *farm)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] > '9' || str[i] < '0')
			ft_error("need aunt\n");
		i++;
	}
	farm->aunts = ft_atoi(str);
	if (farm->aunts < 1)
		ft_error("bad_count_aunt\n");
}
