/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgerold- <vgerold-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 16:44:24 by vgerold-          #+#    #+#             */
/*   Updated: 2020/01/18 18:05:31 by vgerold-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_strlen_ld(char *s, char delimeter)
{
	long length;

	length = 0;
	while (s[length] && s[length] != delimeter)
		length++;
	return (length);
}

char	*ft_linesave(char *src, int line_len)
{
	char *tmp;

	tmp = ft_strdup(src + line_len + 1);
	free(src);
	return (tmp);
}

t_list	*ft_file_lst(t_list **file_lst, int fd)
{
	t_list			*tmp_lst;

	tmp_lst = *file_lst;
	while (tmp_lst)
	{
		if (tmp_lst->content_size == (size_t)fd)
			return (tmp_lst);
		tmp_lst = tmp_lst->next;
	}
	tmp_lst = ft_lstnew("\0", 1);
	tmp_lst->content_size = (size_t)fd;
	ft_lstadd(file_lst, tmp_lst);
	tmp_lst = *file_lst;
	return (tmp_lst);
}

char	**lineset(char **line, t_list *buflst)
{
	long			line_len;

	line_len = ft_strlen_ld(buflst->content, '\n');
	*line = ft_strnew((size_t)line_len);
	*line = ft_strncpy(*line, buflst->content, line_len);
	if ((size_t)line_len == ft_strlen(buflst->content))
		ft_strclr(buflst->content);
	else
		buflst->content = ft_linesave(buflst->content, line_len);
	return (line);
}

int		get_next_line(const int fd, char **line)
{
	ssize_t			response;
	char			buf[BUFF_SIZE + 1];
	t_list			*buflst;
	static	t_list	*file_lst;

	if (fd < 0 || line == NULL)
		return (-1);
	buflst = ft_file_lst(&file_lst, fd);
	if (!ft_strchr(buflst->content, '\n'))
	{
		while ((response = read(fd, &buf, BUFF_SIZE)) > 0)
		{
			buf[response] = '\0';
			buflst->content = ft_strrejoin((char*)buflst->content, buf);
			if (ft_strchr(buf, '\n'))
				break ;
		}
		if (response == -1)
			return (-1);
	}
	if (!ft_strlen(buflst->content))
		return (0);
	lineset(line, buflst);
	return (1);
}
