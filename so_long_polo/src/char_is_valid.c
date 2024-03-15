/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_is_valid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elichan < elichan@student.42.fr >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:49:48 by pabeaude          #+#    #+#             */
/*   Updated: 2024/03/12 12:33:44 by elichan          ###   ########.fr       */
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
		data->nb_perso++;
}

int	nb_is_valid(char *nom_map, t_data *data)
{
	int		fd;
	char	c;

	data->nb_collect = 0;
	data->nb_exit = 0;
	data->nb_perso = 0;
	fd = open(nom_map, O_RDONLY);
	if (fd < 0)
		return (0);
	while (read(fd, &c, 1))
		update_nb(data, c);
	close(fd);
	if (data->nb_exit == 1 && data->nb_perso == 1
		&& data->nb_collect >= 1)
		return (1);
	else
		return (0);
}

int	char_is_valid(char *nom_map, t_data *data)
{
	int	i;
	int	j;

	(void) *nom_map;
	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] != '1' && data->map[i][j] != '0'
				&& data->map[i][j] != 'P' && data->map[i][j] != 'C'
					&& data->map[i][j] != 'E')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	to_long(t_data *data, int i, int j)
{
	mlx_put_image_to_window(data->mlx, data->win, data->food,
		data->x_wall * j, data->y_wall * i);
	data->nb_collect++;
}
