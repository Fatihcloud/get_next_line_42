/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbulut <fbulut@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 16:17:17 by fbulut            #+#    #+#             */
/*   Updated: 2022/01/30 19:40:31 by fbulut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*readbuffer(int fd)
{
	char	*buffer;
	char	*line;
	int		okunan;

	buffer = malloc(BUFFER_SIZE + 1);
	okunan = 1;
	while (!ft_strchr(buffer, '\n') && okunan > 0)
	{
		okunan = read(fd, buffer, BUFFER_SIZE);
		if (okunan <= 0)
			break ;
		buffer[okunan] = 0;
		line = ft_strjoin(line, buffer);
	}
	free(buffer);
	return (line);
}

char	*get_line(char *str)
{
	int	a;

	a = 0;
	while (str[a])
	{
		if (str[a] == '\n')
			break ;
		a++;
	}
	return (ft_substr(str, 0, a));
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*newline;

	buffer = readbuffer(fd);
	
}
