#ifndef VISU_H
# define VISU_H

#ifndef WIN_H 
# define WIN_H 1000
#endif

#ifndef WIN_W 
# define WIN_W 1000
#endif

#ifndef HEX_W 
# define HEX_W 800
#endif

#ifndef HEX_H 
# define HEX_H 800
#endif

#ifndef SQ_SIZE 
# define SQ_SIZE 10
#endif

#ifndef STEPS
# define STEPS 100
#endif

#include "lemin.h"
#include "mlx.h"
typedef struct s_img
{
	void	*ptr;
	int		*data;
	int		bits_per_pixel;
	int		h;
	int		w;
	int		endian;
}	t_img;

typedef struct s_visu
{
	void *mlx_ptr;
	void *win_ptr;
	int step;
	t_list *links;
	t_farm *farm;
	t_img aunt;
	t_img hex;
    int     fd;
}   t_visu;


typedef struct s_link
{
	t_room *room1;
	t_room *room2;
	t_point p;
	t_point delta;
} t_link;

void	hex_img(t_img *hex, t_farm *farm);
#endif