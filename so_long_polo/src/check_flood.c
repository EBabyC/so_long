/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flood.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeaude <pabeaude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:50:45 by pabeaude          #+#    #+#             */
/*   Updated: 2023/09/05 11:51:00 by pabeaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	checkflood(char **copymap, t_data *data)
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
