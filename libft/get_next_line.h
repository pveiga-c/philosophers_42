/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 18:13:22 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/08/21 18:28:35 by pveiga-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 7
# endif

char		*get_next_line(int fd);
size_t		ft_strlen_gnl(const char *str);
char		*ft_strjoin_gnl(char *s1, char *s2);
char		*ft_strchr_gnl(const char *s, int c);
void		*ft_memmove_gnl(void *dest, const void *src, size_t n);
char		*ft_read_line(int fd, char *stash);
char		*ft_next_line(char *stash);

#endif