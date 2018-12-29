/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfinnis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 15:47:46 by dfinnis           #+#    #+#             */
/*   Updated: 2018/08/29 15:48:04 by dfinnis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>//

static int	ft_count_words(char *str)
{
	int	i;
	int	count;
	int	word;

	i = 0;
	count = 0;
	word = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		while (str[i] && (str[i] != ' ' && !(str[i] >= 9 && str[i] <= 13)))
		{
			i++;
			word = 1;
		}
		while (str[i] && (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
			i++;
		if (word == 1)
			count++;
		word = 0;
	}
	printf("word count: %d\n", count);//
	return (count);
}

static int	ft_word_length(char *str, int i)
{
	int	count;

	count = 0;
	while (str[i] != ' ' && !(str[i] >= 9 && str[i] <= 13))
	{
		count++;
		i++;
	}
	printf("word length: %d\n", count);//
	return (count);
}

char		**ft_split_whitespaces(char *str)
{
	int		i;
	int		j;
	int		k;
	char	**res;

	i = 0;
	j = 0;
	if (!(res = (char **)malloc(sizeof(char *) * (ft_count_words(str) + 1))))
		return (NULL);
	while (str[i])
	{
		k = 0;
		while (str[i] && (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
			i++;
		if (!str[i])
			break ;
		if (!(res[j] = (char *)malloc(sizeof(char) * (ft_word_length(str, i) + 1))))
			return (NULL);
		while (str[i] && (str[i] != ' ' && !(str[i] >= 9 && str[i] <= 13)))
			res[j][k++] = str[i++];
		res[j][k] = '\0';
		j++;
	}
	res[j] = NULL;
	return (res);
}
