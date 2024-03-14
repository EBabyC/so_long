/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elichan < elichan@student.42.fr >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 12:13:33 by elichan           #+#    #+#             */
/*   Updated: 2024/03/12 12:55:58 by elichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
	data->ori = 0;
	if (data->map[data->x_pos + 1][data->y_pos] != '1')
	{
		if (data->map[data->x_pos + 1][data->y_pos] != 'E'
			&& data->nb_collect != 0)
		{
			data->map[data->x_pos][data->y_pos] = '0';
			data->map[data->x_pos + 1][data->y_pos] = 'P';
		}
		else if (data->map[data->x_pos + 1][data->y_pos] != 'E'
			&& data->nb_collect == 0)
		{
			data->map[data->x_pos][data->y_pos] = '0';
			data->map[data->x_pos + 1][data->y_pos] = 'P';
		}
		else if (data->map[data->x_pos + 1][data->y_pos] == 'E'
			&& data->nb_collect == 0)
			end(data);
		data->count++;
	}
}

void	left_control(t_data *data)
{
	data->ori = 1;
	if (data->map[data->x_pos - 1][data->y_pos] != '1')
	{
		if (data->map[data->x_pos - 1][data->y_pos] != 'E'
			&& data->nb_collect != 0)
		{
			data->map[data->x_pos][data->y_pos] = '0';
			data->map[data->x_pos - 1][data->y_pos] = 'P';
		}
		else if (data->map[data->x_pos - 1][data->y_pos] != 'E'
			&& data->nb_collect == 0)
		{
			data->map[data->x_pos][data->y_pos] = '0';
			data->map[data->x_pos - 1][data->y_pos] = 'P';
		}
		else if (data->map[data->x_pos - 1][data->y_pos] == 'E'
			&& data->nb_collect == 0)
			end(data);
		data->count++;
	}
}

int	key_control(int key, t_data *data)
{
	if (key == UP)
		ft_key_up_down(key, data);
	else if (key == DOWN)
		ft_key_up_down(key, data);
	else if (key == RIGHT)
	{
		right_control(data);
		ft_putnbr(data->count);
	}
	else if (key == LEFT)
	{
		left_control(data);
		ft_putnbr(data->count);
	}
	else if (key == ESC)
		end(data);
	return (0);
}
