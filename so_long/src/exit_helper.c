/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkocan <hkocan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:55:48 by hkocan            #+#    #+#             */
/*   Updated: 2024/03/01 05:24:49 by hkocan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft/libft.h"
#include "../inc/mlx/mlx.h"
#include "../inc/solong.h"
#include <stdlib.h>
#include <unistd.h>

void	error_message(char *str)
{
	size_t	len;

	len = ft_strlen(str);
	write(2, str, (len + 1));
	write(1, "\n", 1);
}

static void	mlx_free(t_data *data)
{
	if (data->groundimg)
		mlx_destroy_image(data->mlx, data->groundimg);
	if (data->wallimg)
		mlx_destroy_image(data->mlx, data->wallimg);
	if (data->coinimg)
		mlx_destroy_image(data->mlx, data->coinimg);
	if (data->playerimg)
		mlx_destroy_image(data->mlx, data->playerimg);
	if (data->exitimg)
		mlx_destroy_image(data->mlx, data->exitimg);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
}

void	exit_free(t_data *data, int code)
{
	int	i;

	i = 0;
	if (data->map)
	{
		while (data->map[i])
			free(data->map[i++]);
		free(data->map);
	}
	if (data->mlx && code != 2)
		mlx_free(data);
	if (data->fd > 0)
		close(data->fd);
	if (data && code != 2)
		free(data);
	if (code != 2)
		exit(code);
}
