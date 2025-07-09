/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efmacm23 <efmacm23@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 20:07:37 by yuske             #+#    #+#             */
/*   Updated: 2025/07/09 03:30:35 by efmacm23         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	while (i < end && src[i] != '\0')
	{
		dest[i] = src[i];
		i += 1;
	}
	dest[i] = '\0';
}

// char	*double_free_null_str(char **str1, char **str2, int num_for_error, int scope)

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