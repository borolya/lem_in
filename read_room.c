#include "lemin.h"
#include "libft.h"
#include <stdio.h>

int check_room(char *str)
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
int check_command(char *str)
{
	if (str[0] == '#' && str[1] == '#')
		return(1);
	return (0);
}

t_room *ft_room(t_farm *farm, t_tree **root, char *str)
{
	t_room *room;

	room = take_room(str);
	if (search_coordinates(room->x, room->y, *root))
		ft_error("duble_coord");
	tree_insert(root, find_parent(*root, room), room);
	farm->count_rooms++;
	return (room);
}

char *read_rooms(int fd, t_farm *farm, t_command *command, t_tree **root)
{
	char *str;

	command->start = 0;
	command->finish = 0;
	farm->count_rooms = 0;
	while (get_next_line(fd, &str) && str[0] != '\0')
	{
		if (!check_comment(str))
		{
			if (check_command(str))
				take_command(command, str, farm, root, fd);
			else if (check_room(str))
				ft_room(farm, root, str);
            else
			{
				if (!command->start || !command->finish)
					ft_error("not_command st or fin\n");
				return (str);
			}
		}
		free(str);
	}
	return (str);
}
