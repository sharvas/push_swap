/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaskeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 14:52:16 by svaskeli          #+#    #+#             */
/*   Updated: 2019/01/09 11:00:02 by svaskeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_get_line(char **line, char *str, char **mem)
{
	char	*tmp;

	tmp = NULL;
	if (ft_strchr(str, '\n') == NULL)
	{
		tmp = *line;
		if (!(*line = ft_strjoin(*line, str)))
			return (-1);
		free(tmp);
		if (str)
			free(str);
		str = NULL;
	}
	else
	{
		*mem = ft_strchr(str, '\n') + 1;
		*ft_strchr(str, '\n') = '\0';
		tmp = *line;
		if (!(*line = ft_strjoin(*line, str)))
			return (-1);
		free(tmp);
		if (str)
			free(str);
		str = NULL;
		return (1);
	}
	return (0);
}

int	get_next_line(const int fd, char **line)
{
	char	*mem;
	char	*s;
	int		k;

	if (line == NULL || fd < 0)
		return (-1);
	if (!(*line = ft_strdup("")))
		return (-1);
	mem = NULL;
	k = 1;
	if (mem)
		if (ft_get_line(line, mem, &mem) == 1)
			return (1);
	while (k > 0)
	{
		if (!(s = ft_strnew(1)))
			return (-1);
		if ((k = read(fd, s, 1)) == -1)
			return (-1);
		if (ft_get_line(line, s, &mem) == 1)
			return (1);
		if (k == 0 && !*line[0])
			return (0);
		else if (k == 0 && *line[0])
			return (1);
	}
	return (-1);
}
