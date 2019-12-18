/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lacollar <lacollar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 13:08:45 by lacollar          #+#    #+#             */
/*   Updated: 2019/12/13 16:11:45 by lacollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 36
# endif

# include <stddef.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>

int		get_next_line(int fd, char **line);
int		index_nwl(char *str);
char	*strjoin_modified(char *s1, char *s2);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*checknl(char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strcpy(char *dst, const char *src);

#endif
