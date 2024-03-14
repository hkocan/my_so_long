/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkocan <hkocan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:55:48 by hkocan            #+#    #+#             */
/*   Updated: 2024/03/01 05:20:20 by hkocan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft/libft.h"
#include "../inc/solong.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

void	calculate_map_height(char *file_name, t_data *data)
{
	char	*line;

	data->fd = open(file_name, O_RDONLY);
	if (data->fd == -1)
	{
		error_message("File descriptor error!");
		exit_free(data, 1);
	}
	line = get_next_line(data->fd);
	if (!line)
	{
		error_message("Map is empty!");
		exit_free(data, 1);
	}
	data->map_width = ft_strlen(line) - 1;
	while (line != NULL)
	{
		data->map_height++;
		free(line);
		line = get_next_line(data->fd);
	}
	close(data->fd);
}

char	**parse_map(t_data *data, char *filename)
{
	char	*line;
	char	**map;
	int		i;

	data->fd = open(filename, O_RDONLY);
	if (data->fd == -1)
		exit_free(data, 1);
	map = ft_calloc(sizeof(char *), (data->map_height + 1));
	if (!map)
		exit_free(data, 1);
	i = 0;
	line = get_next_line(data->fd);
	while (line)
	{
		map[i++] = ft_strdup(line);
		free(line);
		line = get_next_line(data->fd);
	}
	map[i] = NULL;
	close(data->fd);
	return (map);
}
