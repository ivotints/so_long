/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03check_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:29:18 by ivotints          #+#    #+#             */
/*   Updated: 2024/02/26 15:34:50 by ivotints         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_edges(t_data *data, char **map, int line_count)
{
	int	i;

	i = 1;
	check_top(data, map, line_count);
	while (i < line_count)
	{
		if (map[i][0] != '1' || map[i][data->map.line_len - 1] != '1')
			error_msg(ERR_EDGES3, data);
		i++;
	}
}

void	check_rectangle(t_data *data)
{
	int		i;
	size_t	j;

	i = 0;
	data->map.line_len = ft_strlen(data->map.map[i]) - 1;
	while (data->map.map[++i])
	{
		j = 0;
		while (data->map.map[i][j] && data->map.map[i][j] != '\n')
			j++;
		if (j != data->map.line_len)
			error_msg(ERR_MAPL, data);
	}
}

void	check_pec_amount_on_error(t_data *data)
{
	if (data->map.count_p < 1)
		error_msg(ERR_PLAYER1, data);
	if (data->map.count_p > 1)
		error_msg(ERR_PLAYER2, data);
	if (data->map.count_e < 1)
		error_msg(ERR_EXIT1, data);
	if (data->map.count_e > 1)
		error_msg(ERR_EXIT2, data);
	if (data->map.count_c < 1)
		error_msg(ERR_COLECT, data);
}

void	check_pec_amount(t_data *data)
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
				data->map.count_p++;
			else if (data->map.map[i][j] == 'E')
				data->map.count_e++;
			else if (data->map.map[i][j] == 'C')
				data->map.count_c++;
		}
	}
	check_pec_amount_on_error(data);
}

void	check_map(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (data->map.map[++i])
	{
		j = 0;
		while (j < ft_strlen(data->map.map[i]) - 1)
			if (ft_strchr("01CEP", data->map.map[i][j++]) == NULL)
				error_msg(ERR_OTHER_CHAR, data);
	}
	check_pec_amount(data);
	check_rectangle(data);
	check_edges(data, data->map.map, data->map.line_count - 1);
}
