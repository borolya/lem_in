#include "lemin.h"
#include "libft.h"

int check_comment(char *str)
{
    if (str[0] == '#' && (str[1] == '\0' || str[1] != '#'))
        return (1);
    return (0);
}

int take_aunts(char *str, t_farm *farm)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] > '9' || str[i] < '0')
			return (-1);
		i++;
	}
	farm->aunts = ft_atoi(str);
	if (farm->aunts < 1)
		return (-1);
	return (1);
}

int ft_count_rooms(t_list *alst)
{
	int count;

	count = 0;
	while (alst != NULL)
	{
		count++;
		alst = alst->next;
	}
	return (count);
}

#include <stdio.h>

void write_list(t_list *alst)
{
	t_room *room;

	while (alst)
	{
		room = alst->content;
		printf("name = |%s|", room->name);
		printf("x = %d y = %d \n", room->x, room->y);
		alst = alst->next;
	}
}
void write_table(t_links *adja_table, int count_rooms)
{
	int i;
	int j;

	i = 0;
	while (i < count_rooms)
	{
		printf("name = %s ", adja_table[i].name);
		while (j < count_rooms)
		{
			printf("%d ", adja_table[i].array[j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

int read_file(int fd, t_farm *farm)
{
	char *str;
	int read_room;
	int start;
	int finish;
	t_room *room;
	t_list *alst;
	int i;
	int count_rooms;
	t_links *adja_table;
	t_links tmp;

	if (get_next_line(fd, &str) != 1)
		return (-1);
	while (check_comment(str) && get_next_line(fd, &str))
	{}
	if (take_aunts(str, farm) == -1)
		return (-1);//free farm, str
	free(str);
	start = 0;
	finish = 0;
	read_room = 1;
	alst = NULL;
	while (get_next_line(fd, &str) && read_room)
	{
		if (!check_comment(str))
		{
			if (ft_strequ(str, "##start"))
			{
				if (start)//the same room?
					return (-1);
				free(str);
				if (get_next_line(fd, &str) != 1)
					return (-1);
				if (!check_room(str))
					return (-1);
				room = take_room(str);
				room->start = 1;
				if (!check_uniq(alst, room))
					return (-1);
				if (push_to_list(&alst, room) == -1)
					return (-1);
				//ft_lstadd(&start, room);
				start = 1;
			}
			else if (ft_strequ(str, "##finish"))
			{
				if (finish)//the same room?
					return (-1);
				free(str);
				if (get_next_line(fd, &str) != 1)
					return (-1);
				if (!check_room(str))
					return (-1);
				room = take_room(str);
				room->finish = 1;
				if (!check_uniq(alst, room))
					return (-1);
				if (push_to_list(&alst, room) == -1)
					return (-1);
				//ft_lstadd(&start, room);
				finish = 1;
			}
			else if (check_room(str))
			{
				
				room = take_room(str);
				if (!check_uniq(alst, room))
					return (-1);
				if (push_to_list(&alst, room) == -1)
					return (-1);
				write(1, "room\n", 5);
				//write_list(alst);
			}
			else if (check_link(str))
			{
				if (!start || !finish)
					return (-1);
				write_list(alst);
				read_room = 0;
				count_rooms = ft_count_rooms(alst);
				printf("count_rooms = %d \n", count_rooms);
				if (count_rooms < 1)
					return (-1);
				adja_table = ft_memalloc(sizeof(t_links) * count_rooms);
				i = 0;
				while (alst)
				{
					room = alst->content;
					tmp = adja_table[i];
					tmp.array = ft_memalloc(sizeof(int) * count_rooms);
					tmp.name = room->name; 
					i++;
					alst = alst->next;
				}
				if (fill_adja_table(str, adja_table, count_rooms) == -1)
				{
					write(1, "tut\n", 4);
					return (-1);
				}
			}
			else
				return (-1);
		}	
		free(str);
	}
	if (!start || !finish)
		return (-1);


	/*
	//if links not exist?
	while (get_next_line(fd, &str))
	{
		if (!check_comment(str))
		{
			if (check_link(str))
			{
				if (fill_adja_table(str, adja_table, count_rooms) == -1)
					return (-1);
			}
		}
		else
			return (-1);
		free(str);
	}
	if (count_rooms == 0)
		return (-1);
	write_table(adja_table, count_rooms);
	*/
	return (0);
}