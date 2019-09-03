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
    int start;
    int finish;
}   t_room;

typedef struct s_links
{
    char *name;
    unsigned int *array;
} t_links;

int     read_file(int fd, t_farm *farm);
int     check_link(char *str);
int     check_room(char *str);
int     check_uniq(t_list *list, t_room *room);
int     push_to_list(t_list **alst, t_room *room);
int		fill_adja_table(char *str, t_links *table, int count_room);
t_room	*take_room(char *str);
int		check_link(char *str);