/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elichan < elichan@student.42.fr >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:58:36 by elichan           #+#    #+#             */
/*   Updated: 2024/03/21 11:54:43 by elichan          ###   ########.fr       */
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
# define KEY_LEFT 65361
# define KEY_DOWN 65364
# define KEY_RIGHT 65363
# define KEY_UP 65362
# define KEY_ESCAPE 65307

typedef struct data_s
{
	void		*mlx;
	void		*win;
	void		*player;
	void		*player2;
	void		*wall;
	void		*floor;
	void		*food;
	void		*exit;
	char		**map;
	int			nb_exit;
	int			nb_player;
	int			nb_collect;
	int			x;
	int			y;
	int			x_pos;
	int			y_pos;
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
char	*stock_line(char *name_map, t_data *data);
char	*ft_strdup(char *src);
char	*ft_itoa(int n);
void	ft_putchar(char c);
void	ft_add_space(void);
void	flood_fill(t_data *data);
void	check_flood(char **copymap, t_data *data);
void	to_long(t_data *data, int i, int j);
void	find_player( t_data *data, int *x, int *y);
void	stock_map(char *name_map, t_data *data);
void	read_map(char *name_map, t_data *data);
void	left_control(t_data *data);
void	right_control(t_data *data);
void	down_control(t_data *data);
void	up_control(t_data *data);
void	init_sprite(t_data *data);
void	update_nb(t_data *data, char c);
void	moves_counter(t_data *data);
int		empty_map(t_data *data);
int		fill(char **copy, int x, int y, t_data *data);
int		end(t_data *data);
int		ft_printf(const char *sign, ...);
int		ft_putnbr(int n);
int		ft_key_up_down(int key, t_data *data);
int		first_to_last(char *name_map, t_data *data);
int		board_valid(char *name_map, t_data *data);
int		map_rectangle(char *name_map, t_data *data);
int		char_valid(char *name_map, t_data *data);
int		name_map(char *ext_map);
int		display(t_data *data);
int		nb_valid(char *name_map, t_data *data);
int		check_map(char *name_map, t_data *data);
int		check_map2(char *name_map, t_data *data);
int		key_control(int key, t_data *data);
int		count_line(char *name_map, t_data *data);
int		count_collect(char *name_map, t_data *data);
int		display_player(t_data *data, int i, int j);
int		display_map(t_data *data, int i, int j);
int		checkstr(char *str);
int		ext_map(char *name_map);

#endif
