/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuske <yuske@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 20:07:37 by yuske             #+#    #+#             */
/*   Updated: 2023/01/18 01:28:00 by yuske            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// // 8L
// char	*ft_strchr(char *str, int chr)
// {
// 	if (str != NULL)
// 	{
// 		while (*str != (unsigned char)chr && *str != '\0')
// 			str++;
// 		if (*str == (unsigned char)chr)
// 			return ((char *)str);
// 	}
// 	return (NULL);
// }

// //6L
// size_t	ft_strlen(const char *str)
// {
// 	size_t	len;

// 	len = 0;
// 	while (str != NULL && str[len] != '\0')
// 		len += 1;
// 	return (len);
// }

#include <stdbool.h> //bool
#include <stdio.h> // ssize_t (#include <stdlib.h> でもOK)
#include <limits.h> // SSIZE_MAX

// #define NOT_FOUND (-1)
// #define NOT_LOOKED (-2)
// #define NULL_PTR (-3)

typedef enum s_error_type
{
	NOT_FOUND = -1,
	NULL_PTR = -2
}	t_err;

ssize_t	ft_strchrlen(const char *str, int chr)
{
	ssize_t	len;

	if (str == NULL)
		return (NULL_PTR);
	len = 0;
	while (str[len] != '\0')
	{
		if ((unsigned char)str[len] == (unsigned char)chr)
			return (len);
		len += 1;
	}
	if ((unsigned char)chr == '\0')
		return (len);
	return (NOT_FOUND);
}

void	*ft_bzero(void *mem, size_t num_bytes_to_set_zero)
{
	unsigned char	*mem_caster;
	size_t			i;

	i = 0;
	mem_caster = (unsigned char *)mem;
	while (i < num_bytes_to_set_zero)
	{
		mem_caster[i] = '\0';
		i += 1;
	}
	return (mem);
}

char	*ft_calloc_for_str(size_t num_bytes_to_allocate)
{
	char	*tmp;

	if (num_bytes_to_allocate == 0)
		num_bytes_to_allocate = 1;
	tmp = (char *)malloc(sizeof(char) * num_bytes_to_allocate);
	if (tmp == NULL)
	{
		errno = ENOMEM;
		return (NULL);
	}
	ft_bzero(tmp, num_bytes_to_allocate);
	return (tmp);
}

char	*double_free_null_str(char **str1, char **str2)
{
	if (str1 && *str1)
	{
		free(*str1);
		*str1 = NULL;
	}
	if (str2 && *str2)
	{
		free(*str2);
		*str2 = NULL;
	}
	return (NULL);
}

void	iter_copy_src_to_dest(char *dest, const char *src, size_t end)
{
	size_t	i;

	i = 0;
	while (end > i + 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i += 1;
	}
}

//22L
char	*ft_strjoin(char *old_str, const char *arr)
{
	char	*nu_str;
	size_t	old_str_len;
	size_t	arr_len;

	if (!old_str)
		old_str = ft_calloc_for_str(1);
	if (!old_str || !arr)
		return (NULL);
	old_str_len = ft_strchrlen(old_str, '\0');
	arr_len = ft_strchrlen(arr, '\0');
	if (old_str_len > SIZE_MAX - arr_len - 1)
		return (double_free_null_str(&old_str, NULL));
	nu_str = ft_calloc_for_str(old_str_len + arr_len + 1);
	if (!nu_str)
		return (double_free_null_str(&old_str, NULL));
	iter_copy_src_to_dest(nu_str, old_str, old_str_len);
	iter_copy_src_to_dest(&nu_str[old_str_len], arr, arr_len);
	double_free_null_str(&old_str, NULL);
	return (nu_str);
}

//16L
// char	*ft_strdup(const char *str)
// {
// 	char	*dup;
// 	size_t	i;

// 	if (str == NULL)
// 		return (NULL);
// 	dup = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
// 	if (!dup)
// 		return (NULL);
// 	i = 0;
// 	while (str[i] != '\0')
// 	{
// 		dup[i] = str[i];
// 		i++;
// 	}
// 	dup[i] = '\0';
// 	return (dup);
// }

// char	*ft_strjoin(char *old_str, const char *arr)
// {
// 	char	*nu_str;
// 	size_t	i;
// 	size_t	j;

// 	if (!old_str)
// 		old_str = ft_calloc_for_str(1);
// 	if (!old_str || !arr)
// 		return (NULL);
// 	nu_str = ft_calloc_for_str(ft_strchrlen(old_str, '\0') + ft_strchrlen(arr, '\0') + 1);
// 	if (nu_str)
// 	{
// 		i = 0;
// 		j = 0;
// 		while (str1[j] != '\0')
// 			nu_str[i++] = str1[j++];
// 		j = 0;
// 		while (str2[j] != '\0')
// 			nu_str[i++] = str2[j++];
// 		nu_str[i] = '\0';
// 	}
// 	free_null_str(&old_str);
// 	return (nu_str);
// }
// 	// i = ft_strlen(str1);
// 	// j = ft_strlen(str2);
// 		// nu_str = strcpy(nu_str, str1);
