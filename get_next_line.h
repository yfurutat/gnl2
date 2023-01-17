/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuske <yuske@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 20:07:02 by yuske             #+#    #+#             */
/*   Updated: 2023/01/18 01:47:32 by yuske            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
// # include <string.h>
// # include <fcntl.h>
// # include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

typedef struct s_id
{
	ssize_t	rd_len;
	size_t	len;
	size_t	i;
	char	terminal;
}	t_id;

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, int c);
size_t	ft_strlen(const char *str);

#endif