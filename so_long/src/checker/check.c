/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkocan <hkocan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:55:48 by hkocan            #+#    #+#             */
/*   Updated: 2024/03/01 02:38:19 by hkocan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft/libft.h"
#include "../../inc/solong.h"

static void	map_rectangle(t_data *data)
{
	int	width;
	int	height;
	int	current_width;

	width = data->map_width;
	height = 0;
	current_width = 0;
	while (data->map[height] != NULL)
	{
		current_width = 0;
		while (data->map[height][current_width] != '\0'
			&& data->map[height][current_width] != '\n')
			current_width++;
		if (current_width != width)
		{
			error_message("Map is not rectangle!");
			exit_free(data, 1);
		}
		height++;
	}
}

int	main_checker(t_data *data)
{
	t_checker	*check;

	map_rectangle(data);
	check = ft_calloc(sizeof(t_checker), 1);
	if (!check)
		return (0);
	if (check_map_cep(data->map, check) == 0)
	{
		error_message("Map is not contain 1, 0, E, C, P or P, E repeating");
		exit_free(data, 1);
	}
	else if (check_map_wall(data) == 0)
	{
		error_message("There is no valid wall!");
		exit_free(data, 1);
	}
	else if (is_path_ok(data) == 0)
	{
		error_message("There is no valid path!");
		exit_free(data, 1);
	}
	return (1);
}
