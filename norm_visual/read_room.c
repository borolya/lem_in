/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_read_room.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharmund <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 20:38:12 by bharmund          #+#    #+#             */
/*   Updated: 2019/10/02 20:38:17 by bharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int		take_name(char *str, t_room *room)
{
	int count;

	if (str[0] == 'L')
		ft_error("L in name\n");
	count = 0;
	while (str[count] && str[count] != ' ')
	{
		if (str[count] == '-')
			ft_error("- in name\n");
		count++;
	}
	if (!(room->name = malloc(sizeof(char) * (count + 1))))
		exit(-1);
	ft_strncpy(room->name, str, count);
	room->name[count] = '\0';
	return (count + 1);
}

static t_room	fill_name_crd(char *str)
{
	t_room	room;
	int		i;

	i = take_name(str, &room);
	room.crd.x = ft_atoi(str + i);
	if (room.crd.x < 0 || (room.crd.x == 0 && str[i] != '0'))
		ft_error("bad x\n");
	while (str[i] != '\0' && str[i] != ' ')
		i++;
	room.crd.y = ft_atoi(str + i);
	if (room.crd.y < 0 || (room.crd.y == 0 && str[i + 1] != '0'))
		ft_error("bad y\n");
	room.links_array = NULL;
	room.start = 0;
	room.finish = 0;
	room.aunts = 0;
	room.ind = -1;
	return (room);
}

static void		check_dbl_name(t_list *alst, char *name)
{
	t_room *room;

	while (alst != NULL)
	{
		room = alst->content;
		if (ft_strequ(room->name, name))
			ft_error("dbl name\n");
		alst = alst->next;
	}
}

int				check_dbl_crd(int x, int y, t_list *alst)
{
	t_room *room;

	if (alst == NULL)
		return (0);
	room = alst->content;
	if (room->crd.x == x && room->crd.y == y)
		return (1);
	return (check_dbl_crd(x, y, alst->next));
}

t_room			*add_room_to_list(t_farm *farm, char *str)
{
	t_room	room;
	t_list	*list;

	room = fill_name_crd(str);
	if (check_dbl_crd(room.crd.x, room.crd.y, farm->room_list))
		ft_error("dbl crd\n");
	if (room.crd.x > farm->max_crd.x)
		farm->max_crd.x = room.crd.x;
	if (room.crd.y > farm->max_crd.y)
		farm->max_crd.y = room.crd.y;
	if (room.crd.x < farm->min_crd.x)
		farm->min_crd.x = room.crd.x;
	if (room.crd.y < farm->min_crd.y)
		farm->min_crd.y = room.crd.y;
	check_dbl_name(farm->room_list, room.name);
	list = ft_lstnew(&room, sizeof(t_room));
	if (list == NULL)
		exit(-1);
	ft_lstadd(&(farm->room_list), list);
	farm->count_rooms++;
	return (list->content);
}
