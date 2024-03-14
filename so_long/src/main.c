/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkocan <hkocan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:55:48 by hkocan            #+#    #+#             */
/*   Updated: 2024/03/01 05:15:05 by hkocan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft/libft.h"
#include "../inc/mlx/mlx.h"
#include "../inc/solong.h"
#include <stdlib.h>

static void	init_images(t_data *data, int width, int height)
{
	data->groundimg = mlx_xpm_file_to_image(data->mlx, "assets/ground.xpm",
			&width, &height);
	data->wallimg = mlx_xpm_file_to_image(data->mlx, "assets/wall.xpm", &width,
			&height);
	data->coinimg = mlx_xpm_file_to_image(data->mlx, "assets/coin.xpm", &width,
			&height);
	data->playerimg = mlx_xpm_file_to_image(data->mlx, "assets/player.xpm",
			&width, &height);
	data->exitimg = mlx_xpm_file_to_image(data->mlx, "assets/exit.xpm", &width,
			&height);
	if (!data->groundimg || !data->wallimg || !data->coinimg || !data->playerimg
		|| !data->exitimg)
	{
		error_message("Image allocation error!");
		exit_free(data, 1);
	}
}

static void	check_mapname(t_data *data, char *map_file)
{
	if (ft_strncmp(ft_strchr(map_file, '.'), ".ber",
			ft_strlen(ft_strchr(map_file, '.'))))
	{
		error_message("Map file name is incorrect!");
		exit_free(data, 1);
	}
}

static int	win_hook(t_data *data, int key)
{
	exit_free(data, 0);
	return (key);
}

static void	init_game(char *map_file)
{
	t_data	*data;

	data = (t_data *)ft_calloc(sizeof(t_data), 1);
	if (!data)
		(error_message("Malloc Error!"), exit (1));
	check_mapname(data, map_file);
	calculate_map_height(map_file, data);
	data->map = parse_map(data, map_file);
	main_checker(data);
	exit_free(data, 2);
	data->map = parse_map(data, map_file);
	data->mlx = mlx_init();
	if (!data->mlx)
		exit_free(data, 1);
	data->win = mlx_new_window(data->mlx, (data->map_width * WIDTH),
			(data->map_height * HEIGHT), "Hello world!");
	if (!data->win)
		exit_free(data, 0);
	init_images(data, WIDTH, HEIGHT);
	render_map(data);
	mlx_key_hook(data->win, key_hook, data);
	mlx_hook(data->win, 17, 0, win_hook, data);
	mlx_loop(data->mlx);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		error_message("Argument count error!");
		return (1);
	}
	init_game(argv[1]);
	return (0);
}
