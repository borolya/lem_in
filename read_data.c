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

t_room *take_room(char *str, t_farm *farm)
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
	room->links_array = NULL;
	room->start = 0;
	room->finish = 0;
	room->ind = -1;
	return (room);
}

char *read_rooms(int fd, t_farm *farm, t_command *command, t_tree **root)
{
	char *str;
	int start;
	int finish;
	t_room *room;

	farm->count_rooms = 0;
	while (get_next_line(fd, &str) && str[0] != '\0')
	{
		if (!check_comment(str))
		{
			if (check_command(str))
				take_command(command);
			else if (check_room(str))
			{
				room = take_room(str, farm);
				tree_insert(root, find_parant(*root, room), room);
				farm->count_rooms++;
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

void initial_ltab(t_farm *farm)
{
	int i;

	if (!(farm->links_tab = ft_memalloc(sizeof(unsigned int*) * farm->count_rooms)))
		exit(-1);
	i = 0;
	while (i < farm->count_rooms)
	{
		if (!(farm->links_tab[i] = ft_memalloc(sizeof(unsigned int) * farm->count_rooms)))
		i++;
	}

}

void initia_array_rooms(t_farm *farm)
{
	if (!(farm->array_rooms = ft_memalloc(sizeof(t_room) * farm->count_rooms)))
		exit(-1);
	farm->count_rooms = 0;
}

t_room search(char *str, t_farm *farm)
{

}

void find_link(char *str, t_farm *farm)
{
	t_room room1;
	t_room room2;

	room1 = search(str, farm);
	room2 = search(ft_strchr(str, '-') + 1, farm);

}

void read_data(int fd, t_farm *farm, int add_command)
{
    char *str;
	t_tree *root;
	t_command command;//add command
	//correct name

    while (get_next_line(fd, &str) && check_comment(str))
		free(str);
	take_aunts(str, farm);
	free(str);
	root = NULL;
	str = read_rooms(fd, farm, &root, command);
	if (!check_link(str))
		ERROR;
	if (farm->count_rooms < 1)
		ERROR;
	initial_ltab(farm);
	initial_array_room(farm);
	find_link(str, farm);
	free(str);
	while(get_next_line(fd, str))
	{
		if(!check_comment(str))
		{
			if (check_command)//?
			{

			}
			if (check_link(str))
			{
				find_link(str, farm);
			}
		}
	}
	
	 
}