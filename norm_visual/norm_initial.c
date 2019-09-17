#include "lemin.h"

static void init_links_array(int *array, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		array[i] = -1;
		i++;
	}
}

#include <stdio.h>
void initial_farm_array_rooms(t_farm *farm)
{
    t_room *room;
    t_list *list;
    int i;

	if (!(farm->array_rooms = ft_memalloc(sizeof(t_room*) * farm->count_rooms)))
		exit(-1);
    i = 0;
    list = farm->room_list;
    while (list != NULL)
    {
        room = list->content;
        if (!(room->links_array = malloc(sizeof(int) * farm->count_rooms)))
			exit(-1);
        init_links_array(room->links_array, farm->count_rooms);
        room->ind = i;
        farm->array_rooms[i] = room;
        i++;
        list = list->next;
    }
    if (!(farm->array_aunts = ft_memalloc(sizeof(int) * farm->count_aunts)))
		exit(-1);
    i = 0;
    while (i < farm->count_aunts)
    {
        printf(" %d ", i);
        farm->array_aunts[i] = farm->start->ind;
        i++;
    }
}