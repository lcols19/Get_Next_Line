/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lacollar <lacollar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 13:08:55 by lacollar          #+#    #+#             */
/*   Updated: 2019/12/13 16:11:37 by lacollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		strlen_modified(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int			index_nwl(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char		*ft_strcpy(char *dst, const char *src)
{
	size_t	i;

	if (!src)
		return (0);
	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char		*strjoin_modified(char *s1, char *s2)
{
	char		*str;
	size_t		len_s1;
	size_t		len_s2;

	if (!s1)
		len_s1 = 0;
	if (!s2)
		len_s2 = 0;
	len_s1 = strlen_modified(s1);
	len_s2 = strlen_modified(s2);
	if (!(str = (char*)malloc(sizeof(char) * (len_s1 + len_s2 + 1))))
		return (NULL);
	len_s1 = 0;
	len_s2 = 0;
	while (s1 && s1[len_s1])
	{
		str[len_s1] = s1[len_s1];
		len_s1++;
	}
	while (s2[len_s2] && s2[len_s2] != '\n')
		str[len_s1++] = s2[len_s2++];
	str[len_s1] = 0;
	free(s1);
	return (str);
}

char		*checknl(char *str)
{
	size_t		i;

	i = 0;
	while (i <= strlen_modified(str))
	{
		if (str[i] == '\n')
			return (str + i + 1);
		i++;
	}
	return (0);
}
