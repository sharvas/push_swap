
#include "push_swap.h"

void	ft_setmax_b(t_all *all, int if_rotate)
{
	t_stack	*tmp;
	t_stack	*max;
	int		count_rb;
	int		count_rrb;

	tmp = all->b;
	max = all->b;
	count_rb = 0;
	count_rrb = 0;
	while (tmp && tmp->next != all->b)
	{
		if (tmp->n < tmp->next->n)
			max = tmp->next;
		tmp = tmp->next;
	}
	tmp = all->b;
	while (tmp && tmp != max)
	{
		tmp = tmp->next;
		count_rb++;
	}
	tmp = all->b;
	while (tmp && tmp != max)
	{
		tmp = tmp->prev;
		count_rrb++;
	}
	if (count_rb < count_rrb)
	{
		while (if_rotate && all->b != max)
			ft_rb(all);
	}
	else
	{
		while (if_rotate && all->b != max)
			ft_rrb(all);
	}
}

int		ft_isleft(t_all *all, char c)
{
	t_stack *tmp;

	tmp = all->a;
	if (c == '-')
	{
		while (tmp && tmp->next != all->a)
		{
			if (tmp->n <= all->median)
				return (1);
			tmp = tmp->next;
		}
	}
	else if (c == '+')
	{
		while (tmp && tmp->next != all->a)
		{
			if (tmp->n > all->median)
				return (1);
			tmp = tmp->next;
		}
	}
	return (0);
}

int	ft_find_max(t_all *all, char stack)
{
	t_stack		*tmp;
	int		max;
	int		len;

	tmp = (stack == 'a') ? all->a : all->b;
	len = ft_find_len(all, stack);
	max = tmp->n;
	while (len--)
	{
		tmp = tmp->next;
		if (tmp->n > max)
			max = tmp->n;
	}
	return (max);
}

void	ft_rotate_direction(t_all *all, int max)
{
	t_stack	*tmp;
	int		count;

	count = 0;
	tmp = all->b;
	while (tmp->n != max)
	{
		count++;
		tmp = tmp->next;
	}
	if (count <= (ft_find_len(all, 'b') / 2))
		while (all->b->n != max)
			ft_rb(all);
	else
		while (all->b->n != max)
			ft_rrb(all);
}

void	ft_pa_sort(t_all *all)
{
	int		max;

	max = ft_find_max(all, 'b');
	ft_rotate_direction(all, max);
	ft_pa(all);
}

void	ft_sort_v2(t_all *all)
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
	while (tmp--)
	{
		ft_rra(all);
		ft_pb(all);
	}
	size_b = ft_find_len(all, 'b');
	while (size_b--)
		ft_pa_sort(all);
}

void	ft_sort_algo_switch(t_all *all)
{
	if (ft_is_sorted(all, 'a'))
		return ;
	if (ft_find_len(all, 'a') <= 5)
		ft_sort_small(all);
	else
		ft_sort_v2(all);
}

void	ft_push_swap(char **av)
{
	t_all	*all;

	all = NULL;
	all = ft_initialize(all);
	all->display = 1;
	ft_fill_a(all, av);
	ft_find_ref(all);
//	ft_sort(all);
	ft_sort_algo_switch(all);
}

int		main(int ac, char **av)
{
	if (ac == 1)
		ft_push_swap_usage();
	ft_push_swap(av);
	return (0);
}
