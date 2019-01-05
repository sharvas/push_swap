
#include "push_swap.h"

void	ft_read_args_ps(t_all *all, char **argv)
{
	int		i;

	i = 1;
	if (ft_strcmp(argv[i], "-f") == 0)
	{
		i++;
		all->f = argv[i++];
	}
	ft_fill_a(all, argv, i);
}

void	ft_find_refs(t_all *all)
{
	t_stack		*cpy;

	all->len = ft_find_len(all, 'a');
	cpy = ft_dublicate_list(all);
	ft_simple_sort(cpy);
	all->min = cpy->n;
	all->one_third = ft_find_ref(cpy, (all->len / 3));
	all->two_thirds = ft_find_ref(cpy, ((all->len / 3) * 2));
	all->one_seventh = ft_find_ref(cpy, (all->len / 7));
	all->two_sevenths = ft_find_ref(cpy, ((all->len / 7) * 2));
	all->three_sevenths = ft_find_ref(cpy, ((all->len / 7) * 3));
	all->four_sevenths = ft_find_ref(cpy, ((all->len / 7) * 4));
	all->five_sevenths = ft_find_ref(cpy, ((all->len / 7) * 5));
	all->six_sevenths = ft_find_ref(cpy, ((all->len / 7) * 6));
	while (cpy->next)
		cpy = cpy->next;
	all->max = cpy->n;
	while (cpy->prev)
		cpy = cpy->prev;
	ft_free_stack(cpy);
}

int		ft_find_ref(t_stack *cpy, int count)
{
	int	n;
	t_stack *top;

	top = cpy;
	while (count--)
		cpy = cpy->next;
	n = cpy->n;
	cpy = top;
	return(n);
}

void	ft_putfile(t_all *all)
{
	int	fd;

	if((fd = open(all->f, O_RDWR|O_CREAT|O_EXCL, 0666)) < 0)
		ft_error();//usage??
	if((write(fd, all->instructions, ft_strlen(all->instructions))) < 0)
		ft_error();//usage??
	close(fd);
}

void	ft_push_swap(char **av)
{
	t_all	*all;

	all = NULL;
	all = ft_initialize(all);
	all->write_instructions = 1;
	ft_read_args_ps(all, av);
	ft_find_refs(all);
	ft_sort_algo_switch(all);
	ft_condense_verbose(all);
	if (!all->f)
		ft_putstr(all->instructions);
	else
		ft_putfile(all);
	ft_free_all(all);
}

int		main(int ac, char **av)
{
	if (ac == 1 || ((ac == 2 || ac == 3) && (ft_strcmp(av[1], "-f") == 0)))
		ft_push_swap_usage();
	ft_push_swap(av);
	return (0);
}
