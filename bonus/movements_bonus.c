/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoustani <aoustani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 19:35:26 by aoustani          #+#    #+#             */
/*   Updated: 2022/06/02 21:11:18 by aoustani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	move_right(t_var *var)
{
	var->map.mtx[var->img.pos.y][var->img.pos.x] = '0';
	var->img.pos.x += 1;
	var->map.mtx[var->img.pos.y][var->img.pos.x] = 'P';
	var->game.count_steps++;
	return (0);
}

int	move_left(t_var *var)
{
	var->map.mtx[var->img.pos.y][var->img.pos.x] = '0';
	var->img.pos.x -= 1;
	var->map.mtx[var->img.pos.y][var->img.pos.x] = 'P';
	var->game.count_steps++;
	return (0);
}

int	move_up(t_var *var)
{
	var->map.mtx[var->img.pos.y][var->img.pos.x] = '0';
	var->img.pos.y -= 1;
	var->map.mtx[var->img.pos.y][var->img.pos.x] = 'P';
	var->game.count_steps++;
	return (0);
}

int	move_down(t_var *var)
{
	var->map.mtx[var->img.pos.y][var->img.pos.x] = '0';
	var->img.pos.y += 1;
	var->map.mtx[var->img.pos.y][var->img.pos.x] = 'P';
	var->game.count_steps++;
	return (0);
}

int	movements(int key, t_var *var)
{
	if ((key == D_KEY)
		&& (var->map.mtx[var->img.pos.y][var->img.pos.x + 1] == 'E'))
		check_collect(var);
	else if ((key == D_KEY)
		&& (var->map.mtx[var->img.pos.y][var->img.pos.x + 1] != '1'))
		move_right(var);
	if ((key == A_KEY)
		&& (var->map.mtx[var->img.pos.y][var->img.pos.x - 1] == 'E'))
		check_collect(var);
	else if ((key == A_KEY)
		&& (var->map.mtx[var->img.pos.y][var->img.pos.x - 1] != '1'))
		move_left(var);
	if ((key == W_KEY)
		&& (var->map.mtx[var->img.pos.y - 1][var->img.pos.x] == 'E'))
		check_collect(var);
	else if ((key == W_KEY)
		&& (var->map.mtx[var->img.pos.y - 1][var->img.pos.x] != '1'))
		move_up(var);
	if ((key == S_KEY)
		&& (var->map.mtx[var->img.pos.y + 1][var->img.pos.x] == 'E'))
		check_collect(var);
	else if ((key == S_KEY)
		&& (var->map.mtx[var->img.pos.y + 1][var->img.pos.x] != '1'))
		move_down(var);
	return (0);
}
