#include "lemin.h"
#include "visu.h"

void ft_error(char *error_name)
{
	ft_putstr(error_name);
	write(2, "Error\n", 6); 
	exit(1);
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
	farm->count_aunts = ft_atoi(str);
	if (farm->count_aunts < 1)
		ft_error("bad_count_aunts\n");
}

void take_command(int fd, t_command *command, char *str, t_farm *farm)
{ 
	char *tmp;

	if (ft_strequ(str, "##start"))
	{
		if (command->start == 1)
			ft_error("dbl start\n");
		command->start = 1;
		while (get_next_line(fd, &tmp) && check_comment(tmp))
			free(tmp);
		if (!check_room(tmp))
			ft_error("need room after start\n");
		farm->start = add_room_to_list(farm, tmp);
		farm->start->aunts = farm->count_aunts;
		farm->start->start = 1;
	//	farm->count_rooms++;
	}
	else if (ft_strequ(str, "##end"))
	{
		if (command->finish)
			ft_error("dbl_end\n");
		command->finish = 1;
		while (get_next_line(fd, &tmp) && check_comment(tmp))
			free(tmp);
		if (!check_room(tmp))
			ft_error("need room after end\n");
		farm->finish = add_room_to_list(farm, tmp);
		farm->finish->aunts = 0;
		farm->finish->finish = 1;
	//	farm->count_rooms++;
	}
}

char *read_rooms(int fd, t_farm *farm, t_command *command)
{
	char *str;

	command->start = 0;
	command->finish = 0;
	farm->count_rooms = 0;
	farm->max_crd.x = -2147483648;
	farm->max_crd.y = -2147483648;
	farm->min_crd.x = 2147483647;
	farm->min_crd.y = 2147483647;
	while (get_next_line(fd, &str) && str[0] != '\0')
	{
		if (!check_comment(str))
		{
			if (check_command(str))
				take_command(fd, command, str, farm);
			else if (check_room(str))
				add_room_to_list(farm, str);
			else
			{
				if (!command->start || !command->finish)
					ft_error("not_command st or end\n");
				return (str);
			}
		}
		free(str);
	}
	return (str);
}

void read_links(int fd, t_farm *farm, t_command *command)
{
	char *str;

	while (get_next_line(fd, &str))
	{
		if (!check_comment(str))
		{
			if (check_command(str))
				take_command(fd, command, str, farm);
			else if (check_link(str))
				find_link(str, farm);
			else if (str[0] == '\0')
			{
				free(str);
				break ;
			}
			else
				ft_error("bad_string\n");
		}
		free(str);
	}
	//if (str[0] == '\0')
	//	free(str);
}

#include <stdio.h>

void write_room(t_room *room)
{
	int i;
	int *links_array;

    printf("name = |%s|, ind = %d , x = %d, y = %d\n", room->name, room->ind, room->crd.x, room->crd.y);
	i = 0;
	links_array = room->links_array;
	printf("links ");
	while (links_array[i] != -1)
	{
		printf("%d ", links_array[i]);
		i++;
	}
	printf("\n");
}

void write_farm(t_farm *farm)
{
	int i;

	i = 0;
	printf("\nWRITE\ncout_room = %d\n", farm->count_rooms);
	while (i < farm->count_rooms)
	{
		write_room(farm->array_rooms[i]);
		i++;
	}
	i = 0;
	printf("count_aunt = %d\n", farm->count_aunts);
	while (i < farm->count_aunts)
	{
		printf(" %d ", farm->array_aunts[i]);
		i++;
	}
    printf("\nEND WRITE\n");
}

void read_data(int fd, t_farm *farm)
{
	char *str;
	t_command command;

	while (get_next_line(fd, &str) && check_comment(str))
		free(str);
	take_aunts(str, farm);
	//printf("in start c_an = %d\n", farm->count_aunts);
	free(str);
	farm->room_list = NULL;
	str = read_rooms(fd, farm, &command);
	if (!check_link(str))
		ft_error("not_link\n");
	if (farm->count_rooms < 1)
		ft_error("need_rooms\n");
	initial_farm_array_rooms(farm);
	find_link(str, farm);
	free(str);
	read_links(fd, farm, &command);
	write_farm(farm);
}