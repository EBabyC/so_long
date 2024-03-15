/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeaude <pabeaude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:55:30 by pabeaude          #+#    #+#             */
/*   Updated: 2023/09/05 17:08:04 by pabeaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static unsigned int	countdown(int i)
{
	unsigned int	count;

	if (i <= 0)
		count = 1;
	else
		count = 0;
	while (i != 0)
	{
		count++;
		i /= 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char			c;
	char			*str;
	unsigned int	count;

	count = countdown(n);
	str = malloc((count + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[count] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n < 0)
		str[0] = '-';
	while (n != 0)
	{
		c = n % 10;
		if (n < 0)
			c = -c;
		str[--count] = (c + '0');
		n /= 10;
	}
	return (str);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 2)
	{
		data.largeur = 0;
		data.hauteur = 0;
		data.count = 0;
		read_map(av[1], &data);
		stock_map(av[1], &data);
		close(data.fd);
		data.mlx = mlx_init();
		if (data.mlx == 0)
			exit(0);
		init_sprite(&data);
		data.win = mlx_new_window(data.mlx, data.nb_char_line * 64,
				data.nb_line * 64, "DinoLand");
		check_map(av[1], &data);
		floodfill(&data);
		mlx_loop_hook(data.mlx, &display, &data);
		mlx_key_hook(data.win, &key_control, &data);
		mlx_hook(data.win, 17, 1L << 1, &end, &data);
		mlx_loop(data.mlx);
	}
	else
		write (2, "Merci de ne fournir qu'une map\n", 31);
}
