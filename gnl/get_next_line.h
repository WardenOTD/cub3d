/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 09:46:40 by jteoh             #+#    #+#             */
/*   Updated: 2024/01/11 17:58:10 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char		*get_next_line(int fd);

char		*readfd(int fd, char *string);

char		*reallocbuff(char *buff, int rv);

char		*readstring(char *string);

char		*trim(char *string);

int			ft_strlen2(const char *s);

char		*ft_strjoin(char *s1, char *s2);

int			check(char *string, int c);

char		*ft_strdup(const char *s1);

#endif
