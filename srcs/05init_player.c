/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05init_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:30:58 by ivotints          #+#    #+#             */
/*   Updated: 2024/02/26 15:31:09 by ivotints         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	analyze_chars(t_data *data, int width, int i, int j)
{
	if (data->map.map[i][j] == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->img.wall, width,
			i * IMG_SIZE);
	else if (data->map.map[i][j] == '0')
		mlx_put_image_to_window(data->mlx, data->win, data->img.ground, width,
			i * IMG_SIZE);
	else if (data->map.map[i][j] == 'P')
		mlx_put_image_to_window(data->mlx, data->win, data->img.player, width,
			i * IMG_SIZE);
	else if (data->map.map[i][j] == 'E')
		mlx_put_image_to_window(data->mlx, data->win, data->img.exit_l, width,
			i * IMG_SIZE);
	else if (data->map.map[i][j] == 'C')
		mlx_put_image_to_window(data->mlx, data->win, data->img.coin1, width,
			i * IMG_SIZE);
}

int	render(t_data *data)
{
	int		i;
	size_t	j;
	int		width;

	if (!data->win)
		return (1);
	i = -1;
	while (data->map.map[++i])
	{
		j = 0;
		width = 0;
		while (data->map.map[i][j] && data->map.map[i][j] != '\n')
		{
			analyze_chars(data, width, i, j);
			width += IMG_SIZE;
			j++;
		}
	}
	return (0);
}

void	init_images(t_data *data)
{
	data->img.ground = mlx_xpm_file_to_image(data->mlx, GROUND,
			&data->img.width, &data->img.height);
	data->img.exit_l = mlx_xpm_file_to_image(data->mlx, LOCKED,
			&data->img.width, &data->img.height);
	data->img.player = mlx_xpm_file_to_image(data->mlx, PLAYER,
			&data->img.width, &data->img.height);
	data->img.wall = mlx_xpm_file_to_image(data->mlx, W_RAND,
			&data->img.width, &data->img.height);
	data->img.coin1 = mlx_xpm_file_to_image(data->mlx, COIN1,
			&data->img.width, &data->img.height);
}

void	init_window(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		error_msg(ERR_MLX_INIT, data);
	data->win = mlx_new_window(data->mlx, data->win_width,
			data->win_height, WIN_NAME);
	if (!data->win)
		error_msg(ERR_NEW_WIN, data);
}

void	init_player(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (data->map.map[++i])
	{
		j = -1;
		while (data->map.map[i][++j])
		{
			if (data->map.map[i][j] == 'P')
			{
				data->p_i = i;
				data->p_j = j;
			}
		}
	}
}
