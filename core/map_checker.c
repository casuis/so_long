/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:45:16 by asimon            #+#    #+#             */
/*   Updated: 2022/01/05 18:10:35 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_check_col(char *map_line, char wall, data_t *data)
{
	int		i;

	i = 0;
	while (map_line[i])
		i++;
	if (map_line[0] != wall || map_line[i - 1] != wall)
	{
		ft_error("Error\nMap column not close\n");
		return (0);
	}
	data->width = i;
	return (1);
}

int	ft_check_line(char *map_line, char wall, data_t *data)
{
	int		i;

	i = 0;
	while (map_line[i])
	{
		if (map_line[i] != wall)
		{
			ft_error("Error\nMap line not close\n");
			return (0);
		}
		i++;
	}
	data->height = i;
	return (1);
}

int	ft_check_other(char *map_line,cnt_t *content)
{
	int		i;

	i = 0;
	while (map_line[i])
	{
		if (map_line[i] == content->player)
			content->count_p += 1;
		if (map_line[i] == content->exit)
			content->count_e += 1;
		if (content->count_e > 1 || content->count_p > 1)
		{
			ft_error("Error\nWrong number of player or exit\n");
			return (0);
		}
		if (map_line[i] != content->wall && map_line[i] != content->player
			&& map_line[i] != content->exit && map_line[i] != content->collect
			&& map_line[i] != content->space)
		{
			ft_error("Error\nUnknown symbol(s) in map\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_same_char(char *str)
{
	int		i;
	char	buff;

	i = 0;
	buff = '1';
	if (str == NULL)
		return (-1);
	while (str[i])
	{
		if (str[i] != buff && str[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_format(char **map)
{
	int		y;
	int		x;
	int		count_x;

	x = 0;
	y = 0;
	count_x = 0;
	while (map[0][count_x])
		count_x++;
	while (map[y] != NULL)
	{
		while (map[y][x])
			x++;
		if (x != count_x)
		{
			ft_error("Error\nMap must be a rectangle or a square\n");
			return (0);
		}
		x = 0;
		y++;
	}
	return (1);
}
