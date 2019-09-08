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
	if (i < 1)
		return (0);
	tmp = 0;
	i++;
	while(str[i] && str[i] != ' ')
	{
		if (str[i] > '9' || str[i] < '0')
			return (0);
		tmp++;
		i++;
	}
	if (tmp < 1)
		return (0);
	tmp = 0;
	i++;
	while (str[i] && str[i] != ' ')
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

t_room *take_room(char *str)
{
	int i;
	t_room *room;

	room = ft_memalloc(sizeof(t_room));
	if (room == NULL)
		return (NULL);
	i = take_name(str, room);
	if (i < 0)
		return (NULL);
	i++;
	room->x = ft_atoi(str + i);
	while (str[i] != '\0' && str[i] != ' ')
		i++;
	room->y = ft_atoi(str + i);
	room->start = 0;
	room->finish = 0;
	return (room);
}

t_tree *find_parant(t_tree *root, t_room *room)//exit(1) if dublicate
{
	t_tree *parant;

	parant = NULL;
	while (root != NULL)
	{
		parant = root;
		if (ft_strcmp(room->name, root->content->name) == 0)
		{
			fr_putstr("dublicate_name\n");
			ERROR;
		}
		else if (ft_strcmp(room->name, root->content->name) > 0)
			root = root->right;
		else
			root = root->left;
	}
	return (parant);
}

void tree_insert(t_tree **root, t_tree *parant, t_room *room)
{
	t_tree *new;

	//if (room == NULL)
	//	exit(-1);
	if (!(new = ft_memalloc(sizeof(t_tree))))
		exit(-1);
	new->content = room;
	new->right = NULL;
	new->left = NULL;
	new->p = NULL;
	if (parant == NULL)
	{
		*root = new;
		return;
	}
	if (ft_strcmp(new->content->name, parant->content->name) > 0)
		parant->right = new;
	else
		parant->left = new;
}

int fill_adja_table(char *str, t_links *table, int count_rooms)
{
	int i;
	int j;
	int count_letters;
    unsigned int *array;

	i = 0;
	count_letters = 0;
	while (str[count_letters] != '-')
		count_letters++;
    write(1, "tut\n", 4);
	while (!ft_strnequ(str, table[i].name, count_letters) && i < count_rooms)
		i++;
	if (i == count_rooms)
    {
        write(1, "not_found1\n", 11);
		return (-1);
    }
    j = 0;
	while (!ft_strequ(str + count_letters + 1, table[j].name) && j < count_rooms)
		j++;
	if (j == count_rooms)
		return (-1);
    //table[i].array[j] = 1;
	array = table[i].array;
    array[j] = 1;
    //(table[j].array)[i] = 1;
	array = table[j].array;
    array[i] = 1;
    return (0);
}