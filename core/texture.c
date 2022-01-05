/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 13:51:23 by asimon            #+#    #+#             */
/*   Updated: 2022/01/05 20:36:54 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_parse_background(data_t *data)
{
	int		i;
	int		y;

	i = 0;
	y = 0;
	while (data->map[y] != NULL)
	{
		//printf("salut");
		/*while (data->map[y][i] != '\0')
		{
			if (data->map[y][i] == data->content.wall)
				mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
					data->img.img_wall, (data->img.width * i), (data->img.height * y));
			if (data->map[y][i] == data->content.space)
				mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
					data->img.img_floor, (data->img.width * i), (data->img.height * y));
			i++;
		}*/
		//i = 0;
		y++;
	}
}

int	render(data_t *data)
{
	ft_parse_background(data);
	return (0);
}

void	core_render(data_t *data)
{

	data->mlx_win = mlx_new_window(data->mlx_ptr,
	(data->width * data->img.width), (data->height * data->mg.height), "So_long");
	if (data->mlx_win == NULL)
	{
		free(data->mlx_ptr);
		return ;
	}
	mlx_loop_hook(data->mlx_ptr, &render, &data);
	mlx_loop(data->mlx_ptr);
	mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	mlx_destroy_display(data->mlx_ptr);
}

int	main(int argc, char **argv)
{
	data_t	data;

	if (argc == 1)
		return (0);
	else
	{
		data.mlx_ptr = mlx_init();
		set_content(&(data.content));
		set_img(&data);
		data.map = map_core(argv, &data);
		core_render(&data);
	}
	return (1);
}
