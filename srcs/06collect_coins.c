/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06collect_coins.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:31:40 by ivotints          #+#    #+#             */
/*   Updated: 2024/02/26 18:21:25 by ivotints         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	collect_coins(t_data *data, char di, char **map)
{
	if (((di == 'd' || di == 'S') && map[data->p_i][data->p_j + 1] == 'C')
		|| ((di == 'a' || di == 'Q') && map[data->p_i][data->p_j - 1] == 'C')
		|| ((di == 's' || di == 'T') && map[data->p_i + 1][data->p_j] == 'C')
		|| ((di == 'w' || di == 'R') && map[data->p_i - 1][data->p_j] == 'C'))
		data->map.collected++;
}

int	checknt(t_data *data, char di, char til, char **map)
{
	if (((di == 'd' || di == 'S') && map[data->p_i][data->p_j + 1] == til)
		|| ((di == 'a' || di == 'Q') && map[data->p_i][data->p_j - 1] == til)
		|| ((di == 's' || di == 'T') && map[data->p_i + 1][data->p_j] == til)
		|| ((di == 'w' || di == 'R') && map[data->p_i - 1][data->p_j] == til))
		return (1);
	return (0);
}

void	move_player(t_data *data, char di)
{
	if (checknt(data, di, '1', data->map.map)
		|| (data->map.can_exit == 0 && checknt(data, di, 'E', data->map.map)))
		return ;
	data->steps_count++;
	collect_coins(data, di, data->map.map);
	if (data->map.collected == data->map.count_c)
		data->map.can_exit = 1;
	data->map.map[data->p_i][data->p_j] = '0';
	if (di == 'd' || di == 'S')
		data->p_j++;
	else if (di == 'a' || di == 'Q')
		data->p_j--;
	else if (di == 's' || di == 'T')
		data->p_i++;
	else if (di == 'w' || di == 'R')
		data->p_i--;
	move_msg(data);
	if (data->map.can_exit == 1 && data->map.map[data->p_i][data->p_j] == 'E')
	{
		mlx_destroy_window(data->mlx, data->win);
		data->win = NULL;
	}
	data->map.map[data->p_i][data->p_j] = 'P';
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx, data->win);
		data->win = NULL;
	}
	else if (ft_strchr("wasdRQTS", keysym))
		move_player(data, keysym);
	return (0);
}

void	loop_images(t_data data)
{
	mlx_loop_hook(data.mlx, &render, &data);
	mlx_hook(data.win, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_hook(data.win, ClientMessage, LeaveWindowMask, &handle_button_r, &data);
	mlx_loop(data.mlx);
}
