#include "lemin.h"

int take_name(char *str, t_room *room)
{
	int count;

	if (str[0] == 'L')
		ft_error("L in name\n");
	count = 0;
	while (str[count] && str[count] != ' ')//change to space
	{
		if (str[count] == '-')
			ft_error("- in name\n");
		count++;
	}
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
		ft_error("bad x\n");
	while (str[i] != '\0' && str[i] != ' ')
		i++;
	room->y = ft_atoi(str + i);
	if (room->y < 0)
		ft_error("bad y\n");
	room->links_array = NULL;
	room->start = 0;
	room->finish = 0;
	room->ind = -1;
	return (room);
}

int search_coordinates(int x, int y, t_tree *root)
{
	if (root == NULL)
		return (0);
	if (root->content->x == x && root->content->y == y)
		return (1);
	return (search_coordinates(x, y, root->left) || search_coordinates(x, y, root->right));
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
            exit(-1);
		i++;
	}
}

void initial_array_rooms(t_farm *farm, int *ind)
{
    t_room *room;

	if (!(farm->array_rooms = ft_memalloc(sizeof(t_room) * farm->count_rooms)))
		exit(-1);
	farm->array_rooms[0] = *(farm->start);
    room = farm->start;
    room->ind = 0;
	if (!(room->links_array = malloc(sizeof(int) * farm->count_rooms)))
			exit(-1);
	init_links_array(room->links_array, farm->count_rooms);
	farm->array_rooms[1] = *(farm->finish);
    room = farm->finish;
    room->ind = 1;
	if (!(room->links_array = malloc(sizeof(int) * farm->count_rooms)))
			exit(-1);
	init_links_array(room->links_array, farm->count_rooms);
	*ind = 2;
}
void init_links_array(int *array, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		array[i] = -1;
		i++;
	}
}

void add_link(int *array, int ind)
{
	int i;

	i = 0;
	while (array[i] != -1)
		i++;
	array[i] = ind;
}
#include <stdio.h>

void find_link(char *str, t_farm *farm, int *ind)
{
	t_room *room1;
	t_room *room2;
	char *separator;

    write(1, "link  ", 5);
	separator = ft_strchr(str, '-');
	room1 = ft_search(str, farm, (int)(separator - str), ind);
    ft_putstr(room1->name);
    ft_putstr(ft_itoa(room1->ind));
    write(1, " ", 1);
	separator++;
	room2 = ft_search(separator, farm, ft_strlen(separator), ind);
    ft_putstr(room2->name);
    ft_putstr(ft_itoa(room2->ind));
    write(1, "\n", 1);
	if (ft_strequ(room1->name, room2->name))
	{
		write(1, "loop\n", 5);
		ft_error();;	
	}
	if (farm->links_tab[room1->ind][room2->ind] == 1)
	{
		ft_putstr("dublicate_links\n");
		ft_error();
	}
	farm->links_tab[room1->ind][room2->ind] = 1;
	farm->links_tab[room2->ind][room1->ind] = 1;
	add_link(room1->links_array, room2->ind);
	add_link(room2->links_array, room1->ind);
}

void take_command(t_command *command, char *str, t_farm *farm, t_tree **root, int fd)
{ 
	char *tmp;

	if (ft_strequ(str, "##start"))
	{
        if (command->start == 1)
            ft_error("dbl start\n");
		command->start = 1;
		while (get_next_line(fd, &tmp) && check_comment(str))
			free(tmp);
		if (!check_room(tmp))
			ft_error("need room after start\n");
		farm->start = ft_room(farm, root, tmp);
	}
	else if (ft_strequ(str, "##finish"))
	{
        if (command->finish)
            ft_error("dbl_finish\n");
		command->finish = 1;
		while (get_next_line(fd, &tmp) && check_comment(str))
			free(tmp);
		if (!check_room(tmp))
			ft_error("need room after finish\n");
		farm->finish = ft_room(farm, root, tmp);
	}
}
