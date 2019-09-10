/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharmund <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 14:53:40 by bharmund          #+#    #+#             */
/*   Updated: 2019/08/30 14:53:46 by bharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "lemin.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


void ft_error(char *error_name)
{
	ft_putstr(error_name);
	write(2, "Error\n", 6); 
	exit(1);
}

#include <stdio.h>

void ft_write_links_tab(t_farm *farm)
{
	int i;
	int j;

	i = 0;
	while (i < farm->count_rooms)
	{
		j = 0;
		while (j < farm->count_rooms)
		{
			printf("|%d| ", farm->links_tab[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
void ft_write_array_rooms(t_farm *farm)
{
	int i;
	t_room room;
	int j;

	i = 0;
	while ( i < farm->count_rooms)
	{
		room = farm->array_rooms[i];
		printf("\nname=%s, ind = %d, x = %d, y = %d, start = %d, finish = %d\nlinks_array", 
			room.name, room.ind, room.x, room.y, room.start, room.finish);
		j = 0;
		while(j < farm->count_rooms)
		{
			printf("%d ", room.links_array[j]);
			j++;
		}
		i++;
	}
}
void read_data(int fd, t_farm *farm)
{
	char *str;
	t_command command;//add command
	int ind;

	while (get_next_line(fd, &str) && check_comment(str))
		free(str);
	take_aunts(str, farm);
	free(str);
	farm->root = NULL;
	str = read_rooms(fd, farm, &command, &farm->root);
	if (!check_link(str))
		ft_error("not_link\n");
	if (farm->count_rooms < 1)
		ft_error("need_rooms\n");
	initial_ltab(farm);
	initial_array_rooms(farm, &ind);
	find_link(str, farm, &ind);
	free(str);
	while(get_next_line(fd, &str))
	{
		if(!check_comment(str))
		{
			if (check_command(str))
			{
				take_command(&command, str, farm, &farm->root, fd);
			}
			if (check_link(str))
				find_link(str, farm, &ind);
			else
				ft_error("bad_string\n");
		}
		free(str);
	}
	ft_write_links_tab(farm);
	ft_write_array_rooms(farm);
	//ft_free(root)
}

int main(int argc, char **argv)
{
	t_farm farm;
	int fd;

	if (argc == 1)
		fd = 0;
	else
		fd = open(argv[1], O_RDONLY);
	read_data(fd, &farm);
	return (0);
}