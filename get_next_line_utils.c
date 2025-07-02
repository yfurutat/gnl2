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
	NOT_LOOKED = -2,
	NULL_PTR = -3
}	t_err;

ssize_t	strnchrlen(const char *str, ssize_t n, int chr)
{
	ssize_t	len;

	if (str == NULL)
		return NULL_PTR;
	if (n < 1)
		return NOT_LOOKED;
	len = 0;
	while (len < n && str[len] != '\0')
	{
		if ((unsigned char)str[len] == (unsigned char)chr)
			return (len);
		len += 1;
	}
	if ((unsigned char)chr == '\0' && str[len] == '\0')
		return (len);
	return NOT_FOUND;
}

//16L
char	*ft_strdup(const char *str)
{
	char	*dup;
	size_t	i;

	if (str == NULL)
		return (NULL);
	dup = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

//22L
char	*ft_strjoin(char *str1, char *str2)
{
	char	*nu_str;
	size_t	i;
	size_t	j;

	if (!str1)
		str1 = ft_strdup("");
	if (!str1 || !str2)
		return (NULL);
	nu_str = (char *)malloc(ft_strlen(str1) + ft_strlen(str2) + 1);
	if (nu_str)
	{
		i = 0;
		j = 0;
		while (str1[j] != '\0')
			nu_str[i++] = str1[j++];
		j = 0;
		while (str2[j] != '\0')
			nu_str[i++] = str2[j++];
		nu_str[i] = '\0';
	}
	free(str1);
	return (nu_str);
}
	// i = ft_strlen(str1);
	// j = ft_strlen(str2);
		// nu_str = strcpy(nu_str, str1);
