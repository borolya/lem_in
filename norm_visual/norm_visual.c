#include "lemin.h"
#include "visu.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <stdio.h>
void initialisation(t_visu *visu)
{
	visu->mlx_ptr = mlx_init();
	visu->win_ptr = mlx_new_window(visu->mlx_ptr, WIN_W, WIN_H, "HEX");
	visu->links = NULL;
}

void fill_points(t_link *link)//add ft_abs to lib
{
	//printf("r1 = %d, r2 = %d\n", link->room1->crd.x, link->room1->crd.y);
	
	link->p.x = link->room1->crd.x;
	link->p.y = link->room1->crd.y;
	link->delta.x = (link->room1->crd.x - link->room2->crd.x) / STEPS;
	link->delta.y = (link->room1->crd.y - link->room2->crd.y) / STEPS;

}

char *handle_str(char *str, t_farm *farm, t_link *link)
{
	int numb;
	int i;
	int len;
	char *tmp;

	if (str[0] != 'L')
		ft_error("bad_moved");//free all
	str++;
	numb = ft_atoi(str);
	if (numb >= farm->count_aunts)
		ft_error("bad_aunt_numb\n");
	//printf("numb = %d\n", numb);
	tmp = NULL;
	link->room1 = farm->array_rooms[farm->array_aunts[numb]];
	//printf("r1 = %s\n", link->room1->name);
	str = ft_strchr(str, '-');
	str++;
	tmp = ft_strchr(str, ' ');
	if (tmp != NULL)
		len = tmp - str;
	else
		len = ft_strlen(str);
	i = 0;
	while (!ft_strnequ(str, farm->array_rooms[i]->name, len))
		i++;
	
	if (i < farm->count_rooms)
		link->room2 = farm->array_rooms[i];
	else
		ft_error("aunt go to nowhere");
	//printf("r2 = %s\n", link->room2->name);
	fill_points(link);
	if (tmp != '\0')
		tmp++;
	//printf("r1 = %s, r2 = %s\n", link->room1->name, link->room2->name);
	return (tmp);
}
#include <stdio.h>

int step_init(int keycode, t_visu *visu)
{
	t_link link;
	char *save;
	char *str;
	t_list *list;
	t_link *plink;

	if (keycode == 53)
	{
		//free_all;
		exit(1);
	}
	else if (keycode == 49)
	{
		if (get_next_line(visu->fd, &str))
		{
			printf("str = %s\n", str);
			save = str;
			while (save != NULL)
			{
				save = handle_str(save, visu->farm, &link);
				if (!(list = ft_lstnew(&link, sizeof(t_link))))
					exit(-1);
				ft_lstadd(&(visu->links), list);
				//printf("p = %p\n", visu->links);
			}
			free(str);
			list = visu->links;
			while (list != NULL)
			{
				plink = list->content;
				printf("r1 = %s, r2 = %s\n", plink->room1->name, plink->room2->name);
				list = list->next;
			}
			//change count aunt in room
			visu->step = STEPS;
		}
		else 
			visu->step = 0;
	}
	return (0);
}

void draw_aunt(t_link *link, t_visu *visu)
{
	mlx_put_image_to_window(visu->mlx_ptr, visu->win_ptr, visu->aunt.ptr, link->p.x, link->p.y);
	link->p.x += link->delta.x;
	link->p.y = link->delta.y;
	if (visu->step == 0)
	{
		free(link);
		link = NULL;
	}
}

void draw_hex(t_visu *visu)
{
	//add list of rooms and aunt
	mlx_put_image_to_window(visu->mlx_ptr, visu->win_ptr, visu->hex.ptr, 0, 0);
}

void ft_lstfree(t_list **alst)
{
	t_list *lst;
	t_list *next;

	if (alst)
		return;
	lst = (*alst);
	while (lst)
	{
		free((t_link*)(lst->content));
		next = lst->next;
		free(lst);
		lst = next;
	}
	*alst = NULL;
}

int dinamic(t_visu *visu)
{
	t_list *link;

	visu->step = 10;	
	draw_hex(visu);
	//mlx_clear_window(visu->mlx_ptr, visu->win_ptr);
	mlx_put_image_to_window(visu->mlx_ptr, visu->win_ptr, visu->hex.ptr, 0, 0);
	if (visu->step >= 0)
	{
		link = visu->links;
		mlx_clear_window(visu->mlx_ptr, visu->win_ptr);
		draw_hex(visu);
		while (link != NULL)
		{
			draw_aunt(link->content, visu);
			link = link->next;
		}
		visu->step--;
		if (visu->step < 0)
			ft_lstfree(&(visu->links));
	}
	return (0);
}

void imag_initialisation(t_img *hex, t_img *aunt, t_visu *visu)
{
	int i;

	hex->h = HEX_W;
	hex->w = HEX_H;
	hex->ptr = mlx_new_image (visu->mlx_ptr, HEX_W, HEX_H);
	hex->data = (int*)mlx_get_data_addr(hex->ptr, &hex->bits_per_pixel, &hex->h, &hex->endian);
	hex_img(hex, visu->farm);
	aunt->h = 5;
	aunt->w = 5;
	aunt->ptr = mlx_new_image(visu->mlx_ptr, aunt->w, aunt->h);
	aunt->data = (int*)mlx_get_data_addr(aunt->ptr, &aunt->bits_per_pixel, &aunt->h, &aunt->endian);
	i = 0;
	while (i < 25)
	{
		aunt->data[i] = 100;
		i++;
	}
}

#include <stdio.h>

int main(int argc, char **argv)
{
	t_farm farm;
	t_visu visu;
	t_img	aunt;
	t_img	hex;
	int fd;

	if (argc == 1)
		fd = 0;
	else
		fd = open(argv[1], O_RDONLY);
	read_data(fd, &farm);//add aunts_to room struct//read to \n
	
    initialisation(&visu);
	visu.farm = &farm;
	visu.fd = fd;
	visu.step = 100;
	
		//write_farm(&farm);
	imag_initialisation(&hex, &aunt, &visu);
	visu.aunt = aunt;
	visu.hex = hex;
	mlx_key_hook(visu.win_ptr, &step_init, &visu);
	mlx_loop_hook(visu.mlx_ptr, &dinamic, &visu);
 	mlx_loop(visu.mlx_ptr);
}