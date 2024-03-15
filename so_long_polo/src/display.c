/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeaude <pabeaude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:51:54 by pabeaude          #+#    #+#             */
/*   Updated: 2023/09/06 15:56:29 by pabeaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	end(t_data *data)
{
	int	i;

	i = 0;
	mlx_destroy_window(data->mlx, data->win);
	while (data->map[i])
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
	mlx_destroy_image(data->mlx, data->exit);
	mlx_destroy_image(data->mlx, data->food);
	mlx_destroy_image(data->mlx, data->perso2);
	mlx_destroy_image(data->mlx, data->perso);
	mlx_destroy_image(data->mlx, data->wall);
	mlx_destroy_image(data->mlx, data->floor);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	close(data->fd);
	exit(0);
}

void	init_sprite(t_data *data)
{
	data->ori = 0;
	data->exit = mlx_xpm_file_to_image(data->mlx, "sprites/sorti.xpm",
			&data->x_wall, &data->y_wall);
	data->food = mlx_xpm_file_to_image(data->mlx, "sprites/food.xpm",
			&data->x_wall, &data->y_wall);
	data->perso = mlx_xpm_file_to_image(data->mlx, "sprites/dino1.xpm",
			&data->x, &data->y);
	data->perso2 = mlx_xpm_file_to_image(data->mlx, "sprites/dino2.xpm",
			&data->x, &data->y);
	data->wall = mlx_xpm_file_to_image(data->mlx, "sprites/arbre2.xpm",
			&data->x_wall, &data->y_wall);
	data->floor = mlx_xpm_file_to_image(data->mlx, "sprites/sol.xpm",
			&data->x_wall, &data->y_wall);
}

int	display_perso(t_data *data, int i, int j)
{
	if (data->map[i][j] == 'P' && data->ori == 0)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->perso,
			data->x * j, data->y * i);
		data->x_pos = j;
		data->y_pos = i;
	}
	else if (data->map[i][j] == 'P' && data->ori == 1)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->perso2,
			data->x * j, data->y * i);
		data->x_pos = j;
		data->y_pos = i;
	}
	return (0);
}

int	display_map(t_data *data, int i, int j)
{
	if (data->map[i][j] == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->wall,
			data->x_wall * j, data->y_wall * i);
	else if (data->map[i][j] == '0')
		mlx_put_image_to_window(data->mlx, data->win, data->floor,
			data->x_wall * j, data->y_wall * i);
	else if (data->map[i][j] == 'E')
		mlx_put_image_to_window(data->mlx, data->win, data->exit,
			data->x_wall * j, data->y_wall * i);
	return (0);
}

int	display(t_data *data)
{
	int		i;
	int		j;
	char	*str;

	i = -1;
	data->nb_collect = 0;
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
		{
			if (data->map[i][j] == 'P')
				display_perso(data, i, j);
			else if (data->map[i][j] == '1' ||
					data->map[i][j] == '0' || data->map[i][j] == 'E')
				display_map(data, i, j);
			else if (data->map[i][j] == 'C')
				to_long(data, i, j);
		}
	}
	str = ft_itoa(data->count);
	mlx_string_put(data->mlx, data->win, 10, 32, 0x00FFFFFF, "NB = ");
	mlx_string_put(data->mlx, data->win, 40, 32, 0x00FFFFFF, str);
	free(str);
	return (0);
}
