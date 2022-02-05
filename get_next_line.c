/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbulut <fbulut@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:55:21 by fbulut            #+#    #+#             */
/*   Updated: 2022/02/05 20:12:03 by fbulut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

char	*kalan_line(char *str)
{
	char	*y;

	if (!str)
		return (NULL);
	if (!*str)
	{
		free(str);
		return (NULL);
	}
	y = ft_strchr(str, '\n');
	if (!y)
	{
		free(str);
		return (NULL);
	}
	y++;
	if (!*y)
	{
		free(str);
		return (NULL);
	}
	y = ft_strdup(y);
	free(str);
	return (y);
}

char	*get_line(char *str)
{
	char	*y;
	char	*line;
	size_t	size;

	if (!str)
		return (NULL);
	if (!*str)
		return (NULL);
	y = ft_strchr(str, '\n');
	if (!y)
		return (ft_strdup(str));
	y++;
	if (!*y)
		return (ft_strdup(str));
	size = ft_strlen(str) - ft_strlen(y);
	line = ft_substr(str, 0, size);
	return (line);
}

char	*readdata(char *str, int fd)
{
	char	*bf;
	char	*temp;
	int		d;

	if (!str)
	str = ft_strdup("");
	d = 1;
	bf = malloc(BUFFER_SIZE + 1);
	while (d && !ft_strchr(str, '\n'))
	{
		d = read(fd, bf, BUFFER_SIZE);
		if (d < 0)
		{
			free (bf);
			free (str);
			return (NULL);
		}
		bf[d] = 0;
		temp = ft_strjoin(str, bf);
		free(str);
		str = temp;
	}
	free(bf);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = readdata(str, fd);
	line = get_line(str);
	str = kalan_line(str);
	return (line);
}

// int   main()
// {
//   int   fd;
//   char *c;

//   fd = open("test.txt", O_RDWR);
//   c = get_next_line(fd);
//   while(c)
//   {
//     printf("%s",c);
// 	free(c);
//     c = get_next_line(fd);
//   }
// //   For checking leaks
//   system("leaks a.out");
// }