/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sup.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 12:26:47 by crenly-b          #+#    #+#             */
/*   Updated: 2019/10/08 12:32:45 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		add_link(t_room *room, int new)
{
	int i;

	i = 0;
	while (room->link[i] != -1)
	{
		if (room->link[i] == new)
			return ;
		i++;
	}
	room->link[i++] = new;
	room->link[i] = -1;
}

int			search_path(t_room *room)
{
	if (room->link[0] == -1)
	{
		ft_printf("hole in path \n");
		return (-1);
	}
	else if (room->link[1] != -1)
	{
		ft_printf("room pos = %d link0 = %d link1 = %d \n",
			room->pos, room->link[0], room->link[1]);
		ft_printf("dup path\n");
		return (-1);
	}
	return (room->link[0]);
}

void		ft_lstaddend(t_list **alst, t_list *new)
{
	t_list *list;

	if (*alst == NULL)
	{
		*alst = new;
		new->next = NULL;
		return ;
	}
	list = *alst;
	while (list->next != NULL)
		list = list->next;
	list->next = new;
	new->next = NULL;
}

void		ft_lstaddlbo(t_list **alst, t_list *new)
{
	t_list *lbo;
	t_list *next;

	if (*alst == NULL)
		ft_printf("ERROR END");
	if ((*alst)->next == NULL)
	{
		new->next = *alst;
		*alst = new;
		return ;
	}
	lbo = *alst;
	while (lbo->next->next != NULL)
		lbo = lbo->next;
	next = lbo->next;
	lbo->next = new;
	new->next = next;
}

void		ft_find_end_room(char **line, t_map *map)
{
	t_list *temp;

	map->str = ft_strsplit(*line, ' ');
	if (!map->str[0] || !map->str[1] || !map->str[2] || map->str[3] != NULL
		|| map->str[0][0] == 'L' || (ft_strchr(&(*map->str[0]), 45) != NULL))
		ft_lem_error("Error(end room) = \0", line);
	ft_atoicoor(&(*map->str[1]));
	ft_atoicoor(&(*map->str[2]));
	ft_new_roominitial(map);
	map->new_room->pos = 1;
	temp = ft_elem_of_rooms(map);
	if (map->s == 0)
		ft_lstaddend(&map->rooms, temp);
	else
		ft_lstaddlbo(&map->rooms, temp);
	map->ef = 0;
	temp = NULL;
}
