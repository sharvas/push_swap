
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

void	ft_rotate_direction(t_all *all, int num, int direction)
{
	if (direction > 0)
		while (all->b->n != num)
			ft_rb(all);
	else
		while (all->b->n != num)
			ft_rrb(all);
}

int		ft_up_down(t_all *all, int num)
{
	t_stack	*tmp;
	int		count;
	int 	len;

	count = 0;
	tmp = all->b;
	while (tmp->n != num)
	{
		count++;
		tmp = tmp->next;
	}
	if (count <= ((len = ft_find_len(all, 'b')) / 2))
		return (count);
	else
		return ((len - count) * -1);
}

int		ft_min_max(t_all *all, int max, int min)
{
	int		count_max;
	int		count_min;
	int		max_direction;
	int		min_direction;

	count_max = ft_up_down(all, max);
	count_min = ft_up_down(all, min);
	max_direction = 1;
	min_direction = 1;
	if (count_max < 0)
	{
		count_max = -count_max;
		max_direction = -1;
	}
	if (count_min < 0)
	{
		count_min = -count_min;
		min_direction = -1;
	}
	if (count_max > (count_min + 1))
	{
		ft_rotate_direction(all, min, min_direction);
		return (-1);
	}
	else
	{
		ft_rotate_direction(all, max, max_direction);
		return (1);
	}
}

void	ft_pushback(t_all *all, int min_max)
{
	if (min_max > 0)
		ft_pa(all);
	else
	{
		ft_pa(all);
		ft_ra(all);
	}
}

void	ft_pa_sort(t_all *all)
{
	int	max;
	int	min;
	int	min_max;

	max = ft_find_max(all, 'b');
	min = ft_find_min(all, 'b');
	min_max = ft_min_max(all, max, min);
	ft_pushback(all, min_max);
}

int		ft_sort_module(t_all *all, int size, int start, int end)
{
	int		size_b;
	int 	next_size;

	if (size < all->len / 2)
	{
		while (all->a->n > end)
			ft_rra(all);
		while (all->a->n <= end)
			ft_rra(all);
		size++;
	}
	else
		while (all->a->n > end)
			ft_ra(all);
	while (size--)
	{
		if (all->a->n > start && all->a->n <= end)
			ft_pb(all);
		else
			ft_ra(all);
	}
	size_b = ft_find_len(all, 'b');
	next_size = size_b;
	while (size_b--)
		ft_pa_sort(all);
	return (next_size);
}

void	ft_sort_100(t_all *all)
{
	int		size_a;
	int 	tmp;

	size_a = ft_find_len(all, 'a');
	tmp = ft_sort_module(all, size_a, all->two_thirds, all->max);
	tmp = tmp + ft_sort_module(all, size_a - tmp, all->one_third, all->two_thirds);
	tmp = tmp + ft_sort_module(all, size_a - tmp, all->min, all->one_third);
	while (all->a->n != all->min)
		ft_rra(all);
}

void	ft_sort_big(t_all *all)
{
	int		size_a;
	int 	tmp;

	size_a = ft_find_len(all, 'a');
	tmp = ft_sort_module(all, size_a, all->six_sevenths, all->max);
	tmp = tmp + ft_sort_module(all, size_a - tmp, all->five_sevenths, all->six_sevenths);
	tmp = tmp + ft_sort_module(all, size_a - tmp, all->four_sevenths, all->five_sevenths);
	tmp = tmp + ft_sort_module(all, size_a - tmp, all->three_sevenths, all->four_sevenths);
	tmp = tmp + ft_sort_module(all, size_a - tmp, all->two_sevenths, all->three_sevenths);
	tmp = tmp + ft_sort_module(all, size_a - tmp, all->one_seventh, all->two_sevenths);
	tmp = tmp + ft_sort_module(all, size_a - tmp, all->min, all->one_seventh);
	while (all->a->n != all->min)
		ft_rra(all);
}

void	ft_sort_algo_switch(t_all *all)
{
	if (ft_is_sorted(all, 'a'))
		return ;
	else if (ft_find_len(all, 'a') <= 5)
		ft_sort_small(all);
	else if (ft_find_len(all, 'a') > 101)
		ft_sort_big(all);
	else
		ft_sort_100(all);
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
	ft_find_ref(all);
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
