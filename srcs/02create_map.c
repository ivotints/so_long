/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02create_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:28:28 by ivotints          #+#    #+#             */
/*   Updated: 2024/02/26 18:03:32 by ivotints         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_map(t_data *data)
{
	data->map.count_p = 0;
	data->map.count_e = 0;
	data->map.count_c = 0;
	data->map.collected = 0;
	data->map.can_exit = 0;
	data->steps_count = 0;
	data->win_height = data->map.line_count * IMG_SIZE;
	data->win_width = (ft_strlen(data->map.map[0]) - 1) * IMG_SIZE;
	data->img.height = IMG_SIZE;
	data->img.width = IMG_SIZE;
}

void	fill_rows(t_data *data)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	line = get_next_line(data->map.fd);
	while (line)
	{
		j = -1;
		data->map.map[i] = ft_calloc(ft_strlen(line) + 1, sizeof(char));
		if (!data->map.map[i])
			error_msg(ERR_MALLOC, data);
		while (line[++j])
			data->map.map[i][j] = line[j];
		data->map.map[i++][j] = '\0';
		free(line);
		line = get_next_line(data->map.fd);
	}
	data->map.map[i] = NULL;
}

//to recive number of rows
int	count_rows(char *path)
{
	int		fd;
	char	*line;
	int		rows;

	rows = 0;
	fd = open (path, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		rows++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (rows);
}

void	create_map(char *path, t_data *data)
{
	data->map.line_count = count_rows(path);
	data->map.path = path;
	data->map.map = ft_calloc(data->map.line_count + 1, sizeof(char *));
	if (!(data->map.map))
		error_msg(ERR_MALLOC, NULL);
	data->map.fd = open(path, O_RDONLY);
	fill_rows(data);
	close(data->map.fd);
}
