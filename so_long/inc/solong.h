/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkocan <hkocan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:55:48 by hkocan            #+#    #+#             */
/*   Updated: 2024/03/01 03:27:45 by hkocan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# define HEIGHT 64
# define WIDTH 64
# define UP 13
# define DOWN 1
# define LEFT 0
# define RIGHT 2
# define ESC 53

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*groundimg;
	void	*wallimg;
	void	*playerimg;
	void	*exitimg;
	void	*coinimg;
	char	**map;
	int		win_width;
	int		win_height;
	int		map_width;
	int		map_height;
	int		pl_x;
	int		pl_y;
	int		is_player_init;
	int		player_moves;
	int		coins;
	int		coins_checker;
	int		is_error;
	int		fd;
}			t_data;

typedef struct s_checker
{
	int		i;
	int		j;
	int		playercount;
	int		coincount;
	int		exitcount;
}			t_checker;

void		render_map(t_data *data);
char		**parse_map(t_data *data, char *filename);
int			key_hook(int keycode, t_data *vars);
void		exit_free(t_data *data, int code);
void		error_message(char *str);
int			main_checker(t_data *data);
void		calculate_map_height(char *file, t_data *data);
int			check_map_cep(char **map, t_checker *check);
int			check_map_wall(t_data *solong);
int			is_path_ok(t_data *map);
#endif
