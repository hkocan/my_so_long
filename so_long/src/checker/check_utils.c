/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkocan <hkocan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:55:48 by hkocan            #+#    #+#             */
/*   Updated: 2024/03/01 05:41:54 by hkocan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft/libft.h"
#include "../../inc/solong.h"
#include <stdlib.h>

int	check_map_cep(char **map, t_checker *check)
{
	check->i = -1;
	while (check->i++, map[check->i])
	{
		check->j = -1;
		while (check->j++, map[check->i][check->j] != '\n'
			&& map[check->i][check->j] != '\0')
		{
			if (map[check->i][check->j] != '1' && map[check->i][check->j] != '0'
				&& map[check->i][check->j] != 'C'
				&& map[check->i][check->j] != 'E'
				&& map[check->i][check->j] != 'P')
				return (free(check), 0);
			if (map[check->i][check->j] == 'C')
				check->coincount++;
			if (map[check->i][check->j] == 'P')
				check->playercount++;
			if (map[check->i][check->j] == 'E')
				check->exitcount++;
		}
	}
	if (check->playercount != 1 || check->coincount < 1
		|| check->exitcount != 1)
		return (free(check), 0);
	return (free(check), 1);
}

int	check_map_wall(t_data *solong)
{
	t_checker	check;

	check.i = 0;
	check.j = 0;
	while (solong->map[check.i][check.j] != '\n')
		if (solong->map[check.i][check.j++] != '1')
			return (0);
	check.j = 0;
	check.i = (solong->map_height) - 1;
	while (solong->map[check.i][check.j] != '\0')
		if (solong->map[check.i][check.j++] != '1')
			return (0);
	check.i = 0;
	while (solong->map[check.i])
	{
		if (solong->map[check.i][check.j - 1] != '1')
			return (0);
		if (solong->map[check.i++][0] != '1')
			return (0);
	}
	return (1);
}

static void	path_finding(t_data *solong, int x, int y)
{
	if (solong->map[x][y] == '1')
		return ;
	else if (solong->map[x][y] == 'C')
		solong->coins++;
	else if (solong->map[x][y] == 'E')
		solong->is_error = 1;
	solong->map[x][y] = '1';
	path_finding(solong, x - 1, y);
	path_finding(solong, x, y - 1);
	path_finding(solong, x + 1, y);
	path_finding(solong, x, y + 1);
}

static void	player_location(t_data *solong)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (solong->map[x])
	{
		while (solong->map[x][y])
		{
			if (solong->map[x][y] == 'P')
			{
				solong->pl_x = x;
				solong->pl_y = y;
			}
			if (solong->map[x][y] == 'C')
				solong->coins_checker++;
			y++;
		}
		y = 0;
		x++;
	}
}

int	is_path_ok(t_data *data)
{
	player_location(data);
	path_finding(data, data->pl_x, data->pl_y);
	if (data->coins_checker != data->coins)
	{
		ft_printf("Coin error!!");
		return (0);
	}
	if (!data->is_error)
	{
		ft_printf("Exit error!!");
		return (0);
	}
	return (1);
}
