/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeaude <pabeaude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:51:20 by pabeaude          #+#    #+#             */
/*   Updated: 2023/09/05 11:51:32 by pabeaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_map(char *nom_map, t_data *data)
{
	if (!name_map(nom_map))
	{
		write(2, "ERROR, mauvaise extention de map\n", 33);
		end(data);
	}
	if (!nb_is_valid(nom_map, data))
	{
		write(2, "ERROR, nombre de C,E ou P NON VALIDE\n", 38);
		end(data);
	}
	if (!char_is_valid(nom_map, data))
	{
		write(2, "ERROR, charactere non valide\n", 29);
		end(data);
	}
	check_map2(nom_map, data);
	return (0);
}

int	check_map2(char *nom_map, t_data *data)
{
	if (!map_is_rectangle(nom_map, data))
	{
		write(2, "ERROR, la map n'est pas rectangle\n", 34);
		end(data);
	}
	if (!first_to_last(nom_map, data))
	{
		write(2, "ERROR, la map n'est pas ferme\n", 30);
		end(data);
	}
	if (!board_is_valid(nom_map, data))
	{
		write(2, "ERROR, la map n'est pas ferme\n", 30);
		end(data);
	}
	return (0);
}
