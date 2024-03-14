/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkocan    <hkocan@student.42kocaeli.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:55:48 by hkocan            #+#    #+#             */
/*   Updated: 2024/02/26 15:03:56 by hkocan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/mlx/mlx.h"
#include "../../inc/solong.h"

static void	render_putimagehelper(char loc, t_data *data, int x, int y)
{
	if (loc == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->wallimg, x * WIDTH,
			y * HEIGHT);
	else if (loc == 'C')
		mlx_put_image_to_window(data->mlx, data->win, data->coinimg, x * WIDTH,
			y * HEIGHT);
	else if (loc == 'E')
		mlx_put_image_to_window(data->mlx, data->win, data->exitimg, x * WIDTH,
			y * HEIGHT);
	else if (loc == 'P' && data->is_player_init == 0)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->playerimg, x
			* WIDTH, y * HEIGHT);
		data->is_player_init = 1;
		data->pl_x = x;
		data->pl_y = y;
	}
	else
		mlx_put_image_to_window(data->mlx, data->win, data->groundimg, x
			* WIDTH, y * HEIGHT);
}

void	render_map(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map_height && data->map[y])
	{
		x = 0;
		while (data->map[y][x] != '\n' && data->map[y][x] != '\0')
		{
			render_putimagehelper(data->map[y][x], data, x, y);
			x++;
		}
		y++;
	}
}
