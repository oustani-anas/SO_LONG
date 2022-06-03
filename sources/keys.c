/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoustani <aoustani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 08:11:07 by aoustani          #+#    #+#             */
/*   Updated: 2022/06/02 16:56:01 by aoustani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
		free_exit(var, "\e[33m\e[1mGame closed! (ESC)\e[0m\n");
	movements(key, var);
	if (init_steps != var->game.count_steps)
		ft_printf("STEPS:%d\n", init_steps);
	print_map(var);
	return (0);
}
