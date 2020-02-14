/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gariadno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 13:58:09 by gariadno          #+#    #+#             */
/*   Updated: 2020/02/14 14:20:46 by gariadno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	char			*str;

	str = (char *)s;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (&str[i]);
		i++;
	}
	if (c == 0)
		return (&str[i]);
	return (0);
}

static	void	ft_strdel(char **str)
{
	if (*str && str)
	{
		free(*str);
		*str = NULL;
	}
}

static	int		result(char **line, char **readed_line, int fd, int readed)
{
	int		len;
	char	*tmp;

	if (readed < 0)
		return (-1);
	else if (readed == 0 && readed_line[fd] == NULL &&
		(*line = ft_strdup("")))
		return (0);
	len = 0;
	while (readed_line[fd][len] != '\n' && readed_line[fd][len] != '\0')
		len++;
	if (readed_line[fd][len] == '\n')
	{
		*line = ft_substr(readed_line[fd], 0, len);
		tmp = ft_strdup(&readed_line[fd][len + 1]);
		free(readed_line[fd]);
		readed_line[fd] = tmp;
		if (readed_line[fd][0] == '\0')
			ft_strdel(&readed_line[fd]);
		return (1);
	}
	*line = ft_strdup(readed_line[fd]);
	ft_strdel(&readed_line[fd]);
	return (0);
}

int				get_next_line(int fd, char **line)
{
	static char *readed_line[OPEN_MAX];
	char		*buff;
	int			readed;
	char		*tmp;

	if (fd < 0 || line == NULL || BUFFER_SIZE < 1)
		return (-1);
	if (!(buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char))))
		return (-1);
	while ((readed = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[readed] = '\0';
		if (!(readed_line[fd]))
			readed_line[fd] = ft_strdup(buff);
		else
		{
			tmp = ft_strjoin(readed_line[fd], buff);
			free(readed_line[fd]);
			readed_line[fd] = tmp;
		}
		if (ft_strchr(buff, '\n'))
			break ;
	}
	free(buff);
	return (result(line, readed_line, fd, readed));
}
