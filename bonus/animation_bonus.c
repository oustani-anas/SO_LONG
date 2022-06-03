/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoustani <aoustani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 19:33:50 by aoustani          #+#    #+#             */
/*   Updated: 2022/06/02 21:10:25 by aoustani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	xpm_to_img2(t_var *var)
{
	int	x;
	int	y;

	var->img.img_enemy1 = mlx_xpm_file_to_image(var->mlx, "./imgs/fire1.xpm",
			&x, &y);
	var->img.img_enemy2 = mlx_xpm_file_to_image(var->mlx, "./imgs/fire2.xpm",
			&x, &y);
	var->img.img_enemy3 = mlx_xpm_file_to_image(var->mlx, "./imgs/fire3.xpm",
			&x, &y);
}

int	enemy_animation(t_var *var, int row, int col)
{
	static int	i;
	static int	state;

	if (state == 0)
		mlx_put_image_to_window(var->mlx, var->win, var->img.img_enemy1,
			SPRITE_W * col, SPRITE_H * row);
	else if (state == 1)
		mlx_put_image_to_window(var->mlx, var->win, var->img.img_enemy2,
			SPRITE_W * col, SPRITE_H * row);
	else if (state == 2)
		mlx_put_image_to_window(var->mlx, var->win, var->img.img_enemy3,
			SPRITE_W * col, SPRITE_H * row);
	if (i == DURATION)
	{
		state = (state + 1) % 3;
		i = 0;
	}
	else
		i++;
	return (0);
}
