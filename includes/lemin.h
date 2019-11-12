/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 13:55:33 by crenly-b          #+#    #+#             */
/*   Updated: 2019/10/07 23:20:14 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "../libft/includes/libft.h"

typedef struct	s_room
{
	char	*name;
	int		x;
	int		y;
	int		pos;
	int		paint_mark;
	int		*link;
}				t_room;

typedef struct	s_path
{
	int		a_h;
	int		size;
	int		bfs[10000];
	int		*p;
}				t_path;

typedef struct	s_map
{
	t_list	*rooms;
	t_room	*new_room;
	char	**str;
	int		q_rooms;
	int		ants;
	int		s;
	int		e;
	int		lf;
	int		sf;
	int		ef;
	int		temp_x;
	int		temp_y;
	int		max_x;
	int		max_y;
}				t_map;

typedef	struct	s_farm
{
	int		cnt;
	t_room	**arr;
	int		**wl;
	int		*line;
	int		*bfs;
	int		bfs_flag;
	int		mpw;
	int		lwl;
	int		p;
	int		cgp;
}				t_farm;

int				main(int argc, char *argv[]);
char			*ft_validation(t_map *map, t_farm *farm);
int				ft_atoilemin(char *s);
void			ft_atoicoor(char *s);
void			ft_find_start_room(char **line, t_map *map);
void			ft_find_end_room(char **line, t_map *map);
void			ft_find_curr_room(char **line, t_map *map);
void			ft_savelinks(char **line, t_map *map, t_farm *farm);
void			ft_fiil_in_links(t_map *map, t_farm *farm);
void			ft_str_of_names(t_map *map);
void			ft_lem_error(const char *err, char **line);
void			ft_linkserror();
void			ft_input_error();
void			ft_cant_find_way_error();
void			ft_solution(t_map *map, t_farm *farm);
void			ft_str_of_names(t_map *map);
void			ft_create_ways_lines(t_farm *farm);
int				ft_fiil_in_ways_lines(t_farm *farm);
void			ft_create_line(t_farm *farm);
void			ft_fiil_in_line(t_farm *farm);
void			ft_farm_initial(t_farm *farm, t_map *map);
void			ft_print_bfs_potensial(t_farm *farm);
void			ft_print_bfs(t_farm *farm);
void			ft_print_temp_line(t_farm *farm);
void			ft_print_way1(t_map *map, t_farm *farm);
void			ft_bfs(t_room **ar_r, int q_rooms, t_farm *farm);
void			ft_check_and_right_to_wl(t_farm *farm, int number, int pos);
void			ft_bfs_finder(t_farm *farm);
void			split_rev(t_path *path, t_farm *farm);
t_path			*ft_suurballe(t_farm *orgn, t_farm *split,
									t_farm *pfarm, int aunts);
void			olya_write_dfarm(t_farm *farm);
void			add_path(t_path *good, t_farm *farm, int k, t_farm *split);
void			add_link(t_room *room, int new);
void			change_link(t_room *room, int change, int new);
void			delete_link(t_room *room, int del_link);
void			ft_fill_path(t_path *path, int *bfs, int size);
void			olya_write_path(t_path path);
void			olya_write_good(t_path *good, int cgp);
void			ft_clean_links(t_farm *farm);
void			ft_dup_clear_farm(t_farm *pfarm, int n);
void			olya_write_name_path(t_path *save, int k, t_farm *orgn);
void			ft_path_cpy(t_path *save, t_path *good, int k);
void			cpy_paint_mark(t_farm *split, t_farm *pfarm,
													int *change, int num);
void			init_split(t_farm *orgn, t_farm *new);
void			ft_fill_path(t_path *path, int *bfs, int size);
void			ft_clean_links(t_farm *farm);
void			all_split(t_path *good, int k, t_farm *split);
void			dup_link(int *dest_link, int *src_link);
void			back_to_origin(t_farm *farm, t_farm *orgn);
void			write_room(t_room *room);
void			ft_print_result(t_path *ans, t_map *map, int cgp, int ants);
void			ft_one_path_print(t_path *ans, t_map *map, int i, int nant);
void			add_link(t_room *room, int new);
void			ft_mapinitial(t_map *map);
int				search_path(t_room *room);
void			ft_find_end_room(char **line, t_map *map);
void			ft_lstaddlbo(t_list **alst, t_list *new);
void			ft_lstaddend(t_list **alst, t_list *new);
void			ft_new_roominitial(t_map *map);
t_list			*ft_elem_of_rooms(t_map *map);

#endif
