/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_valid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elichan < elichan@student.42.fr >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:08:22 by elichan           #+#    #+#             */
/*   Updated: 2024/03/18 14:32:57 by elichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

//validation de la map
//mise a j d elem en fct char c
void	update_nb(t_data *data, char c)
{
	if (c == 'E')
		data->nb_exit++;
	else if (c == 'C')
		data->nb_collect++;
	else if (c == 'P')
		data->nb_player++;
}
//validation nb elem

int	nb_valid(char *name_map, t_data *data)
{
	int		fd;
	char	c;

	data->nb_collect = 0;
	data->nb_exit = 0;
	data->nb_player = 0;
	fd = open(name_map, O_RDONLY);
	if (fd < 0)
		return (0);
	while (read(fd, &c, 1))
		update_nb(data, c);
	close(fd);
	if (data->nb_exit == 1 && data->nb_collect >= 1 && data->nb_player == 1)
		return (1);
	else
		return (0);
}
//valitation des char
//i parcourt les lignes j les colonnes

int	char_valid(char *name_map, t_data *data)
{
	int	i;
	int	j;

	(void) *name_map;
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

//connection mlx, win= la ou est le C, food = image de C
void	to_long(t_data *data, int i, int j)
{
	mlx_put_image_to_window(data->mlx, data->win, data->food,
		data->x_wall * j, data->y_wall * i);
		data->nb_collect++;
}
