/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharmund <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 21:06:20 by bharmund          #+#    #+#             */
/*   Updated: 2019/10/02 21:06:22 by bharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_error(char *error_name)
{
	ft_putstr(error_name);
	write(2, "Error\n", 6);
	exit(1);
}

void	take_aunts(t_farm *farm, int fd)
{
	int		i;
	char	*str;

	str = NULL;
	while (get_next_line(fd, &str) && check_comment(str))
		free(str);
	if (str == NULL)
		ft_error("empty file\n");
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
	free(str);
}

void	take_command(int fd, t_command *command, char *str, t_farm *farm)
{
	int		*flag;
	char	*tmp;
	t_room	*room;

	flag = ft_strequ(str, "##start") == 1 ? &(command->start) : &(command->end);
	if (*flag == 1)
		ft_error("dbl command\n");
	*flag = 1;
	while (get_next_line(fd, &tmp) && check_comment(tmp))
		free(tmp);
	if (!check_room(tmp))
		ft_error("need room after command\n");
	room = add_room_to_list(farm, tmp);
	if (ft_strequ(str, "##start"))
	{
		room->aunts = farm->count_aunts;
		room->start = 1;
	}
	if (ft_strequ(str, "##end"))
		room->finish = 1;
	free(tmp);
}

char	*take_rooms(int fd, t_farm *farm, t_command *command)
{
	char *str;

	command->start = 0;
	command->end = 0;
	while (get_next_line(fd, &str))
	{
		if (!check_comment(str))
		{
			if (check_command(str))
				take_command(fd, command, str, farm);
			else if (check_room(str))
				add_room_to_list(farm, str);
			else
			{
				if (!command->start || !command->end)
					ft_error("not_command st or end\n");
				return (str);
			}
		}
		free(str);
	}
	return (str);
}

void	read_data(int fd, t_farm *farm)
{
	char		*str;
	t_command	command;

	take_aunts(farm, fd);
	farm->room_list = NULL;
	farm->count_rooms = 0;
	farm->max_crd.x = -2147483648;
	farm->max_crd.y = -2147483648;
	farm->min_crd.x = 2147483647;
	farm->min_crd.y = 2147483647;
	str = take_rooms(fd, farm, &command);
	if (!check_link(str))
		ft_error("not_link\n");
	if (farm->count_rooms < 1)
		ft_error("need_rooms\n");
	initial_farm_array_rooms(farm);
	find_link(str, farm);
	free(str);
	take_links(fd, farm, &command);
}
