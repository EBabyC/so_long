/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeaude <pabeaude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:52:48 by pabeaude          #+#    #+#             */
/*   Updated: 2023/09/06 15:57:03 by pabeaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	fill(char **copy, int x, int y, t_data *data)
{
	if (x < 0 || y < 0 || x >= data->nb_char_line
		|| y >= data->nb_line || copy[y][x] == '1' || copy[y][x] == 'F')
		return (1);
	if (copy[y][x] == 'E')
	{
		data->token_exit = 1;
		return (1);
	}
	copy[y][x] = 'F';
	fill(copy, x + 1, y, data);
	fill(copy, x - 1, y, data);
	fill(copy, x, y + 1, data);
	fill(copy, x, y - 1, data);
	return (data->token_exit);
}

void	find_perso(t_data *data, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P')
			{
				*x = j;
				*y = i;
			}
			j++;
		}
		i++;
	}
}

char	*ft_strdup(char *src)
{
	char	*new;
	int		i;
	int		size;

	size = 0;
	while (src[size])
		size++;
	new = malloc(sizeof(char) * (size + 1));
	if (new == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		new[i] = src[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	**mapcopy(t_data *data)
{
	int		i;
	char	**new;

	i = 0;
	while (data->map[i])
		i++;
	new = malloc(sizeof(char *) * (i + 1));
	if (new == NULL)
		end(data);
	i = 0;
	while (data->map[i])
	{
		new[i] = ft_strdup(data->map[i]);
		i++;
	}
	new[i] = 0;
	return (new);
}

void	floodfill(t_data *data)
{
	char	**copymap;
	int		x;
	int		y;

	data->token_exit = 0;
	copymap = mapcopy(data);
	find_perso(data, &x, &y);
	if (!fill(copymap, x, y, data))
	{
		write(2, "ERROR exit", 10);
		end(data);
	}
	checkflood(copymap, data);
}
