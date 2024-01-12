/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:17:40 by jteoh             #+#    #+#             */
/*   Updated: 2024/01/12 17:31:21 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_tex_malloc(t_data *data, int i, int j, char spc)
{
	int		index;
	int		pos;
	char	*hold;

	index = 0;
	pos = j;
	while (data->file[i][j])
	{
		if (data->file[i][j] == ' ' || data->file[i][j] == '\n')
			break ;
		index++;
		j++;
	}
	if (!check_invalid_after(data, i, j))
		return (0);
	hold = get_tex_copy(data, i, pos, index);
	get_tex_transfer(data, hold, spc);
	return (1);
}

char	*get_tex_copy(t_data *data, int i, int j, int index)
{
	char	*hold;
	int		k;

	hold = (char *)malloc(sizeof(char) * (index + 1));
	hold[index] = 0;
	k = 0;
	while (k < index)
		hold[k++] = data->file[i][j++];
	return (hold);
}

void	get_tex_transfer(t_data *data, char *hold, char spc)
{
	if (spc == 'N')
		data->n_path = ft_strdup(hold);
	else if (spc == 'E')
		data->e_path = ft_strdup(hold);
	else if (spc == 'S')
		data->s_path = ft_strdup(hold);
	else if (spc == 'W')
		data->w_path = ft_strdup(hold);
	free(hold);
}

int	check_invalid_after(t_data *data, int i, int j)
{
	while (data->file[i][j])
	{
		if (data->file[i][j] != ' ' && data->file[i][j] != '\n')
			return (0);
		j++;
	}
	return (1);
}
