/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfinnis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 10:41:55 by dfinnis           #+#    #+#             */
/*   Updated: 2018/11/15 10:41:57 by dfinnis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_list	*get_fd(t_list **stat, int fd)
{
	t_list	*tmp;

	tmp = *stat;
	while (tmp)
	{
		if (tmp->content_size == (size_t)fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew(NULL, 0);
	tmp->content_size = fd;
	tmp->content = ft_strnew(0);
	ft_lstadd(stat, tmp);
	return (tmp);
}

int				get_last_line(char **line, char *content, char *str, int ret)
{
	char	*tmp;

	if (ret == 0)
		free(str);
	if (!content)
		return (0);
	tmp = ft_strchr(content, '\n');
	if (tmp)
	{
		*tmp = '\0';
		*line = ft_strdup(content);
		tmp = tmp + 1;
		ft_strcpy(content, tmp);
		return (1);
	}
	else if (ft_strlen(content) > 0)
	{
		*line = ft_strdup(content);
		*content = '\0';
		return (1);
	}
	return (0);
}

int				free_gnl(char *str, int n)
{
	free(str);
	return (n);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*stat;
	t_list			*tmp;
	char			*str;
	int				ret;

	if (fd < 0 || !line || BUFF_SIZE <= 0)
		return (-1);
	if (!stat)
		stat = get_fd(&stat, fd);
	tmp = get_fd(&stat, fd);
	str = ft_strnew(BUFF_SIZE);
	while (!(ft_strchr(str, '\n')))
	{
		ret = read(fd, str, BUFF_SIZE);
		if (ret == -1)
			return (free_gnl(str, -1));
		if (ret == 0)
			return (get_last_line(line, tmp->content, str, ret));
		str[ret] = '\0';
		*line = ft_strjoin(tmp->content, str);
		free(tmp->content);
		tmp->content = *line;
	}
	free(str);
	return (get_last_line(line, tmp->content, str, ret));
}
