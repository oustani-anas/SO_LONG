/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoustani <aoustani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 19:34:47 by aoustani          #+#    #+#             */
/*   Updated: 2022/06/02 21:11:55 by aoustani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	get_init_position(t_var *var)
{
	int		row;
	int		col;

	row = 0;
	while (row < var->map.size.y - 1)
	{
		col = 0;
		while (col <= var->map.size.x)
		{
			if (var->map.mtx[row][col] == 'P')
			{
				var->img.pos.x = col;
				var->img.pos.y = row;
			}
			col++;
		}
		row++;
	}
	return (0);
}

int	count_collec(t_var *var)
{
	int		row;
	int		col;

	row = 0;
	var->game.count_collec = 0;
	while (row < var->map.size.y - 1)
	{
		col = 0;
		while (col <= var->map.size.x)
		{
			if (var->map.mtx[row][col] == 'C')
				var->game.count_collec++;
			col++;
		}
		row++;
	}
	return (var->game.count_collec);
}

int	check_collect(t_var *var)
{
	if (count_collec(var) == 0)
	{
		free_exit(var, "\e[34m\e[1mCONGRATS\n!!!! You WON !!!!\e[0m\n");
	}
	else
		ft_printf("\e[35m\e[1m!!! Collect all Diamands !!!\e[0m\n");
	return (0);
}

int	print_steps(t_var *var)
{
	char	*str;

	str = ft_itoa(var->game.count_steps);
	mlx_string_put(var->mlx, var->win, (var->img.pos.x * SPRITE_W) + 50,
		(var->img.pos.y * SPRITE_H) + 10, 0x00FFFF, str);
	free(str);
	return (0);
}
