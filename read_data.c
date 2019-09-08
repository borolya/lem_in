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

void initia_array_rooms(t_farm *farm, int *ind)
{
	if (!(farm->array_rooms = ft_memalloc(sizeof(t_room) * farm->count_rooms)))
		exit(-1);
	farm->array_rooms[0] = farm->start;
	farm->array_rooms[1] = farm->finish;
	*ind = 2;
}
void init_links_array(int *array, int *size)
{
	int i;

	i = 0;
	while (i < size)
	{
		array[i] = -1;
		i++;
	}
}
t_room *search(char *str, t_farm *farm, int n, int *ind)
{
	t_tree *tree;
	t_room *room;
	int n;

	tree = farm->tree_rooms;
	
	while (tree != NULL && !ft_strnequ(tree->content->name, str, n))
	{
		if (ft_strncmp(str, tree->content->name, n) > 0)
			tree = tree->right;
	}
	if (tree == NULL)
		ERROR;
	room = tree->content;
	if (room->ind < 0)
	{
		room->ind = *ind;
		farm->array_rooms[*ind] = *room;
		(*ind)++;
		if(!(room->links_array = malloc(sizeof(int) * farm->count_rooms)))
			exit(-1);
		init_links_array(room->links_array, farm->count_rooms);
	}
	return(room);
	/*	
	tree->content->ind = farm->count_rooms;
	farm->links_tab[farm->count_rooms] = 
	farm->count_rooms++;
	*/
}

void add_link(int *array, int ind)
{
	int i;

	while (array[i]!=-1)
		i++;
	array[i] = ind;
	
}
void find_link(char *str, t_farm *farm, int *ind)
{
	t_room *room1;
	t_room *room2;
	char *separator;

	separator = ft_strchr(str, '-');
	room1 = search(str, farm, (int)(separator - str), ind);
	separator++;
	room2 = search(separator, farm, ft_strlen(separator), ind);
	if (ft_strequ(room1->name, room2->name))
	{
		write(1, "loop\n", 5);
		ERROR;	
	}
	if (farm->links_tab[room1->ind][room2->ind] == 1)
	{
		ft_putstr("dublicate_links\n");
		ERROR;
	}
	farm->links_tab[room1->ind][room2->ind] = 1;
	farm->links_tab[room2->ind][room1->ind] = 1;
	add_link(room1->links_array, room2->ind);
	add_link(room2->links_array, room1->ind);
}

void read_data(int fd, t_farm *farm, int add_command)
{
    char *str;
	t_tree *root;
	t_command command;//add command
	int ind;
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
	initial_array_room(farm, &ind);
	find_link(str, farm, &ind);
	free(str);
	while(get_next_line(fd, str))
	{
		if(!check_comment(str))
		{
			if (check_command)//?
			{

			}
			if (check_link(str))
				find_link(str, farm, &ind);
			else
			{
				ft_purstr("bad_string\n");
				ERROR;
			}
		}
		free(str);
	}
	//ft_free(root)
}