/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elichan < elichan@student.42.fr >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 12:13:33 by elichan           #+#    #+#             */
/*   Updated: 2024/03/25 15:14:31 by elichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

//deplacement vers le haut et compteur de mouv incremente

void	up_control(t_data *data)
{
	if (data->map[data->y_pos + 1][data->x_pos] != '1')
	{
		if (data->map[data->y_pos + 1][data->x_pos] != 'E'
			&& data->nb_collect != 0)
		{
			data->map[data->y_pos][data->x_pos] = '0';
			data->map[data->y_pos + 1][data->x_pos] = 'P';
		}
		else if (data->map[data->y_pos + 1][data->x_pos] != 'E'
			&& data->nb_collect == 0)
		{
			data->map[data->y_pos][data->x_pos] = '0';
			data->map[data->y_pos + 1][data->x_pos] = 'P';
		}
		else if (data->map[data->y_pos + 1][data->x_pos] == 'E'
			&& data->nb_collect == 0)
			end(data);
		data->count++;
	}
}
//deplacement vers le bas et compteur de mouv incremente

void	down_control(t_data *data)
{
	if (data->map[data->y_pos - 1][data->x_pos] != '1')
	{
		if (data->map[data->y_pos - 1][data->x_pos] != 'E'
			&& data->nb_collect != 0)
		{
			data->map[data->y_pos][data->x_pos] = '0';
			data->map[data->y_pos - 1][data->x_pos] = 'P';
		}
		else if (data->map[data->y_pos - 1][data->x_pos] != 'E'
			&& data->nb_collect == 0)
		{
			data->map[data->y_pos][data->x_pos] = '0';
			data->map[data->y_pos - 1][data->x_pos] = 'P';
		}
		else if (data->map[data->y_pos - 1][data->x_pos] == 'E'
			&& data->nb_collect == 0)
			end(data);
		data->count++;
	}
}

void	right_control(t_data *data)
{
	//data->ori = 0;
	if (data->map[data->y_pos][data->x_pos + 1] != '1')
	{
		if (data->map[data->y_pos][data->x_pos + 1] != 'E'
			&& data->nb_collect != 0)
		{
			data->map[data->y_pos][data->x_pos] = '0';
			data->map[data->y_pos][data->x_pos + 1] = 'P';
		}
		else if (data->map[data->y_pos][data->x_pos + 1] != 'E'
			&& data->nb_collect == 0)
		{
			data->map[data->y_pos][data->x_pos] = '0';
			data->map[data->y_pos][data->x_pos + 1] = 'P';
		}
		else if (data->map[data->y_pos][data->x_pos + 1] == 'E'
			&& data->nb_collect == 0)
			end(data);
		data->count++;
	}
}

void	left_control(t_data *data)
{
	//data->ori = 1;
	if (data->map[data->y_pos][data->x_pos - 1] != '1')
	{
		if (data->map[data->y_pos][data->x_pos - 1] != 'E'
			&& data->nb_collect != 0)
		{
			data->map[data->y_pos][data->x_pos] = '0';
			data->map[data->y_pos][data->x_pos - 1] = 'P';
		}
		else if (data->map[data->y_pos][data->x_pos - 1] != 'E'
			&& data->nb_collect == 0)
		{
			data->map[data->y_pos][data->x_pos] = '0';
			data->map[data->y_pos][data->x_pos - 1] = 'P';
		}
		else if (data->map[data->y_pos][data->x_pos - 1] == 'E'
			&& data->nb_collect == 0)
			end(data);
		data->count++;
	}
}

int	key_control(int key, t_data *data)
{
	if (key == UP || key == KEY_UP)
		ft_key_up_down(key, data);
	else if (key == DOWN || key == KEY_DOWN)
		ft_key_up_down(key, data);
	else if (key == RIGHT || key == KEY_RIGHT)
	{
		right_control(data);
		ft_putnbr(data->count);
	}
	else if (key == LEFT || key == KEY_LEFT)
	{
		left_control(data);
		ft_putnbr(data->count);
	}
	else if (key == ESC)
		end(data);
	return (0);
}
