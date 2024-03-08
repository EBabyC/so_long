/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elichan < elichan@student.42.fr >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 12:02:10 by elichan           #+#    #+#             */
/*   Updated: 2024/03/08 14:33:26 by elichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_putnbr(int n)
{
	ft_add_space();
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putchar(n % 10 + '0');
	}
	else if (n < 9)
		ft_putchar(n % 10 + '0');
	return (0);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_add_space(void)
{
	write(1, " ", 1);
}

int	ft_key_up_down(int key, t_data *data)
{
	if (key == UP)
	{
		up_control(data);
		ft_putnbr(data->count);
	}
	else if (key == DOWN)
	{
		down_control(data);
		ft_putnbr(data->count);
	}
	return (0);
}
