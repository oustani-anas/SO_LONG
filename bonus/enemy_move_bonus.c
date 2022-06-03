/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoustani <aoustani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 19:35:06 by aoustani          #+#    #+#             */
/*   Updated: 2022/06/02 21:11:01 by aoustani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	check_enemy(t_var *var)
{
	int		row;
	int		col;

	row = 0;
	while (row < var->map.size.y - 1)
	{
		col = 0;
		while (col < var->map.mtx[row][col])
		{
			if (var->map.mtx[row][col] == 'Y')
					var->enemy_has++;
			col++;
		}
		row++;
	}
	return (0);
}

int	get_enemy_position(t_var *var)
{
	int		row;
	int		col;

	row = 0;
	while (row < var->map.size.y - 1)
	{
		col = 0;
		while (col <= var->map.size.x)
		{
			if (var->map.mtx[row][col] == 'Y')
			{
				var->enemy.pos.x = col;
				var->enemy.pos.y = row;
			}
			col++;
		}
		row++;
	}
	return (0);
}

int	step_into_enemy(int key, t_var *var)
{
	if ((key == A_KEY)
		&& (var->map.mtx[var->img.pos.y][var->img.pos.x - 1] == 'Y'))
	{
		free_exit(var, "\e[31m\e[1mGAME OVER\n!!!! You LOST !!!!\e[0m\n");
	}
	if ((key == D_KEY)
		&& (var->map.mtx[var->img.pos.y][var->img.pos.x + 1] == 'Y'))
	{
		free_exit(var, "\e[31m\e[1mGAME OVER\n!!!! You LOST !!!!\e[0m\n");
	}
	if ((key == S_KEY)
		&& (var->map.mtx[var->img.pos.y + 1][var->img.pos.x] == 'Y'))
	{
		free_exit(var, "\e[31m\e[1mGAME OVER\n!!!! You LOST !!!!\e[0m\n");
	}
	if ((key == W_KEY)
		&& (var->map.mtx[var->img.pos.y - 1][var->img.pos.x] == 'Y'))
	{
		free_exit(var, "\e[31m\e[1mGAME OVER\n!!!! You LOST !!!!\e[0m\n");
	}
	return (0);
}
