/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 13:40:39 by asimon            #+#    #+#             */
/*   Updated: 2022/01/07 23:06:42 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*get_map(int fd)
{
	char	*line_map;
	char	*buff;
	int		char_count;
	char	*tmp_buff;

	line_map = ft_strdup("");
	buff = ft_strdup("");
	char_count = gnl(fd, &line_map);
	if (char_count > 0)
	{
		tmp_buff = ft_strdup("");
		while (char_count > 0)
		{
			buff = ft_strjoin(buff, line_map);
			free(tmp_buff);
			free(line_map);
			line_map = ft_strdup("");
			char_count = gnl(fd, &line_map);
			tmp_buff = buff;
		}
		return (buff);
	}
	ft_error("Error\nWrong lecture map\n");
	return (NULL);
}

char	**parse_map(int fd, data_t *data)
{
	int		i;
	char	**test;

	i = 1;
	data->map = ft_split(get_map(fd), '\n');
	ft_check_content(data);
	if (!(ft_check_format(data->map)))
		return (NULL);
	if (!(ft_check_line(data->map[0], data->content.wall, data)))
		return (NULL);
	while (data->map[i] != NULL)
	{
		if (!(ft_check_col(data->map[i], data->content.wall, data)))
			return (NULL);
		else if (!(ft_check_other(data->map[i], &(data->content))))
			return (NULL);
		i++;
	}
	data->height = i;
	if (data->content.count_c == 0 || data->content.count_e != 1
		|| data->content.count_p != 1)
		return (ft_error("Error\nNeed 1 Player/Exit and at least 1 Object\n"));
	if (!(ft_check_line(data->map[i - 1], data->content.wall, data)))
		return (NULL);
	if (data->content.count_p == 0 || data->content.count_e == 0)
		return (ft_error("Error\nWrong number of exit or player\n"));
	return (data->map);
}

char	**map_core(char **str, data_t *data)
{
	int		fd;

	fd = 0;
	data->map = NULL;
	if (ft_strchr(str[1], ".ber") == 0)
		return (ft_error("Error\nNo correct format map founded\n"));
	else
	{
		fd = open(str[1], O_RDONLY);
		if (fd != 0)
			data->map = parse_map(fd, data);
		else
			return (ft_error("Error\nFailed to open file\n"));
	}
	return (data->map);
}
