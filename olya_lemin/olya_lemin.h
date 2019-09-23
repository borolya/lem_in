#ifndef LEMIN_H
# define LEMIN_H

#include "libft.h"

typedef struct s_path
{
	int *array;
	int length;
}   t_path;

typedef struct s_point
{
	int x;
	int y;
}   t_point;

typedef struct s_room
{
	int ind;
	char *name;
	t_point crd;
	int start : 1;
	//for start or finish array aunts
	int finish : 1;
	//int *links_array;
	// int *li
	int *in_links;//end -1
	int *out_links;//end -1
	int aunts;
	//int *including_in_path;//end -1
}   t_room;

typedef struct s_farm
{
	int count_aunts;
	int *array_aunts;
	int count_rooms;
	//t_room *start;
	//t_room *finish;
	//t_list *room_list;
	t_room *(*array_rooms);// * 2 изначально замолочить вторую чать! in-out and initialize
	t_path *good_path;//end -1
	//t_path *finding_path;
	int best_lenght;
	int **weight_tab;//size 2count_aunts * 2count_aunts;
} t_farm;

#endif