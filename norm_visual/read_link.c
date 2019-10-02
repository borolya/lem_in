/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_read_link.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharmund <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 21:04:18 by bharmund          #+#    #+#             */
/*   Updated: 2019/10/02 21:04:19 by bharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	search_rooms(char *str, t_list *list,
							t_room **room1, t_room **room2)
{
	int		wrdlen;
	char	*separator;
	t_room	*room;

	separator = ft_strchr(str, '-');
	wrdlen = separator - str;
	separator++;
	*room1 = NULL;
	*room2 = NULL;
	room = list->content;
	while (list != NULL && (*room1 == NULL || *room2 == NULL))
	{
		room = list->content;
		if (ft_strnequ(str, room->name, wrdlen))
			*room1 = room;
		if (ft_strequ(separator, room->name))
			*room2 = room;
		list = list->next;
	}
	if (*room1 == NULL || *room2 == NULL)
		ft_error("bad_link\n");
}

void		find_link(char *str, t_farm *farm)
{
	t_room	*room1;
	t_room	*room2;
	int		i;

	search_rooms(str, farm->room_list, &room1, &room2);
	if (room1 == room2)
		ft_error("loop\n");
	i = 0;
	while (room1->links_array[i] != -1 && room1->links_array[i] != room2->ind)
		i++;
	if (room1->links_array[i] == -1)
		room1->links_array[i] = room2->ind;
	i = 0;
	while (room2->links_array[i] != -1 && room2->links_array[i] != room1->ind)
		i++;
	if (room2->links_array[i] == -1)
		room2->links_array[i] = room1->ind;
}

void		take_links(int fd, t_farm *farm, t_command *command)
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
}
