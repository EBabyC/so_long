/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elichan < elichan@student.42.fr >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 12:45:09 by elichan           #+#    #+#             */
/*   Updated: 2024/03/05 13:06:29 by elichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_map(char *name_map, t_data *data)
{
	if (!ext_map(name_map))
	{
		write(2, "ERROR, Wrong Extension\n", 23);
		end(data);
	}
	if (!nb_valid(name_map, data))
	{
		write(2, "ERROR, Wrong nb P/C/E\n", 22);
		end(data);
	}
	if (!char_valid(name_map, data))
	{
		write(2, "ERROR, Wrong char\n", 18);
		end(data);
	}
	check_map2(name_map, data);
	return (0);
}

int	check_map2(char *name_map, t_data *data)
{
	if (!map_rectangle(name_map, data))
	{
		write(2, "ERROR, Not Rectangle\n", 21);
		end(data);
	}
	if (!first_to_last(name_map, data))
	{
		write(2, "ERROR, Not Closed\n", 18);
		end(data);
	}
	if (!board_valid(name_map, data))
	{
		write(2, "ERROR, Not Closed\n", 18);
		end(data);
	}
	return (0);
}
