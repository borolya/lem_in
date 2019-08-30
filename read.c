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

	if (get_next_line(fd, &str) != 1)
		return(-1);
	split = ft_split(str, ' ');
	if (count_split(split) != 1)
		return (-1);
	farm->aunts = ft_atoi(split[0]);
	if (farm->aunts < 1)
		return (-1);
	start = 0;
	finish = 0;
	read_room = 1;
	while (get_next_line(fd, &str) && read_room)
	{
	//	split = t_split(str, ' ');
	//	count = count_split(split);
		if (!check_comment(str))
		{
			if(ft_strequ(str, "##start"))
			{
				if (start)
					return (-1);
				if (!(room = add_room(str))//addromm
					return (-1);
				room->start = 1;
				ft_add_list(start, room);
				start = 1;
			}
			else if (ft_strequ(str, "##finish"))
			{
				if (finish)
					return (-1);
				if (!(room = add_room(str)))
					return (-1);
				room->finish = 1;
				ft_add_list(start, room);
				finish = 1;
			}
			else if (add_room)
			{
				/* code */
			}
			else
			{
				check_link;
				read_room == 0;
			}
		}
		free(str);
	}
	//start ,finish


	while (get_next_line(fd, &str))
	{
		if (!check_comment)
		{
			if (!check_links)
				return (-1);
		}
		free(str);
	}
}