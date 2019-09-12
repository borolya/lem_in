#include "libft.h"
#include "lemin.h"

void rotate_left(t_tree *x)
{
	t_tree *y;
	t_tree *p;

	p = x->p;
	y = x->right;
	y->p = x->p; 
	if (p->right == x)
		p->right = y;
	else
		p->left = y;
	if (y == NULL)
	{
		write(1, "my mist\n", 8);
		exit(1);
	}
	x->right = y->left;
	if (y->left != NULL)
		y->left->p = x;
	y->left = x;
	x->p = y;
}

void rotate_right(t_tree *x)
{
	t_tree *y;
	t_tree *p;

	p = x->p;
	y = x->left;
	y->p = x->p; 
	if (p->right == x)
		p->right = y;
	else
		p->left = y;
	if (y == NULL)
	{
		write(1, "my mist\n", 8);
		exit(1);
	}
	x->left = y->right;
	if (y->right != NULL)
		y->right->p = x;
	y->right = x;
	x->p = y;
}

t_tree *find_parent(t_tree *root, t_room *room)//exit(1) if dublicate
{
	t_tree *parent;

	parent = NULL;
	while (root != NULL)
	{
		parent = root;
		if (ft_strcmp(room->name, root->content->name) == 0)
		{
			ft_error("dublicate_name\n");
		}
		else if (ft_strcmp(room->name, root->content->name) > 0)
			root = root->right;
		else
			root = root->left;
	}
	return (parent);
}

t_room *ft_search_init_array(char *str, t_farm *farm, int n, int *ind)
{
	t_tree *tree;
	t_room *room;
	
	tree = farm->root;
	while (tree != NULL && !ft_strnequ(tree->content->name, str, n))
	{
		if (ft_strncmp(str, tree->content->name, n) > 0)
			tree = tree->right;
		else
			tree = tree->left;
	}
	if (tree == NULL)
		ft_error("link of no existing room\n");
	//write(1, "fff", 3);
	//init
	room = tree->content;
	if (room->ind < 0)
	{
		room->ind = *ind;
		if (!(room->links_array = malloc(sizeof(int) * farm->count_rooms)))
			exit(-1);
		init_links_array(room->links_array, farm->count_rooms);
        farm->array_rooms[*ind] = room;
		(*ind)++;
	}
	return(room);
}

void tree_insert(t_tree **root, t_tree *parant, t_room *room)
{
	t_tree *new;

	//if (room == NULL)
	//	exit(-1);
	if (!(new = ft_memalloc(sizeof(t_tree))))
		exit(-1);
	new->content = room;
	new->right = NULL;
	new->left = NULL;
	new->p = NULL;
	new->color = 0;
	if (parant == NULL)
	{
		*root = new;
		return;
	}
	if (ft_strcmp(new->content->name, parant->content->name) > 0)
		parant->right = new;
	else
		parant->left = new;
	//if ()
	//balance_tree(root);
}
