/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_is_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeaude <pabeaude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:56:08 by pabeaude          #+#    #+#             */
/*   Updated: 2023/09/05 11:56:22 by pabeaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	name_map(char *nom_map)
{
	int	i;

	i = 0;
	while (nom_map[i])
		i++;
	i -= 1;
	if (nom_map[i] == 'r' && nom_map[i - 1] == 'e'
		&& nom_map[i - 2] == 'b' && nom_map[i - 3] == '.')
		return (1);
	else
		return (0);
}

int	map_is_rectangle(char *nom_map, t_data *data)
{
	int	i;
	int	j;
	int	res;

	(void)	*nom_map;
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

int	first_to_last(char *nom_map, t_data *data)
{
	int	i;
	int	j;
	int	res;

	(void)*nom_map;
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

int	board_is_valid(char *nom_map, t_data *data)
{
	int	i;
	int	j;
	int	res;

	(void)*nom_map;
	i = 0;
	j = 0;
	while (data->map[i][j])
		j++;
	res = j - 1;
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
