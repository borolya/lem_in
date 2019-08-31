#include "libft.h"

typedef struct s_farm
{
	int aunts;
	t_list *rooms;
	int **links;
    int f_start;
    int f_finish;
} t_farm;

typedef struct s_room
{
	char *name;
	int x;
	int y;
    int start;
    int finish;
}   t_room;
