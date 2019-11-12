/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 17:57:03 by crenly-b          #+#    #+#             */
/*   Updated: 2019/08/01 19:01:20 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_find_line(char **str_read, char **line)
{
	char *tmp;

	if ((*str_read)[0] == '\0')
	{
		ft_strdel(str_read);
		return (0);
	}
	if (ft_strchr(*str_read, '\n') != NULL)
	{
		*(ft_strchr(*str_read, '\n')) = '\0';
		*line = ft_strdup(*str_read);
		tmp = ft_strdup(ft_strchr(*str_read, '\0') + 1);
		free(*str_read);
		if (tmp)
		{
			*str_read = ft_strdup(tmp);
			free(tmp);
		}
	}
	else
	{
		*line = ft_strdup(*str_read);
		ft_memdel((void **)str_read);
	}
	return (1);
}

int		get_next_line(int const fd, char **line)
{
	static char	*str[FD_LIMIT];
	char		buf[BUFF_SIZE + 1];
	char		*tmp;
	int			des;

	if (fd == -1 || !line || read(fd, buf, 0) < 0)
		return (-1);
	if (!(str[fd]))
		str[fd] = ft_strnew(0);
	while (ft_strchr(str[fd], '\n') == NULL)
	{
		des = read(fd, buf, BUFF_SIZE);
		buf[des] = '\0';
		if (des == 0)
			break ;
		tmp = ft_strjoin(str[fd], buf);
		free(str[fd]);
		str[fd] = ft_strdup(tmp);
		if (!(str[fd]))
			str[fd] = ft_strnew(0);
		free(tmp);
	}
	return (ft_find_line(&str[fd], line));
}
