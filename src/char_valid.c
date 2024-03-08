/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_valid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elichan < elichan@student.42.fr >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:08:22 by elichan           #+#    #+#             */
/*   Updated: 2024/03/08 12:07:09 by elichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	update_nb(t_data *data, char c)
{
	if (c == 'E')
		data->nb_exit++;
	else if (c == 'C')
		data->nb_collect++;
	else if (c == 'P')
		data->nb_player++;
}

int	nb_valid(char *name_map, t_data *data)
{
	int		fd;
	char	c;

	data->nb_collect = 0;
	data->nb_exit = 0;
	data->nb_player = 0;
	fd = open(name_map, O_RONLY);
	if (fd < 0)
		return (0);
	while (read(fd, &c, 1))
		update_nb(data, c);
	clode(fd);
	if (data->nb_exit == 1 && data->nb_collect >= 1 && data->nb_player == 1)
		return (1);
	else
		return (0);
}

int	char_valid(char *name_map, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] != '1' && data->map[i][j] != '0'
				&& data->map[i][j] != 'P' && data->map[i][j] != 'E'
				&& data->map[i][j] != 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
