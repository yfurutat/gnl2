/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efmacm23 <efmacm23@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 20:07:02 by yuske             #+#    #+#             */
/*   Updated: 2025/07/09 03:15:08 by efmacm23         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h> // read()
# include <stdio.h> // FOPEN_MAX
# include <stdlib.h> // ssize_t (#include <stdio.h> でもOK)
# include <errno.h>
# include <limits.h> // SSIZE_MAX
// #include <stdbool.h> //bool
// # include <stdint.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

// #define NOT_FOUND (-1)
// #define NOT_LOOKED (-2)
// #define NULL_PTR (-3)
typedef enum s_error_type
{
	NOT_FOUND = -1,
	NULL_PTR = -2
}	t_err;

// typedef struct s_id
// {
// 	ssize_t	rd_len;
// 	size_t	len;
// 	size_t	i;
// 	char	terminal;
// }	t_id;

char	*get_next_line(int fd);
ssize_t	ft_strchrlen(const char *str, int chr);
void	*ft_bzero(void *mem, size_t num_bytes_to_set_zero);
char	*ft_calloc_for_str(size_t num_bytes_to_allocate);
char	*double_free_null_str(char **str1, char **str2);
void	iter_copy_src_to_dest(char *dest, const char *src, size_t end);
// char	*ft_strjoin(char *s1, char *s2);
// char	*ft_strdup(const char *str);
// char	*ft_strchr(char *s, int c);
// size_t	ft_strlen(const char *str);

#endif