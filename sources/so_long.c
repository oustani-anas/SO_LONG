/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoustani <aoustani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 19:58:22 by aoustani          #+#    #+#             */
/*   Updated: 2022/06/02 20:58:44 by aoustani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	init(t_var *var)
{
	var->map.mtx = malloc((var->map.size.y + 1) * sizeof(char *));
	var->game.count_steps = 0;
	return (0);
}

int	check_args(int argc, char **argv)
{
	if (argc < 2)
		message("Provide map name and extension as argument\n\
Ex: ./so_long maps/map.ber");
	if (argc > 2)
		message("Too many arguments. Provide only map name and extension\n\
Ex: ./so_long maps/map.ber");
	if (ft_strstr(argv[1], ".ber") == NULL)
		message("Invalid map extension. Use: .ber");
	return (0);
}

int	main(int argc, char **argv)
{
	t_var	var;

	check_args(argc, argv);
	get_x_y(&var, argv);
	init(&var);
	get_map(&var, argv);
	var.mlx = mlx_init();
	var.win = mlx_new_window(var.mlx, var.map.size.x * PLAYER_H,
			var.map.size.y * PLAYER_H, "So long");
	get_init_position(&var);
	xpm_to_img(&var);
	print_map(&var);
	mlx_hook(var.win, X_EVENT_KEY_PRESS, 1L << 0, key_press, &var);
	mlx_hook(var.win, X_EVENT_KEY_EXIT, 1L << 0, mlx_close, &var);
	mlx_loop(var.mlx);
}
