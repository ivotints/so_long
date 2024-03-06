/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 13:33:43 by ivotints          #+#    #+#             */
/*   Updated: 2024/02/26 18:22:44 by ivotints         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include "../mlx/mlx.h"
# include <string.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

//Colors
# define RED "\033[0;31m"
# define RESET "\033[0m"
# define WHITE "\033[1;37m"

# define MAP_EXTENSION ".ber"
//Errors
# define ERR_IS_DIR "It is a directory"
# define ERR_FAIL_TO_OPEN_FILE "The file cannot be opened"
# define ERR_TOO_SHORT_NAME "Too short map path"
# define ERR_EXTENSION "Wrong argument. Extension \".ber\" was not found"
# define ERRTOOLOW "Please enter map path"
# define ERRTOOHIGH "Too many arguments. Please enter only one map path"
# define ERR_MALLOC "Failed to allocate memory"
# define ERR_OTHER_CHAR "The map file contains unauthorized characters"
# define ERR_PLAYER1 "There must be at least one player on the map."
# define ERR_PLAYER2 "There cannot be more than one player on the map."
# define ERR_EXIT1 "There must be at least one exit on the map."
# define ERR_EXIT2 "There cannot be more than one exit on the map."
# define ERR_COLECT "There are no collectibles on the map. Must be at least one"
# define ERR_MAPL "The lines are not the same length. The map isn't rectangular"
# define ERR_EDGES1 "The lower part of the map is not covered by walls."
# define ERR_EDGES2 "The upper part of the map is not covered by walls."
# define ERR_EDGES3 "The side of the map is not covered by walls."
# define ERR_MLX_INIT "Failed to initialize mlx."
# define ERR_NEW_WIN "Failed to create window"
# define ERR_RENDER "No window to render"
# define ERR_EXIT_FLOOD "The map is impassable. Unable to reach exit"
# define ERR_COIN_FLOOD "The map is impassable. \
It is impossible to collect all the emeralds"
# define ERR_EXIT_FLOOD_BLOCK "The map is impassable. The exit does not allow \
to collect all the emiralds."

//window
# define IMG_SIZE 40
# define WIN_NAME "Minekart"

//textures
# define GROUND "assets/ground.xpm"
# define LOCKED "assets/exit.xpm"
# define PLAYER "assets/player.xpm"
# define W_RAND "assets/wall.xpm"
# define COIN1 "assets/coin.xpm"

typedef struct s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct s_img
{
	void	*mlx_img;
	int		width;
	int		height;
	void	*wall;
	void	*exit_l;
	void	*ground;
	void	*player;
	int		line_length;
	void	*coin1;
}				t_img;

typedef struct s_map
{
	int		fd;
	int		line_count;
	size_t	line_len;
	int		count_p;
	int		count_e;
	int		count_c;
	char	*path;
	char	**map;
	int		can_exit;
	int		collected;
}				t_map;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		steps_count;
	int		p_i;
	int		p_j;
	int		win_height;
	int		win_width;
	t_img	img;
	t_map	map;
}				t_data;

void	check_extension(char *path);
void	error_msg(char *str, t_data *data);
void	ft_free(char **tab);
void	create_map(char *path, t_data *data);
int		count_rows(char *path);
void	fill_rows(t_data *data);
void	init_map(t_data *data);
void	check_map(t_data *data);
void	check_pec_amount(t_data *data);
void	check_pec_amount_on_error(t_data *data);
void	check_rectangle(t_data *data);
void	check_edges(t_data *data, char **map, int line_count);
void	check_top(t_data *data, char **map, int line_count);
void	init_player(t_data *data);
void	check_flood_fill(t_data *data, char **map);
char	**ft_make_map_copy(t_data *data, char **map);
void	fill(char **tab, t_point size, t_point cur);
void	fill_e(char **tab, t_point size, t_point cur);
void	check_pec_flood_fill(char **map, t_data *data, char exit);
void	init_window(t_data *data);
void	init_images(t_data *data);
int		render(t_data *data);
void	analyze_chars(t_data *data, int width, int i, int j);
void	loop_images(t_data data);
int		handle_keypress(int keysym, t_data *data);
void	move_player(t_data *data, char di);
int		checknt(t_data *data, char di, char til, char **map);
void	collect_coins(t_data *data, char di, char **map);
void	move_msg(t_data *data);
int		handle_button_r(t_data *data);
void	destroy_images(t_data data);

#endif
