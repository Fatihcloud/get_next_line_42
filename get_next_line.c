/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbulut <fbulut@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 16:17:17 by fbulut            #+#    #+#             */
/*   Updated: 2022/01/31 11:52:19 by fbulut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*readbuffer(int fd, char *line)
{
	char	*buffer;
	char	*line2;
	int		okunan;

	buffer = malloc(BUFFER_SIZE + 1);
	okunan = 1;
	while (!ft_strchr(line, '\n') && okunan > 0)
	{
		okunan = read(fd, buffer, BUFFER_SIZE);
		if (okunan <= 0)
			break ;
		buffer[okunan] = 0;
		line2 = ft_strjoin(line, buffer);
		free(line);
		line = line2;
	}
	free(buffer);
	return (line);
}

char	*ft_move_str(char **str, size_t n)
{
	char	*old;
	size_t	len;

	old = *str;
	len = ft_strlen(*str) - n;
	if (len == 0)
		*str = NULL;
	else
		*str = ft_substr(old, n, len);
	free(old);
	return (*str);
}

char	*get_line(char **str)
{
	char	*line;
	size_t	line2;

	if (ft_strchr(*str, '\n') || ft_strchr(*str, '\0'))
	{
		line2 = ft_strchr(*str, '\n') - (*str);
		line = ft_substr(*str, 0, line2);
		ft_move_str(str, line2);
		return (line);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*newline;
	char		*line;

	buffer = readbuffer(fd, buffer);
	line = get_line(&buffer);
	if (!line)
	{
		newline = ft_strdup(buffer);
		free(buffer);
		buffer = NULL;
		return (newline);
	}
	return (line);
}
