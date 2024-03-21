/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elichan < elichan@student.42.fr >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:41:28 by elichan           #+#    #+#             */
/*   Updated: 2024/03/19 11:53:01 by elichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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

void	read_map(char *name_map, t_data *data)
{
	int		fd;
	int		count_on_line;
	int		ret;
	char	buff[2];

	data->map = malloc(sizeof(char *) * (count_line(name_map, data) + 1));
	if (data->map == NULL)
	{
		end(data);
	}
	fd = open(name_map, O_RDONLY);
	ret = 1;
	count_on_line = 0;
	while (1)
	{
		ret = read(fd, buff, 1);
		buff[ret] = '\0';
		if (buff[0] == '\n' || buff[0] == '\0')
			break ;
		count_on_line++;
	}
	if (count_on_line == 0)
		empty_map(data);
	close(fd);
	data->nb_char_line = count_on_line;
}

char	*stock_line(char *name_map, t_data *data)
{
	char	*str;
	char	buff[2];
	int		i;
	int		ret;

	(void) *name_map;
	i = 0;
	str = malloc(sizeof(char) * 1024);
	if (str == NULL)
		end(data);
	ret = 1;
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
	while (++i < data->nb_line)
	{
		data->map[i] = stock_line(name_map, data);
		if (data->map[i][0] == '\0' || data->map[i][0] == '\n')
		{
			free(data->map[i]);
			data->nb_line--;
			break ;
		}
	}
	data->map[i] = 0;
	if (i != data->nb_line)
	{
		i = -1;
		while (data->map[++i])
			free(data->map[i]);
		free(data->map);
		write (1, "ERROR\n", 6);
		close(data->fd);
		exit(0);
	}
}

int	empty_map(t_data *data)
{
	free(data->map);
	write (1, "ERROR\n", 6);
	close(data->fd);
	exit(0);
}
