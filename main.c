/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuske <yuske@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:58:09 by yuske             #+#    #+#             */
/*   Updated: 2023/01/18 01:56:23 by yuske            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <errno.h>

// #define BUF_SIZE 512

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("check.txt", O_RDONLY);
	// fd = open("sample08.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("ERROR\n");
		return (errno);
	}
	while (1)
	{
		line = get_next_line(fd);
		printf("%s [\\n]", line);
		if (!line)
			break ;
		free(line);
	}
	close(fd);
	// system("leaks a.out");
	system("leaks -q a.out");
	return (0);
}

// #include "get_next_line.h"
// #include <fcntl.h>
// #include <stdio.h>

// int	main(void)
// {
// 	int	fd;
// 	int i = 0;
// 	char *str;

// 	fd = open("a.txt", O_RDONLY);
// 	if (fd == -1)
// 		return (-1);
// 	str = malloc(sizeof(char));
// 	*str = 'q';
// 	while(str)
// 	{
// 		str = get_next_line(0);//42, etc
// 		printf("line[%d] : %s", i, str);
// 		i++;		
// 	}
// 	system("leaks -q a.out");
// 	return (0);
// }

// int	main(void)
// {
// 	int		fd;
// 	char	buffer[100];
// 	char	msg[50] = "hello ifocus institute";

// 	fd = open("check.txt", O_RDONLY);
// 	printf("\nfd: %d\n", fd);
// 	if (fd != -1)
// 	{
// 		printf("\ncheck.txt opened with read write access\n");
// 		// write(fd, msg, sizeof(msg));
// 		// lseek(fd, 0, SEEK_SET);
// 		read(fd, buffer, sizeof(msg));
// 		printf("\n %s was written to my file\n", buffer);
// 		close(fd);
// 	}
// 	printf("\nerrno: %d\n", errno);
// 	return (0);
// }

// int	main(void)
// {
// 	char		*str1;
// 	char		str2[100];
// 	char		*str3;
// 	ssize_t		len;

// 	str1 = malloc(sizeof(char *));
// 	str3 = "heyheyheyhay";
// 	if (str1 != NULL)
// 	{
// 		// bzero(str3, strlen(str2));
// 		len = read(0, str3, sizeof(str3));
// 		bzero(str2, strlen(str2));
// 		printf("str2 0: %s\n", str2);
// 		printf("str2 p: %p\n", str2);
// 		printf("str2 c: %s\n", strcpy(str2, "hi, there!"));
// 		str1 = strcpy(str1, "good, eh?");
// 		printf("str1: %s\n", str1);
// 		free(str1);
// 	}
// 	printf("\n");
// 	printf("len: %zd str3: %s\n", len, str3);
// 	printf("str1: %s\n", str1);
// 	printf("str1 p: %p\n", str1);
// 	str1 = NULL;
// 	printf("str1: %s\n", str1);
// 	printf("str1 p: %p\n", str1);
// 	return (0);
// }
	// if (str1 != NULL && str2 != NULL) //str2 != NULL -> always true
	// char const	*head;

	// head = (char *)0;
		// head = str1;
		// while (*str1)
		// {
		// 	str1++;
		// }
		// str1--;
		// printf("str1 end: %s\n", str1);
		// printf("str1 len: %ld\n", str1 - head);
		// printf("str1 sch: %ld\n", strchr(str1, '?') - head);

// int	main(void)
// {
// 	char	*str1;
// 	char	str2[100];
// 	ssize_t	len;

// 	strcpy(str2, "heyheyhay");
// 	len = read(0, str2, strlen(str2));
// 	printf("len: %zd str2: %s\n", len, str2);
// 	if (len == -1)
// 		return (len);
// 	return (0);
// }
