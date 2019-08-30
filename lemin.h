#include "libft.h"

typedef struct s_farm
{
	int aunts;
	t_list *rooms;
	int **links;
} t_farm;

typedef struct s_room
{
	char *name;
	int x;
	int y;
    int f_start;
    int f_finish;
}   t_room;
