#include "lemin.h"
#include "libft.h"

int count_split(char **str)
{
	int count;

	if (str == NULL)
		return(0);
	count = 0;
	while (str[count])
		count++;
	return (count);
}

int take_name(char *str, t_room *room)
{
	int count;

	count = 0;
	while (!str[count] && str[count] != ' ')
		count++;
	if (!(room->name = malloc(sizeof(char) * (count + 1))))
		return (-1);//exit
	ft_strncpy(room->name, str, count);
	return (count);
}

t_room *take_room(char *str)
{
	int i;
	int count_space;
	t_room *room;

	room = ft_memalloc(sizeof(t_room));
	if (room == NULL)
		return (NULL);
	count_space = 0;
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

int check_room(char *str)
{
	int i;
	int tmp;

	i = 0;
	while(str[i] != '\0' && str[i] != ' ')
		i++;
	if (i < 1)
		return (0);
	tmp = 0;
	while(str[i] && str[i] != ' ')
	{
		if (str[i] > '9' || str[i] < '0')
			return (0);
		tmp++;
	}
	if (tmp < 1)
		return (0);
	tmp = 0;
	while(str[i] && str[i] != ' ')
	{
		if (str[i] > '9' || str[i] < '0')
			return (0);
		tmp++;
	}
	if (tmp < 1)
		return (0);
	if (str[i] != '\0')
		return (0);
	return (1);
}

int read(int fd, t_farm *farm)
{
	char *str;
	char **split;
	int count;
	int read_room;
	int start;
	int finish;
	t_room *room;
	t_room *start;
	int i;

	if (get_next_line(fd, &str) != 1)
		return(-1);
	
	//take_aunts
	i = 0;
	while (str[i])
	{
		if (str[i] > '9' || str[i] < '0')
			return(-1);
		i++;
	}
	farm->aunts = ft_atoi(str);
	if (farm->aunts < 1)
		return (-1);
	free(str);
	//
	
	start = 0;
	finish = 0;
	read_room = 1;
	while (get_next_line(fd, &str) && read_room)
	{
		if (!check_comment(str))
		{
			if (ft_strequ(str, "##start"))
			{
				if (start)
					return (-1);
				free(str);
				if (get_next_line(fd, &str) != 1)
					return (-1);
				if (!check_room(str))
					return (-1);
				room = take_room(str);
				if (!check_uniq(start, room))
					return (-1);
				ft_lstadd(&start, room);
				start = 1;
			}
			else if (ft_strequ(str, "##finish"))
			{
				//the same like start
			}
			else if (check_room(str))
			{
				room = take_room(str);
				if (!check_uniq(start, room))
					return (-1);
				ft_lstadd(&start, room);
			}
			else
			{
				check_link;
				read_room == 0;
			}
		}
		free(str);
	}
	if (!start || !finish)
		return (-1);
	//start ,finish
	/*
	while (get_next_line(fd, &str))
	{
		if (!check_comment)
		{
			if (!check_links)
				return (-1);
		}
		free(str);
	}
	*/
}