#include "lemin.h"
#include <stdio.h>

void write_room(t_room *room)
{
	int i;
	int *links_array;

	printf("name = |%s|, ind = %d , x = %d, y = %d st = %d,  en = %d\n", room->name, room->ind, 
			room->crd.x, room->crd.y, room->start, room->finish);
	i = 0;
	links_array = room->links_array;
	printf("links ");
	while (links_array[i] != -1)
	{
		printf("%d ", links_array[i]);
		i++;
	}
	printf("\n");
}

void write_farm(t_farm *farm)
{
	int i;

	i = 0;
	printf("\nWRITE\ncout_room = %d\n", farm->count_rooms);
	while (i < farm->count_rooms)
	{
		write_room(farm->array_rooms[i]);
		i++;
	}
	i = 0;
	printf("count_aunt = %d\n", farm->count_aunts);
	while (i < farm->count_aunts)
	{
		printf(" %d ", farm->array_aunts[i]);
		i++;
	}
    printf("\nEND WRITE\n");
}