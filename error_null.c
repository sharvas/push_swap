/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_null.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfinnis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 12:54:29 by dfinnis           #+#    #+#             */
/*   Updated: 2019/01/05 12:54:30 by dfinnis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char		*ft_strdup_empty(void)
{
	char	*str;

	str = NULL;
	if (!(str = ft_strdup("")))
		ft_error();
	return (str);
}

char		*ft_strjoinfree_s1_error(char *s1, char *s2)
{
	char	*str;

	str = NULL;
	if (!(str = ft_strjoinfree_s1(s1, s2)))
		ft_error();//need to free string
	return (str);
}
