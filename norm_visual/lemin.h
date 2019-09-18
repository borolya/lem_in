#ifndef LEMIN_H
# define LEMIN_H

#include "libft.h"

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
	int *links_array;
	int aunts;
}   t_room;

typedef struct s_farm
{
	int count_aunts;
	int *array_aunts;
	int count_rooms;
	t_room *start;
	t_room *finish;
	t_list *room_list;
	t_room *(*array_rooms);
	t_point min_crd;
	t_point max_crd;
	//unsigned int **links_tab;// change bit
} t_farm;

typedef struct s_command
{
	int start : 1;
	int finish : 1;
}   t_command;

void    read_data(int fd, t_farm *farm);
int     check_comment(char *str);
int     check_link(char *str);
int		check_command(char *str);
int		check_room(char *str);
void    ft_error(char *error_name);
void	initial_farm_array_rooms(t_farm *farm);
t_room	*add_room_to_list(t_farm *farm, char *str);
void	find_link(char *str, t_farm *farm);
void	take_command(int fd, t_command *command, char *str, t_farm *farm);

void    write_farm(t_farm *farm);
void    write_room(t_room *room);
#endif





/*

void    take_aunts(char *str, t_farm *farm);
//void	take_command(t_command *command, char *str, t_farm *farm, t_tree **root, int fd);
int		take_name(char *str, t_room *room);
t_room	*take_room(char *str);
void    ft_error();
int     read_file(int fd, t_farm *farm);
int     check_link(char *str);
int     check_comment(char *str);
int     check_command(char *str);
int     check_room(char *str);
int     check_uniq(t_list *list, t_room *room);
int     push_to_list(t_list **alst, t_room *room);
int		fill_adja_table(char *str, t_links *table, int count_room);
int		check_link(char *str);


void    read_data(int fd, t_farm *farm);
t_tree	*find_parent(t_tree *root, t_room *room);
t_room	*ft_room(t_farm *farm, t_tree **root, char *str);
t_room	*ft_search_init_array(char *str, t_farm *farm, int n, int *ind);
int		search_coordinates(int x, int y, t_tree *root);

void	tree_insert(t_tree **root, t_tree *parant, t_room *room);
void	find_link(char *str, t_farm *farm, int *ind);
void	init_links_array(int *array, int size);
void	initial_array_rooms(t_farm *farm, int *ind);
void	initial_ltab(t_farm *farm);
int		search_coordinates(int x, int y, t_tree *root);
char	*read_rooms(int fd, t_farm *farm, t_command *command, t_tree **root);
*/