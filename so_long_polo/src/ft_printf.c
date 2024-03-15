/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeaude <pabeaude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:54:15 by pabeaude          #+#    #+#             */
/*   Updated: 2023/09/06 15:56:44 by pabeaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_putnbr(int n)
{
	ft_space();
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putchar(n % 10 + '0');
	}
	else if (n < 10)
		ft_putchar(n % 10 + '0');
	return (0);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_space(void)
{
	write (1, " ", 2);
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
