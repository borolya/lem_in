#include "lemin.h"


int take_name(char *str, t_room *room)
{
	int count;

	count = 0;
	while (str[count] && str[count] != ' ')//change to space 
		count++;
	if (!(room->name = malloc(sizeof(char) * (count + 1))))
		exit (-1);
	ft_strncpy(room->name, str, count);
	room->name[count] = '\0';
	return (count + 1);
}

t_room *take_room(char *str)
{
	t_room *room;
	int i;

	if (!(room = malloc(sizeof(t_room))))
		exit (-1);
	i = take_name(str, room);
	room->x = ft_atoi(str + i);
	if (room->x < 0)
		ERROR;
	while (str[i] != '\0' && str[i] != ' ')
		i++;
	room->y = ft_atoi(str + i);
	if (room->y < 0)
		ERROR;
	room->link_array = NULL;
	room->start = 0;
	room->finish = 0;
	return (room);
}

char *read_rooms(int fd, t_farm *farm, t_command *command, t_list **alst)
{
	char *str;
	int start;
	int finish;
	t_room *room;

	while (get_next_line(fd, &str) && str[0] != '\0')
	{
		if (!check_comment(str))
		{
			if (check_command(str))
				take_command(command);
			else if (check_room(str))
			{
				room = take_room(str);
				if (!check_uniq(*alst, room))
					ERROR;
				push_to_list(alst, room);
			}
			else
			{
				if (!start || !finish)
					ERROR;
				return (str);
			}
		}
		free(str);
	}
	return (NULL);
}

void read_data(int fd, t_farm *farm, int add_command)
{
    char *str;
	t_list *alst;
	t_command command;

    while (get_next_line(fd, &str) && check_comment(str))
		free(str);
	take_aunts(str, farm);
	free(str);
	alst = NULL;
	if (!check_link(str))
		ERROR;
	str = read_rooms(fd, farm, &alst, command);
	farm->count_rooms = ft_count_rooms(alst);
	if (farm->count_rooms < 1)
		ERROR;
	
	
	
}