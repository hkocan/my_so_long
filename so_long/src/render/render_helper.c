/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkocan    <hkocan@student.42kocaeli.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:55:48 by hkocan            #+#    #+#             */
/*   Updated: 2024/02/26 15:03:56 by hkocan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft/libft.h"
#include "../../inc/mlx/mlx.h"
#include "../../inc/solong.h"

static void	draw_player(t_data *data)
{
	data->player_moves++;
	ft_printf("Move Count = %d\n", data->player_moves);
	if (data->map[data->pl_y][data->pl_x] == 'C')
	{
		data->map[data->pl_y][data->pl_x] = '0';
		data->coins--;
		ft_printf("coin Count = %d\n", data->coins);
	}
	mlx_clear_window(data->mlx, data->win);
	render_map(data);
	mlx_put_image_to_window(data->mlx, data->win, data->playerimg, data->pl_x
		* WIDTH, data->pl_y * HEIGHT);
	if (data->map[data->pl_y][data->pl_x] == 'E' && data->coins == 0)
	{
		ft_printf("Congratulations! You have completed the game!\n");
		exit_free(data, 0);
	}
}

static void	move(int keycode, t_data *data)
{
	if (keycode == UP)
	{
		data->pl_y -= 1;
		draw_player(data);
	}
	else if (keycode == DOWN)
	{
		data->pl_y += 1;
		draw_player(data);
	}
	else if (keycode == LEFT)
	{
		data->pl_x -= 1;
		draw_player(data);
	}
	else if (keycode == RIGHT)
	{
		data->pl_x += 1;
		draw_player(data);
	}
}

int	key_hook(int keycode, t_data *vars)
{
	if (keycode == UP && vars->map[vars->pl_y - 1][vars->pl_x] != '1')
		move(keycode, vars);
	else if (keycode == LEFT && vars->map[vars->pl_y][vars->pl_x - 1] != '1')
		move(keycode, vars);
	else if (keycode == DOWN && vars->map[vars->pl_y + 1][vars->pl_x] != '1')
		move(keycode, vars);
	else if (keycode == RIGHT && vars->map[vars->pl_y][vars->pl_x + 1] != '1')
		move(keycode, vars);
	else if (keycode == ESC)
		exit_free(vars, 0);
	return (0);
}
