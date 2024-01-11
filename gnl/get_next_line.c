/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 09:46:18 by jteoh             #+#    #+#             */
/*   Updated: 2024/01/11 17:58:38 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*readfd(int fd, char *string)
{
	int		rv;
	char	*buff;

	rv = 1;
	while (rv)
	{
		buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buff)
			return (NULL);
		rv = read(fd, buff, BUFFER_SIZE);
		if (rv == -1)
		{
			free(buff);
			free(string);
			return (NULL);
		}
		buff = reallocbuff(buff, rv);
		string = ft_strjoin(string, buff);
		if (check(buff, '\n'))
			rv = 0;
		free(buff);
	}
	return (string);
}

char	*reallocbuff(char *buff, int rv)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = (char *)malloc(sizeof(char) * (rv + 1));
	if (!tmp)
		return (NULL);
	while (i < rv)
	{
		tmp[i] = buff[i];
		i++;
	}
	tmp[i] = 0;
	free(buff);
	return (tmp);
}

char	*readstring(char *string)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (string[i] != '\n' && string[i] != '\0')
		i++;
	if (string[i] == '\n')
		tmp = (char *)malloc(sizeof(char) * (i + 2));
	if (string[i] == '\0')
		tmp = (char *)malloc(sizeof(char) * (i + 1));
	if (!tmp)
		return (NULL);
	i = 0;
	while (string[i] != '\n' && string[i] != '\0')
		tmp[j++] = string[i++];
	if (string[i] == '\n')
		tmp[j++] = string[i];
	tmp[j] = 0;
	return (tmp);
}

char	*trim(char *string)
{
	char	*tmp;
	int		i;
	int		j;

	j = ft_strlen2(string);
	i = 0;
	while (string[i] != '\n' && string[i] != '\0')
		i++;
	if (string[i] == '\0')
	{
		free(string);
		return (NULL);
	}
	tmp = (char *)malloc(sizeof(char) * (j - i + 1));
	if (!tmp)
		return (NULL);
	if (string[i] == '\n')
		++i;
	j = 0;
	while (string[i] != '\0')
		tmp[j++] = string[i++];
	tmp[j] = 0;
	free(string);
	return (tmp);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*string;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!string)
	{
		string = malloc(sizeof(char) * 1);
		if (!string)
			return (NULL);
		string[0] = 0;
	}
	string = readfd(fd, string);
	if (!string)
		return (NULL);
	line = readstring(string);
	if (!line)
		return (NULL);
	string = trim(string);
	return (line);
}
