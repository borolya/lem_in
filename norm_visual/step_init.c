/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_step_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharmund <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 19:47:03 by bharmund          #+#    #+#             */
/*   Updated: 2019/10/03 19:47:06 by bharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

static void	fill_points(t_link *link)
{
	link->p.x = (double)link->room1->crd.x;
	link->p.y = (double)link->room1->crd.y;
	link->delta.x = (double)(link->room2->crd.x - link->room1->crd.x) / STEPS;
	link->delta.y = (double)(link->room2->crd.y - link->room1->crd.y) / STEPS;
}

static char	*room2_in_link(char *str, t_farm *farm, t_link *link)
{
	char	*tmp;
	int		len;
	int		i;

	tmp = ft_strchr(str, ' ');
	if (tmp != NULL)
		len = tmp - str;
	else
		len = ft_strlen(str);
	i = 0;
	while (i < farm->count_rooms &&
		!ft_strnequ(str, farm->array_rooms[i]->name, len))
		i++;
	if (i < farm->count_rooms)
		link->room2 = farm->array_rooms[i];
	else
		ft_error("aunt go to nowhere");
	fill_points(link);
	if (tmp != NULL)
		tmp++;
	return (tmp);
}

static char	*handle_str(char *str, t_farm *farm, t_link *link)
{
	if (str[0] != 'L')
		ft_error("bad_moved\n");
	str++;
	link->numb = ft_atoi(str) - 1;
	if (link->numb >= farm->count_aunts)
		ft_error("bad_aunt_numb\n");
	link->room1 = farm->array_rooms[farm->array_aunts[link->numb]];
	str = ft_strchr(str, '-');
	if (str == NULL)
		ft_error("aunt go to nowhere");
	str++;
	return (room2_in_link(str, farm, link));
}

int			step_init(int keycode, t_visu *visu)
{
	t_link	link;
	char	*save;
	char	*str;
	t_list	*list;

	if (keycode == 53)
		free_visu(visu);
	else if (keycode == 49 && visu->step < 0)
	{
		if (get_next_line(visu->fd, &str))
		{
			save = str;
			while (save != NULL && save[0] != '\0')
			{
				save = handle_str(save, visu->farm, &link);
				if (!(list = ft_lstnew(&link, sizeof(t_link))))
					exit(-1);
				ft_lstadd(&(visu->links), list);
			}
			free(str);
			visu->step = STEPS;
		}
	}
	return (0);
}
