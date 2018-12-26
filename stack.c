/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfinnis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 13:19:49 by dfinnis           #+#    #+#             */
/*   Updated: 2018/12/23 13:19:51 by dfinnis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

t_all	*ft_initialize(t_all *all)
{
	if (!(all = (t_all *)malloc(sizeof(t_all))))
		exit(1);
	all->a = NULL;
	all->b = NULL;
	return (all);
}

void	ft_checker(char **argv)
{
	t_all	*all;

	all = NULL;
	all = ft_initialize(all);
	ft_fill_a(all, argv);
//	all = ft_do_ops(all);//
	ft_ko_ok(all);
//	ft_free_all(all);
}

int		main(int argc, char **argv)
{
	if (argc > 1)
		ft_checker(argv);
	return (0);
}

void	ft_fill_a(t_all *all, char **argv)//takes argv and makes a double linked list
{
	int	i;

	i = 1;
	while (argv[i])
		ft_add_end(all, ft_atoi(argv[i++]));
}

void	ft_add_end(t_all *all, int n)
{
	t_stack	**top;
	t_stack	*tmp;

	top = &all->a;
	if (*top)
	{
/*		if (!(*/tmp = (t_stack *)malloc(sizeof(t_stack))/*))*/;
//			ft_error(all);//
		tmp->next = *top;
		tmp->prev = (*top)->prev;
		(*top)->prev = tmp;
		tmp->prev->next = tmp;
		tmp->n = n;
	}
	else
	{
/*		if (!(*/*top = (t_stack *)malloc(sizeof(t_stack))/*))*/;
//			ft_error(all);//
		(*top)->next = *top;
		(*top)->prev = *top;
		(*top)->n = n;	
	}
}

void	ft_ko_ok(t_all *all)
{
	if (ft_is_sorted(all))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
}

int		ft_is_sorted(t_all *all)
{
	t_stack	*tmp;

	if (!all->a || all->b)
		return (0);
	tmp = all->a;
	while (tmp->next != all->a)
	{
		if (tmp->n > tmp->next->n)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

// void	ft_debug_v()//prints the stack's status
// {
// 	printf("%s\n", "a:\t|\tb:");
// 	printf("%d\t|\tb:\n",)
// 	while (a->next != top->next)
// 	printf("%")
// }//convert printf to ft_printf


// void	ft_del_top()
// {

// }

// void	ft_add_top(t_all *all, int n)
// {
// 	t_stack	*tmp;

	
// }