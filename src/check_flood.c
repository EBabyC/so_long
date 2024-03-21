/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flood.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elichan < elichan@student.42.fr >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:52:06 by elichan           #+#    #+#             */
/*   Updated: 2024/03/18 12:14:43 by elichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// checks if multiple C or P in the string
// checks 

#include "../includes/so_long.h"

int	checkstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'C')
		{
			write (2, "ERROR C\n", 8);
			return (1);
		}
		if (str[i] == 'P')
		{
			write (2, "ERROR P\n", 8);
			return (1);
		}
		i++;
	}
	return (0);
}

//tableau chaine de char qui represente map
//chaque str represente ligne de map
//ret=nb erreur lors verif map

void	check_flood(char **copymap, t_data *data)
{
	int	i;
	int	ret;

	ret = 0;
	i = 0;
	while (copymap[i])
	{
		ret += checkstr(copymap[i]);
		free(copymap[i]);
		i++;
	}
	free (copymap);
	if (ret != 0)
		end (data);
}
