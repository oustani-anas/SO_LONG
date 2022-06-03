/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoustani <aoustani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 19:34:14 by aoustani          #+#    #+#             */
/*   Updated: 2022/06/02 21:12:56 by aoustani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	get_x_y(t_var *var, char **argv)
{
	int		fd;
	char	*line;

	var->map.size.x = 0;
	var->map.size.y = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		message("Map not found");
	while (1)
	{
		line = get_next_line(fd);
		if (!var->map.size.x && !var->map.size.y && line == 0)
			message("Map not found");
		if (line == 0)
			break ;
		var->map.size.x = ft_strlen(line);
		var->map.size.y++;
		free(line);
	}
	var->map.size.y++;
	free(line);
	close(fd);
	return (0);
}

int	get_map(t_var *var, char **argv)
{
	int		row;
	int		fd;

	row = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		message("Map not found");
	while (1)
	{	
		var->map.mtx[row] = get_next_line(fd);
		if (row != 0 && var->map.mtx[row] == NULL)
			break ;
		row++;
	}
	close(fd);
	check_map(*var);
	return (0);
}

void	xpm_to_img1(t_var *var)
{
	int	x;
	int	y;

	var->img.img_ground = mlx_xpm_file_to_image(var->mlx,
			"./imgs/ground_grey2.xpm", &x, &y);
	var->img.img_walls = mlx_xpm_file_to_image(var->mlx, "./imgs/wall2.xpm",
			&x, &y);
	var->img.img_collect = mlx_xpm_file_to_image(var->mlx, "./imgs/coll.xpm",
			&x, &y);
	var->img.img_exit = mlx_xpm_file_to_image(var->mlx, "./imgs/EXIT1.xpm",
			&x, &y);
	var->img.img_player = mlx_xpm_file_to_image(var->mlx, "./imgs/among_us.xpm",
			&x, &y);
}

int	load_map(t_var *var, int row, int col)
{
	if (var->map.mtx[row][col] == '1')
		mlx_put_image_to_window(var->mlx, var->win, var->img.img_walls,
			SPRITE_W * col, SPRITE_H * row);
	if (var->map.mtx[row][col] == '0')
		mlx_put_image_to_window(var->mlx, var->win, var->img.img_ground,
			SPRITE_W * col, SPRITE_H * row);
	if (var->map.mtx[row][col] == 'E')
		mlx_put_image_to_window(var->mlx, var->win, var->img.img_exit,
			SPRITE_W * col, SPRITE_H * row);
	if (var->map.mtx[row][col] == 'C')
		mlx_put_image_to_window(var->mlx, var->win, var->img.img_collect,
			SPRITE_W * col, SPRITE_H * row);
	if (var->map.mtx[row][col] == 'P')
		mlx_put_image_to_window(var->mlx, var->win, var->img.img_player,
			SPRITE_W * col, SPRITE_H * row);
	if (var->map.mtx[row][col] == 'Y')
		enemy_animation(var, row, col);
	return (0);
}

int	print_map(t_var *var)
{
	int		row;
	int		col;

	row = 0;
	mlx_clear_window(var->mlx, var->win);
	while (row < var->map.size.y - 1)
	{
		col = 0;
		while (col < var->map.size.x)
		{
			load_map(var, row, col);
			col++;
		}
		row++;
	}
	print_steps(var);
	return (0);
}
