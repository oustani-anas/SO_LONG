/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoustani <aoustani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 22:06:22 by aoustani          #+#    #+#             */
/*   Updated: 2022/06/02 21:08:56 by aoustani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <mlx.h>
# include <stdbool.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_EXIT		17
/////////////
# define A_KEY					0
# define S_KEY					1
# define D_KEY					2
# define W_KEY					13
# define ESC 					53
/////////////
# define SPRITE_H				50
# define SPRITE_W				50

# define DURATION 60

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

typedef struct s_img
{
	void		*img_enemy1;
	void		*img_enemy2;
	void		*img_enemy3;
	void		*img_enemy4;
	void		*img_enemy5;
	void		*img_enemy6;
	void		*img_walls;
	void		*img_ground;
	void		*img_collect;
	void		*img_player;
	void		*img_exit;
	t_vector	size;
	t_vector	pos;
}	t_img;

typedef struct s_map
{
	char		**mtx;
	t_vector	size;
}	t_map;

typedef struct s_game
{
	int			count_collec;
	int			count_steps;
	int			count_enemy;
}	t_game;

typedef struct s_var
{
	void		*mlx;
	void		*win;
	t_game		game;
	t_map		map;
	t_img		img;
	t_img		enemy;
	int			enemy_has;
	t_vector	*db;
}	t_var;

int		init(t_var *var);
int		message(char *msg);
int		check_map(t_var var);
int		free_map(t_var *var);
int		mlx_close(t_var *var);
int		print_map(t_var *var);
int		check_enemy(t_var *var);
int		print_steps(t_var *var);
void	xpm_to_img2(t_var *var);
void	xpm_to_img1(t_var *var);
int		count_collec(t_var *var);
int		enemy_patrol(t_var *var);
int		check_collect(t_var *var);
int		get_init_position(t_var *var);
int		get_enemy_position(t_var *var);
int		movements(int key, t_var *var);
int		key_press(int key, t_var *vars);
int		get_x_y(t_var *var, char **argv);
int		get_map(t_var *var, char **argv);
int		check_args(int argc, char **argv);
int		free_exit(t_var *var, char *msg);
int		step_into_enemy(int key, t_var *var);
int		enemy_animation(t_var *var, int row, int col);
int		check_walls(t_var var);
int		check_sprites(t_var var);
int		check_ret(t_var var);

#endif
