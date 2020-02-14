/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gariadno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 14:18:10 by gariadno          #+#    #+#             */
/*   Updated: 2020/02/14 14:18:14 by gariadno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*ori;
	char	*desty;

	if (!dst && !src)
		return (NULL);
	i = 0;
	desty = (char *)dst;
	ori = (char *)src;
	while (i < n)
	{
		desty[i] = ori[i];
		i++;
	}
	return (desty);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;

	if (!s1 || !(str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	ft_memcpy(str, s1, ft_strlen(s1));
	ft_memcpy(str + ft_strlen(s1), s2, ft_strlen(s2));
	str[ft_strlen(s2) + ft_strlen(s1)] = '\0';
	return (str);
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	i;

	if (!(str = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*str;

	if (!s || !(str = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (s[start + i] && i < len && start < ft_strlen(s))
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
