/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoustani <aoustani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 19:34:34 by aoustani          #+#    #+#             */
/*   Updated: 2022/06/02 21:10:49 by aoustani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	check_walls(t_var var)
{
	int		row;
	int		col;

	row = 0;
	while (row < var.map.size.y - 1)
	{
		col = 0;
		if (row == 0 || row == (var.map.size.y - 1))
		{
			while (var.map.mtx[row][col])
			{
				if (var.map.mtx[row][col] != '1')
					message("Invalid map: top or down wall not configured");
				col++;
			}
		}
		if (var.map.mtx[row][0] != '1'
			|| var.map.mtx[row][var.map.size.x - 1] != '1')
			message("Invalid map: lateral wall not configured");
		row++;
	}
	return (0);
}

int	check_sprites(t_var var)
{
	int		has[3];
	int		row;
	int		col;

	row = 0;
	has[0] = 0;
	while (row < var.map.size.y - 1)
	{
		col = 0;
		while (col <= var.map.size.x)
		{
			if (var.map.mtx[row][col] == 'P')
				has[0] += 1;
			if (var.map.mtx[row][col] == 'E')
				has[1] = 1;
			if (var.map.mtx[row][col] == 'C')
				has[2] = 1;
			col++;
		}
		row++;
	}
	if (has[0] != 1 || has[1] != 1 || has[2] != 1)
		message("Invalid map: misssing PEC");
	return (0);
}

int	check_ret(t_var var)
{
	int		row;

	row = 0;
	while (row < var.map.size.y - 1)
	{
		if (var.map.size.x != (int)ft_strlen(var.map.mtx[row]))
			message("Invalid map: not a retangle");
		row++;
	}
	return (0);
}

int	check_char(t_var var)
{
	int		row;
	int		col;	

	row = 0;
	while (row < var.map.size.y - 1)
	{
		col = 0;
		while (var.map.mtx[row][col])
		{
			if (var.map.mtx[row][col] != '0' && var.map.mtx[row][col] != '1'
				&& var.map.mtx[row][col] != 'P' && var.map.mtx[row][col] != 'E'
				&& var.map.mtx[row][col] != 'C' && var.map.mtx[row][col] != 'Y')
				message("Invalid map: unknown char");
			col++;
		}
		row++;
	}
	return (0);
}

int	check_map(t_var var)
{
	check_walls(var);
	check_sprites(var);
	check_ret(var);
	check_char(var);
	return (0);
}
