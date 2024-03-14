/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elichan < elichan@student.42.fr >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:45:15 by elichan           #+#    #+#             */
/*   Updated: 2024/03/12 12:59:26 by elichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	name_map(char *ext_map)
{
	int	i;

	i = 0;
	while (ext_map[i])
		i++;
	i -= 1;
	if (ext_map[i] == 'r' && ext_map[i - 1] == 'e'
		&& ext_map[i - 2] == 'b' && ext_map[i - 3] == '.')
		return (1);
	else
		return (0);
}

int	map_rectangle(char *name_map, t_data *data)
{
	int	i;
	int	j;
	int	res;

	i = 0;
	j = 0;
	while (data->map[i][j])
		j++;
		res = j;
	while (data->map[i])
	{
		j = 0;
		if (data->map[i][j] == '\0')
			break ;
		while (data->map[i][j])
			j++;
		if (res != j)
			return (0);
		i++;
	}
	return (1);
}

int	first_to_last(char *name_map, t_data *data)
{
	int	i;
	int	j;
	int	res;

	i = 0;
	while (data->map[i])
		i++;
	res = i - 1;
	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[0][j] != '1')
				return (0);
			if (data->map[res][j] != '1')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	board_valid(char *name_map, t_data *data)
{
	int	i;
	int	j;
	int	res;

	i = 0;
	j = 0;
	while (data->map[i][j])
		j++;
	res = j -1;
	j = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][0] != '1' || data->map[i][res] != '1')
				return (0);
		j++;
		}
		i++;
	}
	return (1);
}
