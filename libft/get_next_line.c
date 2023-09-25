/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 18:12:47 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/08/21 18:27:58 by pveiga-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*check(char *stash, int nbits)
{
	if (nbits == 0 && *stash == '\0')
	{
		free(stash);
		return (NULL);
	}
	if (stash == NULL)
	{
		stash = malloc(1);
		if (stash == NULL)
			return (NULL);
		*stash = '\0';
	}
	return (stash);
}

char	*ft_read_line(int fd, char *stash)
{
	int		nbits;
	char	*buff;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	nbits = 1;
	while (!ft_strchr_gnl(stash, '\n') && nbits > 0)
	{
		nbits = read(fd, buff, BUFFER_SIZE);
		if (nbits == -1)
		{
			free(stash);
			free(buff);
			return (NULL);
		}
		buff[nbits] = '\0';
		stash = ft_strjoin_gnl(stash, buff);
	}
	stash = check(stash, nbits);
	free(buff);
	return (stash);
}

char	*ft_next_line(char *stash)
{
	char	*str;
	char	*str_f;
	int		nl_pos;

	if (!ft_strchr_gnl(stash, '\n'))
		str_f = stash + (ft_strlen_gnl(stash) - 1);
	else
		str_f = ft_strchr_gnl(stash, '\n');
	nl_pos = str_f - stash + 1;
	str = (char *)malloc(nl_pos + 1);
	if (str == NULL)
	{
		free(stash);
		free(str);
		return (0);
	}
	ft_memmove_gnl(str, stash, nl_pos);
	str[nl_pos] = '\0';
	ft_memmove_gnl(stash, nl_pos + stash, ft_strlen_gnl(stash) - nl_pos + 1);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash;

	if (fd < 0 && BUFFER_SIZE <= 0)
		return (NULL);
	stash = ft_read_line(fd, stash);
	if (!stash)
		return (NULL);
	line = ft_next_line(stash);
	return (line);
}

/*
# include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("testes/test1.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Failed to open file.\n");
		return (1);
	}
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
*/