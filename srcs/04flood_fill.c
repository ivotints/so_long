/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04flood_fill.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:52:02 by ivotints          #+#    #+#             */
/*   Updated: 2024/02/26 17:52:13 by ivotints         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_pec_flood_fill(char **map, t_data *data, char exit)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'E' && !exit)
			{
				ft_free(map);
				error_msg(ERR_EXIT_FLOOD, data);
			}
			else if (map[i][j] == 'C')
			{
				ft_free(map);
				if (exit == 1)
					error_msg(ERR_EXIT_FLOOD_BLOCK, data);
				error_msg(ERR_COIN_FLOOD, data);
			}
		}
	}
}

void	fill(char **tab, t_point size, t_point cur)
{
	if (tab[cur.y][cur.x] == '1' || tab[cur.y][cur.x] == 'F')
		return ;
	tab[cur.y][cur.x] = 'F';
	fill(tab, size, (t_point){cur.x - 1, cur.y});
	fill(tab, size, (t_point){cur.x + 1, cur.y});
	fill(tab, size, (t_point){cur.x, cur.y - 1});
	fill(tab, size, (t_point){cur.x, cur.y + 1});
}

void	fill_e(char **tab, t_point size, t_point cur)
{
	if (tab[cur.y][cur.x] == '1' || tab[cur.y][cur.x] == 'F'
		|| tab[cur.y][cur.x] == 'E')
		return ;
	tab[cur.y][cur.x] = 'F';
	fill_e(tab, size, (t_point){cur.x - 1, cur.y});
	fill_e(tab, size, (t_point){cur.x + 1, cur.y});
	fill_e(tab, size, (t_point){cur.x, cur.y - 1});
	fill_e(tab, size, (t_point){cur.x, cur.y + 1});
}

char	**ft_make_map_copy(t_data *data, char **map)
{
	int		i;
	size_t	j;
	char	**map_copy;

	i = -1;
	map_copy = (char **)ft_calloc(data->map.line_count + 1, sizeof(char *));
	if (!map_copy)
		error_msg(ERR_MALLOC, data);
	while (++i < data->map.line_count)
	{
		map_copy[i] = (char *)ft_calloc(data->map.line_len + 1, sizeof(char));
		if (!map_copy[i])
			error_msg(ERR_MALLOC, data);
		j = -1;
		while (++j < data->map.line_len)
			map_copy[i][j] = map[i][j];
		map_copy[i][j] = '\0';
	}
	map_copy[i] = NULL;
	return (map_copy);
}

void	check_flood_fill(t_data *data, char **map)
{
	char	**map_copy;

	map_copy = ft_make_map_copy(data, map);
	fill(map_copy, (t_point){data->map.line_len, data->map.line_count},
		(t_point){data->p_j, data->p_i});
	check_pec_flood_fill(map_copy, data, 0);
	ft_free(map_copy);
	map_copy = ft_make_map_copy(data, map);
	fill_e(map_copy, (t_point){data->map.line_len, data->map.line_count},
		(t_point){data->p_j, data->p_i});
	check_pec_flood_fill(map_copy, data, 1);
	ft_free(map_copy);
}
