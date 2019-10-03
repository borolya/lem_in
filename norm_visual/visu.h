/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharmund <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 19:56:36 by bharmund          #+#    #+#             */
/*   Updated: 2019/10/03 19:56:38 by bharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISU_H
# define VISU_H

# include "lemin.h"
# include "mlx.h"

# ifndef WIN_H
#  define WIN_H 1040
# endif

# ifndef WIN_W
#  define WIN_W 1040
# endif

# ifndef HEX_W
#  define HEX_W 1000
# endif

# ifndef HEX_H
#  define HEX_H 1000
# endif

# ifndef SQ_SIZE
#  define SQ_SIZE 10
# endif

# ifndef STEPS
#  define STEPS 50
# endif

typedef struct	s_img
{
	void		*ptr;
	int			*data;
	int			bits_per_pixel;
	int			h;
	int			w;
	int			endian;
}				t_img;

typedef struct	s_dpoint
{
	double		x;
	double		y;
}				t_dpoint;

typedef struct	s_visu
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		step;
	t_list	*links;
	t_farm	*farm;
	t_img	aunt;
	t_img	hex;
	int		fd;
}				t_visu;

typedef struct	s_link
{
	t_room		*room1;
	t_room		*room2;
	t_dpoint	p;
	t_dpoint	delta;
	int			numb;
}				t_link;

void			hex_img(t_img *hex, t_farm *farm);
void			free_visu(t_visu *visu);
void			free_farm(t_farm *farm);
void			draw_line(t_point p1, t_point p2, int *img_data);
int				step_init(int keycode, t_visu *visu);
int				dinamic(t_visu *visu);
#endif
