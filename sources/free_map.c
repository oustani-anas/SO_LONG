/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoustani <aoustani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 15:05:06 by aoustani          #+#    #+#             */
/*   Updated: 2022/06/02 21:03:31 by aoustani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	free_map(t_var *var)
{
	int	row;

	row = 0;
	mlx_destroy_window(var->mlx, var->win);
	mlx_destroy_image(var->mlx, var->img.img_ground);
	mlx_destroy_image(var->mlx, var->img.img_walls);
	mlx_destroy_image(var->mlx, var->img.img_collect);
	mlx_destroy_image(var->mlx, var->img.img_exit);
	mlx_destroy_image(var->mlx, var->img.img_player);
	free(var->mlx);
	while (row < var->map.size.y)
	{
		free(var->map.mtx[row]);
		row++;
	}
	free(var->map.mtx);
	return (0);
}

int	free_exit(t_var *var, char *msg)
{
	ft_printf("%s", msg);
	free_map(var);
	exit(EXIT_FAILURE);
}
