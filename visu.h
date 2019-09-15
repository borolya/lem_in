#ifndef WIN_H 
# define WIN_H 1000
#endif

#ifndef WIN_W 
# define WIN_W 1000
#endif

#ifndef STEPS
# define STEPS 50
#endif
typedef struct s_point
{
	int x;
	int y;
} t_point;

typedef struct s_visu
{
	void *mlx_ptr;
	void *win_ptr;
	int action : 1;
	t_list *links;
	t_farm *farm;
	t_img aunt;
	t_img hex;
}   t_visu;

typedef struct s_img
{
	void *ptr;
	int *data;
	int bits_per_pixel;
	int h;
	int w;
	int endian;
}	t_img;

typedef struct s_link
{
	t_room *room1;
	t_room *room2;
	t_point *p;
	t_point *delta;
} t_link;