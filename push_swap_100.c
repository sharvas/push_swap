
#include "push_swap.h"

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
	t_stack	*tmp;
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

void	ft_sort(t_all *all)
{
	int		size_a;
	int		size_b;
	int 	tmp;

	size_a = ft_find_len(all, 'a');
	while (size_a--)
	{
		if (all->a->n >= all->median)
			ft_pb(all);
		else
			ft_ra(all);
	}
	size_b = ft_find_len(all, 'b');
	tmp = all->len - size_b;
	while (size_b--)
		ft_pa_sort(all);
	while (all->a->n >= all->median)
		ft_ra(all);
	while (tmp--)
		ft_pb(all);
	size_b = ft_find_len(all, 'b');
	while (size_b--)
		ft_pa_sort(all);
	while (all->a->n != all->min)
		ft_rra(all);
}

int		ft_sort_module(t_all *all, int size, int start, int end)
{
	int		size_b;
	int 	next_size;

	while (all->a->n > end)
		ft_ra(all);
	while (size--)
	{
		if (all->a->n >= start && all->a->n < end)
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

void	ft_sort_big(t_all *all)
{
	int		size_a;
	int 	tmp1;
	int		tmp2;
	int		tmp3;
	int		tmp4;

	size_a = ft_find_len(all, 'a');
	tmp1 = ft_sort_module(all, size_a, all->three_qu, all->max);
	tmp2 = ft_sort_module(all, all->len - tmp1, all->median, all->three_qu);
	tmp3 = ft_sort_module(all, all->len - tmp1 - tmp2, all->qu, all->median);
	tmp4 = ft_sort_module(all, all->len - tmp1 - tmp2 - tmp3, all->min, all->qu);
	while (all->a->n != all->min)
		ft_ra(all);
}

void	ft_sort_algo_switch(t_all *all)
{
	if (ft_is_sorted(all, 'a'))
		return ;
	else if (ft_find_len(all, 'a') <= 5)
		ft_sort_small(all);
	else if (ft_find_len(all, 'a') > 100)
		ft_sort_big(all);
	else
		ft_sort(all);
}

void	ft_push_swap(char **av)
{
	t_all	*all;

	all = NULL;
	all = ft_initialize(all);
	all->display = 1;
	ft_fill_a(all, av);
	ft_find_ref(all);
	ft_sort_algo_switch(all);
}

int		main(int ac, char **av)
{
	if (ac == 1)
		ft_push_swap_usage();
	ft_push_swap(av);
	return (0);
}
