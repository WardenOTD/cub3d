/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_extension.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 11:05:09 by jteoh             #+#    #+#             */
/*   Updated: 2024/01/26 11:14:47 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	file_extension(char	*file)
{
	if (back_strncmp(file, ".cub"))
		return (0);
	return (1);
}

int	back_strncmp(char *haystack, char *needle)
{
	int	i;
	int	j;

	i = ft_strlen(haystack);
	j = ft_strlen(needle);
	while (i >= 0)
	{
		while (haystack[i] == needle[j])
		{
			if (j == 0)
				return (0);
			j--;
			i--;
		}
		if (j != (int)ft_strlen(needle))
			break ;
		i--;
	}
	return (1);
}
