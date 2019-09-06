#include <stdio.h>
#include "libft.h"
#include "lemin.h"

int main(int argc, char **argv)
{
	int i;
	char *str;
	t_farm farm;

	read_data(0, farm);
	do_instructions(0, farm);
	return (0);
}