/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoustani <aoustani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 19:35:16 by aoustani          #+#    #+#             */
/*   Updated: 2022/06/02 19:41:05 by aoustani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	mlx_close(t_var *var)
{
	free_exit(var, "\e[33m\e[1mGame closed! (X)\e[0m\n");
	return (0);
}

int	key_press(int key, t_var *var)
{
	int	init_steps;

	init_steps = var->game.count_steps;
	if (key == ESC)
	{
		free_exit(var, "\e[33m\e[1mGame closed! (ESC)\e[0m\n");
	}
	else
	{
		if (var->enemy_has > 0)
			step_into_enemy(key, var);
		movements(key, var);
	}
	return (0);
}
