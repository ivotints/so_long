/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04check_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:30:18 by ivotints          #+#    #+#             */
/*   Updated: 2024/02/26 17:52:00 by ivotints         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_top(t_data *data, char **map, int line_count)
{
	int	i;

	i = 0;
	while (map[line_count][i] && map[line_count][i] != '\n')
		if (map[line_count][i++] != '1')
			error_msg(ERR_EDGES1, data);
	i = 0;
	while (map[0][i] && map[0][i] != '\n')
		if (map[0][i++] != '1')
			error_msg(ERR_EDGES2, data);
}
