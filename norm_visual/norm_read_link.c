#include "lemin.h"

#include <stdio.h>
static void search_rooms(char *str, t_list *list, t_room **room1, t_room **room2)
{
	int wrdlen;
	char *separator;
	t_room *room;

	separator = ft_strchr(str, '-');
	wrdlen = separator - str;
	separator++;
    *room1 = NULL;
	*room2 = NULL;
   // write(1, str, wrdlen);
   // write(1, separator, wrdlen);
    room = list->content;
    //printf("str = %s", str);
   // printf("list = %p, room1 = %p, room2 = %p\n", list, *room1, *room2);
	while (list != NULL && (*room1 == NULL || *room2 == NULL))
	{
       // printf("hoo\n");
		room = list->content;
        //ft_putstr(room->name);
       // printf("\n");
		if (ft_strnequ(str, room->name, wrdlen))
			*room1 = room;
		if (ft_strequ(separator, room->name))
			*room2 = room;
		list = list->next;
	}
  //  printf("r1 = %s, r2 = %s\n", (*room1)->name, (*room2)->name);
   // printf("room1 = %p, room2 = %p\n", *room1, *room2);
	if (*room1 == NULL || *room2 == NULL)
		ft_error("bad_link\n");
}

void find_link(char *str, t_farm *farm)
{
	t_room *room1;
	t_room *room2;
	int i;

	search_rooms(str, farm->room_list, &room1, &room2);
	if (room1 == room2)
		ft_error("loop\n");
    printf("find_link  %s, %s\n", room1->name, room2->name);
    
	i = 0;
	while (room1->links_array[i] != -1 && room1->links_array[i] != room2->ind)
		i++;
	if (room1->links_array[i] == -1)
		room1->links_array[i] = room2->ind;
	i = 0;
	while (room2->links_array[i] != -1 && room2->links_array[i] != room1->ind)
		i++;
	if (room2->links_array[i] == -1)
		room2->links_array[i] = room1->ind;
   // printf("!!!!!!!!!!!!!!!!!!!!!!!!r1 = %s, r2 = %s\n", (room1)->name, (room2)->name);
}