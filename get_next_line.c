/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuske <yuske@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 20:07:31 by yuske             #+#    #+#             */
/*   Updated: 2023/01/18 01:37:11 by yuske            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_and_save(int fd, char *save, t_id *id);
static char	*line_arranger(char *save, t_id *id);
static char	*save_the_rest(char *save, t_id *id);
static void	id_initializer(t_id *id);

//13L
char	*get_next_line(int fd)
{
	static char	*save;
	char		*line_to_print;
	t_id		id;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	id_initializer(&id);
	save = read_and_save(fd, save, &id);
	if (!save)
		return (NULL);
	line_to_print = line_arranger(save, &id);
	save = save_the_rest(save, &id);
	return (line_to_print);
}

static void	id_initializer(t_id *id)
{
	id->terminal = '\0';
	id->rd_len = 0;
	id->len = 0;
	id->i = 0;
}

//22L
static char	*read_and_save(int fd, char *save, t_id *id)
{
	char	*buf;

	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1UL);
	if (!buf)
		return (NULL);
	id->rd_len = 1;
	while (1)
	{
		id->rd_len = read(fd, buf, BUFFER_SIZE);
		if (id->rd_len <= 0)
			break ;
		buf[id->rd_len] = '\0';
		save = ft_strjoin(save, buf);
		if (save == NULL || ft_strchr(save, '\n') != NULL)
			break ;
	}
	free(buf);
	if (id->rd_len == -1)
		return (NULL);
	else if (ft_strchr(save, '\n') != NULL)
		id->terminal = '\n';
	return (save);
}

//21L
static char	*line_arranger(char *save, t_id *id)
{
	char	*line;

	id->i = 0;
	if (!save[id->i])
		return (NULL);
	id->len = 0;
	while (save[id->len] != id->terminal)
		id->len++;
	if (id->terminal == '\n')
		line = (char *)malloc(sizeof(char) * (id->len + 2));
	else
		line = (char *)malloc(sizeof(char) * (id->len + 1));
	if (!line)
		free(save);
	else
	{
		while (id->i < id->len + 1)
		{
			line[id->i] = save[id->i];
			id->i += 1;
		}
		line[id->i] = '\0';
	}
	return (line);
}

//17L
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
