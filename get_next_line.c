/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbulut <fbulut@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:55:21 by fbulut            #+#    #+#             */
/*   Updated: 2022/02/02 20:57:51 by fbulut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <fcntl.h>
#include <stdio.h>

char	*get_data_line(int fd, char *destek)
{
	char	*buffer;
	int		okunan;

	okunan = 1;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (!ft_strchr(destek, '\n') && okunan > 0)
	{
		okunan = read(fd, buffer, BUFFER_SIZE);
		if (!okunan)
			break ;
		buffer[okunan] = '\0';
		destek = ft_strjoin(destek, buffer);
	}
	free (buffer);
	return (destek);
}

char	*kalan_line(char *destek)
{
	char	*ptr;

	ptr = ft_strchr(ptr, '\n');
	if (!ptr)
	{
		free (ptr);
		return (NULL);
	}
	ptr++;
	if (!*ptr)
	{
		free(destek);
		return (NULL);
	}
	ptr = ft_strdup(ptr);
	free(destek);
	return (ptr);
}

char	*tut_line(char *destek)
{
	char	*ptr;
	int		len;

	if (!destek)
		return (NULL);
	if (!*destek)
		return (NULL);
	ptr = ft_strchr(destek, '\n');
	if (!ptr)
		return (ft_strdup(destek));
	ptr++;
	if (!(*ptr))
		return (ft_strdup(destek));
	len = ft_strlen(destek) - ft_strlen(ptr);
	return (ft_substr(destek, 0, len));
}

char	*get_next_line(int fd)
{
	static char	*dizi;
	char		*line;

	line = NULL;
	dizi = get_data_line(fd, dizi);
	if (!dizi)
		return (NULL);
	line = tut_line(line);
	dizi = kalan_line(dizi);
	return (line);
}

int   main()
{
  int   fd;
  int	fd2;
  char *c;

  fd = open("test.txt", O_RDONLY);
  c = get_next_line(fd);
    free(c);
  // For checking leaks
  //system("leaks a.out");
}