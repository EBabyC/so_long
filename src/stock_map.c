/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elichan < elichan@student.42.fr >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:41:28 by elichan           #+#    #+#             */
/*   Updated: 2024/03/12 13:00:56 by elichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/s_log.h"

int	count_line(char *name_map, t_data *data)
{
	int			count;
	int			fd;
	int			ret;
	char		buff[2];

	count = 0;
	fd = open(name_map, O_RDONLY);
	if (fd == -1)
	{
		write(1, "ERROR", 5);
		exit (0);
	}
	ret = 1;
	while (ret)
	{
		ret = read(fd, buff, 1);
		buff[ret] = '\0';
		if (buff[0] == '\n' || buff[0] == '\0')
			count++;
	}
	close(fd);
	data->nb_line = count;
	return (count);
}

void	read_map(char *name_map, t_data, *data)
{
	int		fd;
	int		count_on_line;
	int		ret;
	char	buff[2];

	data->map = malloc(sizeof(char *) * (count_line(name_map, data) + 1));
	if (data->map == NULL)
		end(data);
	fd = open(name_map, O_RDONLY);
	ret = 1;
	count_line = 0;
	while (1)
	{
		ret = read(data->fd, buff, 1);
		buff[1] = '\0';
		if (ret == 0 || buff[0] == '\n')
			break ;
		str[i] = buff[0];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	stock_map(char *name_map, t_data *data)
{
	int	i;

	i = -1;
	data->fd = open(name_map, O_RDONLY);
	while (i < data->nb_line)
	{
		data->fd = open(name_map, O_RDONLY);
		if (data->map[i][0] == '\0' || data->map[i][0] == '\n')
		{
			free(data->map[i]);
			data->nb_line--;
			break ;
		}
		i++;
	}
	data->map[i] = 0;
}
