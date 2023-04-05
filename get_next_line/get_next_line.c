/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 15:17:01 by sel-jama          #+#    #+#             */
/*   Updated: 2023/03/28 01:33:47 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_free(char **buff, char **saver)
{
	free(*buff);
	free(*saver);
}

char	*ft_rest(char **save)
{
	int		i;
	int		v;
	char	*rest;

	i = 0;
	while (*(*save + i) && *(*save + i) != '\n')
		i++;
	rest = malloc(ft_strlen(*save) - i + 1);
	if (!rest)
	{
		free (*save);
		return (NULL);
	}
	if (*(*save + i) == '\n')
		i += 1;
	v = 0;
	while (*(*save + i))
	{
	rest[v] = *(*save + i);
		i++;
		v++;
	}
	rest[v] = '\0';
	free(*save);
	return (rest);
}

char	*ft_read(int fd, char **saver)
{
	char	*r_buff;
	int		nbytes;

	if (!(*saver))
		*saver = ft_calloc(1, sizeof(char));
	r_buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!r_buff)
	{
		free(*saver);
		return (NULL);
	}
	nbytes = 1;
	while (!ft_strchr(*saver, '\n') && nbytes != 0)
	{
		nbytes = read(fd, r_buff, BUFFER_SIZE);
		if (nbytes == -1 || (nbytes == 0 && *(*saver) == '\0'))
		{
			ft_free(&r_buff, saver);
			return (NULL);
		}
		*saver = ft_strnjoin(*saver, r_buff, nbytes);
	}
	free (r_buff);
	return (*saver);
}

char	*get_myline(char *saver)
{
	int		i;
	char	*line;

	i = 0;
	if (!saver[i])
		return (NULL);
	while (saver[i] && saver[i] != '\n')
		i++;
	if (saver[i] == '\n')
		i += 1;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (saver[i] && saver[i] != '\n')
	{
		line[i] = saver[i];
		i++;
	}
	if (saver[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	char		*fd_line;
	static char	*saver;

	if (fd < 0 && BUFFER_SIZE <= 0)
		return (NULL);
	saver = ft_read(fd, &saver);
	if (!saver)
		return (NULL);
	fd_line = get_myline(saver);
	saver = ft_rest(&saver);
	return (fd_line);
}
