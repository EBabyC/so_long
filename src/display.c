/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elichan < elichan@student.42.fr >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:14:53 by elichan           #+#    #+#             */
/*   Updated: 2024/03/25 15:15:04 by elichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

//end libere mem et termine prog

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
	//mlx_destroy_image(data->mlx, data->player2);
	mlx_destroy_image(data->mlx, data->player);
	mlx_destroy_image(data->mlx, data->wall);
	mlx_destroy_image(data->mlx, data->floor);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	close(data->fd);
	exit(0);
}
//initialisation des elem graph en stockant ptr d images et leurs dimensions
//ds struct data

void	init_sprite(t_data *data)
{
	//data->ori = 0;
	data->exit = mlx_xpm_file_to_image(data->mlx, "sprites/sortie.xpm",
			&data->x_wall, &data->y_wall);
	data->food = mlx_xpm_file_to_image(data->mlx, "sprites/kunai.xpm",
			&data->x_wall, &data->y_wall);
	data->player = mlx_xpm_file_to_image(data->mlx, "sprites/player.xpm",
			&data->x, &data->y);
	//data->player2 = mlx_xpm_file_to_image(data->mlx, "sprites/playerback.xpm",
	//		&data->x_wall, &data->y_wall);
	data->wall = mlx_xpm_file_to_image(data->mlx, "sprites/flower.xpm",
			&data->x_wall, &data->y_wall);
	data->floor = mlx_xpm_file_to_image(data->mlx, "sprites/tiles.xpm",
			&data->x_wall, &data->y_wall);
}
//affichage joueur en focntion pos

int	display_player(t_data *data, int i, int j)
{
	if (data->map[i][j] == 'P') //&& data->ori == 0)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->player,
			data-> x * j, data-> y * i);
		data->x_pos = j;
		data->y_pos = i;
	}
	else if (data->map[i][j] == 'P') // && data->ori == 1)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->player2,
			data->x * j, data->y * j);
		data->x_pos = j;
		data->y_pos = i;
	}
	return (0);
}
//affichage elem map

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
//affichage complet map, i = -1 pour que 1ere iteration de while commence a 0
//pareil pr j. Apres la fct convertit le comptoir data->count en str

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
				display_player(data, i, j);
			else if (data->map[i][j] == '1' || data->map[i][j] == 'E'
				|| data->map[i][j] == '0')
				display_map(data, i, j);
			else if (data->map[i][j] == 'C')
				to_long(data, i, j);
		}
	}
	str = ft_itoa(data->count);
	mlx_string_put(data->mlx, data->win, 50, 15, 0xFFFFFF, "MOVE:");
	mlx_string_put(data->mlx, data->win, 50, 35, 0xFFFFFF, str);
	free(str);
	return (0);
}
