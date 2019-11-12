/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 16:04:02 by crenly-b          #+#    #+#             */
/*   Updated: 2019/10/08 12:22:51 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int		ft_analyse_line(t_map *map, char **line)
{
	if (*(*line) == '#' && ft_strequ(*line, "##start\0") == 0
			&& ft_strequ(*line, "##end\0") == 0)
		return (1);
	else if (map->s == 0 && ft_strequ(*line, "##start\0") == 1
		&& map->ants > 0 && map->ef == 0)
	{
		map->s = 1;
		map->sf = 1;
		return (1);
	}
	else if (map->e == 0 && ft_strequ(*line, "##end\0") == 1
		&& map->ants > 0 && map->sf == 0)
	{
		map->ef = 1;
		map->e = 1;
		return (1);
	}
	else if ((*(*line) == ' ' || *(*line) == '\n' || *(*line) == '\t'
		|| *(*line) == '-') ||
		(map->s == 1 && ft_strequ(*line, "##start\0") == 1) ||
		(map->e == 1 && ft_strequ(*line, "##end\0") == 1))
		return (-1);
	return (0);
}

static void		ft_find_amount_of_ants(char **line, t_map *map)
{
	char **str;

	str = NULL;
	str = ft_strsplit(*line, ' ');
	if (!str || str[0] == NULL || str[1] != NULL)
		ft_lem_error("INPUT ERROR(ants) = \0", line);
	else
	{
		map->ants = ft_atoilemin(str[0]);
		ft_str2del(&str);
	}
}

static void		ft_save_inf(char **line, t_map *map, t_farm *farm)
{
	if (map->ants == 0)
		ft_find_amount_of_ants(line, map);
	else if (map->ants != 0 && map->sf == 1)
		ft_find_start_room(line, map);
	else if (map->ants != 0 && map->ef == 1)
		ft_find_end_room(line, map);
	else if (map->ants != 0 && map->sf == 0 && map->ef == 0 &&
			(map->s == 0 || map->e == 0))
		ft_find_curr_room(line, map);
	else if (map->ants != 0 && map->s == 1 && map->e == 1 &&
		map->sf == 0 && map->ef == 0 && map->lf == 0)
	{
		if (ft_strchr(*line, 45) == NULL)
			ft_find_curr_room(line, map);
		else
			ft_savelinks(line, map, farm);
	}
	else if (map->ants != 0 && map->s == 1 && map->e == 1 && map->lf == 1)
		ft_savelinks(line, map, farm);
	else
		ft_lem_error("INPUT ERROR = \0", line);
}

static void		ft_validation_sup1(t_map *map,
	t_farm *farm, int *gnl_param, char **line)
{
	if (*line == NULL)
		ft_lem_error("INPUT ERROR(line == NULL) = \0", line);
	else if ((*gnl_param = ft_analyse_line(map, line)) == 1)
		return ;
	else if (*gnl_param == -1)
		ft_lem_error("INPUT ERROR(line) = \0", line);
	else if (*gnl_param == 0)
		ft_save_inf(line, map, farm);
}

char			*ft_validation(t_map *map, t_farm *farm)
{
	char	*line;
	int		gnl_number;
	int		fd;
	char	*text;

	fd = 0;
	line = NULL;
	gnl_number = 0;
	if (!(text = (char *)(malloc(sizeof(char) * 1000000))))
		exit(-1);
	text[0] = '\0';
	while (1)
	{
		if ((gnl_number = get_next_line(fd, &line)) < 0)
			ft_lem_error("READ ERROR(GNL) = \0", &line);
		else if (gnl_number == 0)
			break ;
		else
			ft_validation_sup1(map, farm, &gnl_number, &line);
		ft_strcat(text, line);
		ft_strcat(text, "\n");
		ft_strdel(&line);
	}
	return (text);
}
