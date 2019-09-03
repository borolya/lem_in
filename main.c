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

int main(int argc, char **argv)
{
    t_farm farm;
	t_links table;
	int fd;

	if (argc == 1)
        fd = 0;
    else
		fd = open(argv[1], O_RDONLY);
	//farm = malloc(sizeof(t_farm));
    if (read_file(fd, &farm) == -1)
		write (1, "bad file\n", 9);
	else
		write(1, "all good\n", 9);
	return (0);
}