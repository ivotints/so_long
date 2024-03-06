/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07move_msg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:33:16 by ivotints          #+#    #+#             */
/*   Updated: 2024/02/26 15:33:25 by ivotints         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	destroy_images(t_data data)
{
	mlx_destroy_image(data.mlx, data.img.wall);
	mlx_destroy_image(data.mlx, data.img.ground);
	mlx_destroy_image(data.mlx, data.img.player);
	mlx_destroy_image(data.mlx, data.img.exit_l);
	mlx_destroy_image(data.mlx, data.img.coin1);
	mlx_destroy_display(data.mlx);
}

int	handle_button_r(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	data->win = NULL;
	return (0);
}

void	move_msg(t_data *data)
{
	ft_putstr_fd("\E[H\E[2J", 1);
	ft_putstr_fd(WHITE, 1);
	ft_putstr_fd("Moves counter : ", 1);
	ft_putnbr_fd(data->steps_count, 1);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd(RESET, 1);
}
