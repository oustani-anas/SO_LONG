/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoustani <aoustani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 19:34:56 by aoustani          #+#    #+#             */
/*   Updated: 2022/06/02 20:31:28 by aoustani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	message(char *msg)
{
	ft_printf("\e[31m\e[1m××{Error}××\n%s \e[0m \n", msg);
	exit (EXIT_FAILURE);
	return (0);
}
