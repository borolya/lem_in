#include "libft.h"

#ifndef ERROR 
    #define ERROR write(2, "Error\n", 6);/ exit(1);
#endif

typedef struct s_tree
{
    t_room *content;
    t_tree *left;
    t_tree *right;
    t_tree *p;
}   t_tree;

typedef struct s_farm
{
	int aunts;
    int count_rooms;
	t_list *lst_rooms;
    t_room *array_rooms;
	unsigned int **links_tab;// change bit
} t_farm;

typedef struct s_room
{
    int ind;
	char *name;
	int x;
	int y;
    int start;
    int finish;
    int *links_array;
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