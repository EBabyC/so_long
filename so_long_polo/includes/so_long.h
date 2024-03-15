/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeaude <pabeaude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:43:48 by pabeaude          #+#    #+#             */
/*   Updated: 2023/09/05 17:08:25 by pabeaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define UP 115
# define DOWN   119
# define LEFT   97
# define RIGHT  100
# define ESC    65307

# include "../mlx/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <fcntl.h>
# include <stdarg.h>

typedef struct data_s
{
	void		*mlx;
	void		*win;
	void		*perso;
	void		*perso2;
	void		*wall;
	void		*floor;
	void		*food;
	void		*exit;
	char		**map;
	int			ori;
	int			nb_exit; 
	int			nb_perso; 
	int			nb_collect; 
	int			x;
	int			y;
	int			x_pos;
	int			y_pos;
	int			xperso;
	int			yperso;
	int			fd;
	int			nb_line;
	int			nb_char_line;
	int			x_wall;
	int			y_wall;
	int			hauteur;
	int			largeur;
	int			count;
	int			token_exit;
}		t_data;

char	**mapcopy(t_data *data);
char	*stock_line(char *nom_map, t_data *data);
char	*ft_strdup(char *src);
char	*ft_itoa(int n);
void	ft_putchar(char c);
void	ft_space(void);
void	floodfill(t_data *data);
void	checkflood(char **copymap, t_data *data);
void	to_long(t_data *data, int i, int j);
void	find_perso( t_data *data, int *x, int *y);
void	stock_map(char *nom_map, t_data *data);
void	read_map(char *nom_map, t_data *data);
void	left_control(t_data *data);
void	right_control(t_data *data);
void	down_control(t_data *data);
void	up_control(t_data *data);
void	init_sprite(t_data *data);
void	update_nb(t_data *data, char c);
int		empty_map(t_data *data);
int		fill(char **copy, int x, int y, t_data *data);
int		end(t_data *data);
int		ft_printf(const char *sign, ...);
int		ft_putnbr(int n);
int		ft_key_up_down(int key, t_data *data);
int		first_to_last(char *nom_map, t_data *data);
int		board_is_valid(char *nom_map, t_data *data);
int		map_is_rectangle(char *nom_map, t_data *data);
int		char_is_valid(char *nom_map, t_data *data);
int		name_map(char *nom_map);
int		display(t_data *data);
int		nb_is_valid(char *nom_map, t_data *data);
int		check_map(char *nom_map, t_data *data);
int		check_map2(char *nom_map, t_data *data);
int		key_control(int key, t_data *data);
int		count_line(char *nom_map, t_data *data);
int		count_collect(char *nom_map, t_data *data);

#endif
