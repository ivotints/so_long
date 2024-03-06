/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01check_extension.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:27:33 by ivotints          #+#    #+#             */
/*   Updated: 2024/02/26 15:28:05 by ivotints         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_free(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	tab = NULL;
	return ;
}

void	error_msg(char *str, t_data *data)
{
	ft_putstr_fd(RED, 2);
	ft_putstr_fd("Error. ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd(RESET, 2);
	if (data && data->map.map)
		ft_free(data->map.map);
	exit(1);
}

//__O_DIRECTORY can open only directory. If it is a file, it will return -1
//files named ".her", which means hidden file, are also counted as an extension
//if file name is "*.ber " - with space at the end we display error as "cd" does
void	check_extension(char *path)
{
	size_t	len;
	size_t	len_ext;
	int		fd;

	len = ft_strlen(path);
	len_ext = ft_strlen(MAP_EXTENSION);
	if (len < len_ext)
		error_msg(ERR_TOO_SHORT_NAME, NULL);
	if (ft_strcmp(path + len - len_ext, MAP_EXTENSION))
		error_msg(ERR_EXTENSION, NULL);
	fd = open(path, __O_DIRECTORY);
	if (fd != -1)
	{
		close (fd);
		error_msg(ERR_IS_DIR, NULL);
	}
	fd = open(path, O_RDONLY);
	if (fd == -1)
		error_msg(ERR_FAIL_TO_OPEN_FILE, NULL);
	close (fd);
}
