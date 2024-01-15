/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:51:42 by jteoh             #+#    #+#             */
/*   Updated: 2024/01/15 18:05:42 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	map_clean(t_data *data)
{
	int	i;
	int	j;
	int	longest;

	i = 0;
	longest = 0;
	while (data->map[i])
	{
		j = ft_strlen(data->map[i]);
		if (j > longest)
			longest = j;
		i++;
	}
	map_recopy(data, longest);
}

void	map_recopy(t_data *data, int longest)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		tmp = (char *)malloc(sizeof(char) * longest + 1);
		tmp[longest] = 0;
		while (data->map[i][j])
		{
			tmp[j] = data->map[i][j];
			j++;
		}
		while (j < longest)
			tmp[j++] = ' ';
		free(data->map[i]);
		data->map[i] = ft_strdup(tmp);
		free(tmp);
		i++;
	}
}
