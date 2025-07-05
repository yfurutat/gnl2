/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfurutat <yfurutat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 20:07:31 by yuske             #+#    #+#             */
/*   Updated: 2023/01/20 20:28:11 by yfurutat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// # ifndef BUFFER_SIZE
// #  define BUFFER_SIZE (size_t)(1000)
// # endif

static void	id_initializer(t_id *id);
static char	*read_and_save(int fd, char *saved, t_id *id);
static char	*line_arranger(char *jointed, t_id *id);
static char	*save_the_rest(char *jointed, t_id *id);

//13L
/**
 * @brief Get the lines from fd by the BUFFER_SIZE,
 * 			and arrange them with '\n' if needed.
 * 
 * @param fd : file descriptor number from which to read lines.
 * @return char* : line created through line_arranger().
 * @note you might need to use open() and close() in main().
 */
char	*get_next_line(int fd)
{
	static char	*saved;
	char		*jointed;
	char		*line_to_print;
	ssize_t		next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	next_line = -1;
	jointed = read_and_joint(fd, saved, &next_line);
	if (!jointed)
		return (double_free_null_str(&saved, NULL));
	double_free_null_str(&saved, NULL);
	line_to_print = arrange_line(jointed, &next_line);
	if (!line_to_print)
		return (double_free_null_str(&saved, &jointed));
	saved = save_the_rest(jointed, &next_line);
	if (!saved)
		return (double_free_null_str(&line_to_print, &jointed));
	double_free_null_str(NULL, &jointed);
	return (line_to_print);
}

/**
 * @brief initialize all the elements in the struct.
 * 
 * @param id the struct contains index to make funcs more concise & go easier.
 */
static void	id_initializer(t_id *id)
{
	id->terminal = '\0';
	id->rd_len = 0;
	id->len = 0;
	id->i = 0;
}

//22L
/**
 * @brief read lines from the fd by the BUFFER_SIZE,
 * 			and put them into *buf, before copying them into save.
 * 			if any lines remain in *save, put them before the new lines
 * 			into save and combine them altogether.
 * 
 * @param fd file descriptor given through the input of g_n_l()
 * @param save if a line remains after the last process, 
 * 				it is carried over in this array.
 * @param id set of index, including rd_len
 * @return char* 
 */
static char	*read_and_save(int fd, char *saved, t_id *id)
{
	char	buf[BUFFER_SIZE];
	char	*tmp;
	ssize_t	read_len;

	while (1)
	{
		ft_bzero(buf, BUFFER_SIZE);
		read_len = read(fd, buf, BUFFER_SIZE);
		if (read_len == -1)
			return (NULL);
		if (read_len == 0)
			return (saved);
		saved = ft_strjoin(saved, buf);
		if (saved == NULL)
			return (NULL);
		*next_line = ft_strchrlen(saved, '\n');
		if (*next_line >= 0)
			return (saved);
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

// static char	*read_and_save(int fd, char *save, t_id *id)
// {
// 	char	*buf;

// 	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1UL);
// 	if (!buf)
// 		return (NULL);
// 	id->rd_len = 1;
// 	while (1)
// 	{
// 		id->rd_len = read(fd, buf, BUFFER_SIZE);
// 		if (id->rd_len <= 0)
// 			break ;
// 		buf[id->rd_len] = '\0';
// 		save = ft_strjoin(save, buf);
// 		if (save == NULL || ft_strchr(save, '\n') != NULL)
// 			break ;
// 	}
// 	free(buf);
// 	if (id->rd_len == -1)
// 		return (NULL);
// 	else if (ft_strchr(save, '\n') != NULL)
// 		id->terminal = '\n';
// 	return (save);
// }

//21L
/**
 * @brief create the actual line to output, out of *save.
 * 
 * @param save array saved in the previous func.
 * @param id set of index, including len and i.
 * @return char* line created through this func, 
 * 			which will be returned in the end of g_n_l(), too.
 */
static char	*line_arranger(char *save, t_id *id)
{
	char	*line;

	id->i = 0;
	if (save[id->i] == '\0' || save == NULL)
		return (NULL);
	id->len = 0;
	while (save[id->len] != id->terminal)
		id->len++;
	if (id->terminal == '\n')
		line = (char *)malloc(sizeof(char) * (id->len + 2));
	else
		line = (char *)malloc(sizeof(char) * (id->len + 1));
	if (line == NULL)
		free(save);
	else
	{
		while (id->i < id->len + 1)
		{
			line[id->i] = save[id->i];
			id->i += 1;
		}
		if (id->terminal == '\n')
			line[id->i] = '\0';
	}
	return (line);
}

//17L
/**
 * @brief if the line saved in *save contains any '\n',
 * 			this func keep the rest after creating the line
 * 			in the previous func.
 * @param save array saved and carried over.
 * @param id set of index including len and i.
 * @return char* the rest of the lines saved 
 * 			after creating the line to output.
 */
static char	*save_the_rest(char *save, t_id *id)
{
	char	*for_next;

	for_next = NULL;
	if (save && id->terminal == '\n')
	{
		for_next = (char *)malloc(ft_strlen(save) - id->len + 1);
		if (for_next)
		{
			id->len++;
			id->i = 0;
			while (save[id->len] != '\0')
				for_next[id->i++] = save[id->len++];
			for_next[id->i] = '\0';
		}
	}
	free(save);
	return (for_next);
}
