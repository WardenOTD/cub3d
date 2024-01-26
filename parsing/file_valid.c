/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_valid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:34:20 by jteoh             #+#    #+#             */
/*   Updated: 2024/01/26 11:37:40 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	validity(t_data *data, int i, int j)
{
	while (data->file[i])
	{
		j = 0;
		while (data->file[i][j])
		{
			if (!ft_strncmp(&(data->file[i][j]), "F ", 2))
			{
				if (!get_f(data, i, j))
					return (0);
				data->parse_check += 1;
				break ;
			}
			else if (!ft_strncmp(&(data->file[i][j]), "C ", 2))
			{
				if (!get_c(data, i, j))
					return (0);
				data->parse_check += 1;
				break ;
			}
			j++;
		}
		i++;
	}
	return (validity2(data, 0, 0));
}

int	validity2(t_data *data, int i, int j)
{
	while (data->file[i])
	{
		j = 0;
		while (data->file[i][j])
		{
			if (!ft_strncmp(&(data->file[i][j]), "NO ", 3))
			{
				if (!get_no(data, i, j + 1))
					return (0);
				data->parse_check += 1;
				break ;
			}
			else if (!ft_strncmp(&(data->file[i][j]), "EA ", 3))
			{
				if (!get_ea(data, i, j + 1))
					return (0);
				data->parse_check += 1;
				break ;
			}
			j++;
		}
		i++;
	}
	return (validity3(data, 0, 0));
}

int	validity3(t_data *data, int i, int j)
{
	while (data->file[i])
	{
		j = 0;
		while (data->file[i][j])
		{
			if (!ft_strncmp(&(data->file[i][j]), "SO ", 3))
			{
				if (!get_so(data, i, j + 1))
					return (0);
				data->parse_check += 1;
				break ;
			}
			else if (!ft_strncmp(&(data->file[i][j]), "WE ", 3))
			{
				if (!get_we(data, i, j + 1))
					return (0);
				data->parse_check += 1;
				break ;
			}
			j++;
		}
		i++;
	}
	return (validity4(data, 0, 0));
}

int	validity4(t_data *data, int i, int j)
{
	while (data->file[i])
	{
		j = 0;
		while (data->file[i][j])
		{
			if (ft_isalpha(data->file[i][j]))
				break ;
			if (ft_isdigit(data->file[i][j]))
			{
				if (data->parse_check != 6)
					return (0);
				if (!get_map(data, i))
					return (0);
				data->parse_check++;
				return (validity5_check(data));
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	validity5_check(t_data *data)
{
	if (data->parse_check != 7)
		return (0);
	return (1);
}
