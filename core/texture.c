/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 13:51:23 by asimon            #+#    #+#             */
/*   Updated: 2022/01/07 23:06:39 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	render_background(data_t *data)
{
	int		i;
	int		y;

	i = 0;
	y = 0;
	while (data->map[y] != NULL)
	{
		while (data->map[y][i] != '\0')
		{
			if (data->map[y][i] == data->content.wall)
				mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
					data->img.img_wall, (data->img.width * i), (data->img.height * y));
			if (data->map[y][i] == data->content.space)
				mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
					data->img.img_floor, (data->img.width * i), (data->img.height * y));
			i++;
		}
		i = 0;
		y++;
	}
}

void	render_other(data_t *data)
{
	int		i;
	int		y;

	i = 0;
	y = 0;
	while (data->map[y] != NULL)
	{
		while (data->map[y][i])
		{
			if (data->map[y][i] == data->content.collect)
				mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img.img_collect, (data->img.width * i), (data->img.height * y));
			if (data->map[y][i] == data->content.player)
			{
				data->pos.x = i * data->img.width;
				data->pos.y = y * data->img.height;
				mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img.img_player, (data->img.width * i), (data->img.height * y));
			}
			if (data->map[y][i] == data->content.exit)
				mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img.img_exit, (data->img.width * i), (data->img.height * y));
			i++;
		}
		i = 0;
		y++;
	}
}

int	render(data_t *data)
{
	render_background(data);
	render_other(data);
	return (0);
}


int	chk_coll(data_t *data)
{
	int		i;
	int		y;
	int		count;

	i = 0;
	y = 0;
	count = 0;
	while (data->map[y])
	{
		while (data->map[y][i])
		{
			if (data->map[y][i] == data->content.collect)
				count++;
			i++;
		}
		i = 0;
		y++;
	}
	return (count);
}

int	end(data_t *data)
{
	int		i;
	
	i = 0;
	while (data->map[i] != NULL)
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
	mlx_destroy_image(data->mlx_ptr, data->img.img_wall);
	mlx_destroy_image(data->mlx_ptr, data->img.img_floor);
	mlx_destroy_image(data->mlx_ptr, data->img.img_collect);
	mlx_destroy_image(data->mlx_ptr, data->img.img_player);
	mlx_destroy_image(data->mlx_ptr, data->img.img_exit);
	mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	mlx_destroy_display(data->mlx_ptr);
	printf("Felicitation vous avez gagne en : %d coup !", data->count);
}

void	render_top(data_t *data)
{
	int		pos_x;
	int		pos_y;

	pos_x = data->pos.x / data->img.height;
	pos_y = data->pos.y / data->img.width;
	if (data->map[pos_y - 1][pos_x] != data->content.wall)
	{
		if (!(data->map[pos_y - 1][pos_x] == data->content.exit))
		{
			data->map[pos_y - 1][pos_x] = data->content.player;
			data->map[pos_y][pos_x] = data->content.space;
			data->count += 1;
			printf("count: %d\n", data->count);
		}
		else
			if (chk_coll(data) == 0)
				end(data);
	}
}

int	render_right(data_t *data)
{
	int		pos_x;
	int		pos_y;

	pos_x = data->pos.x / data->img.height;
	pos_y = data->pos.y / data->img.width;
	if (data->map[pos_y][pos_x + 1] != data->content.wall)
	{
		if (!(data->map[pos_y][pos_x + 1] == data->content.exit))
		{
			data->map[pos_y][pos_x + 1] = data->content.player;
			data->map[pos_y][pos_x] = data->content.space;
			data->count += 1;
			printf("count: %d\n", data->count);
		}
		else
			if (chk_coll(data) == 0)
				end(data);
	}
}

void	render_left(data_t *data)
{
	int		pos_x;
	int		pos_y;

	pos_x = data->pos.x / data->img.height;
	pos_y = data->pos.y / data->img.width;
	if (data->map[pos_y][pos_x - 1] != data->content.wall)
	{
		if (!(data->map[pos_y][pos_x - 1] == data->content.exit))
		{
			data->map[pos_y][pos_x - 1] = data->content.player;
			data->map[pos_y][pos_x] = data->content.space;
			data->count += 1;
			printf("count: %d\n", data->count);
		}
		else
			if (chk_coll(data) == 0)
				end(data);
	}
}

void	render_down(data_t *data)
{
	int		pos_x;
	int		pos_y;

	pos_x = data->pos.x / data->img.height;
	pos_y = data->pos.y / data->img.width;
	if (data->map[pos_y + 1][pos_x] != data->content.wall)
	{
		if (!(data->map[pos_y + 1][pos_x] == data->content.exit))
		{
			data->map[pos_y + 1][pos_x] = data->content.player;
			data->map[pos_y][pos_x] = data->content.space;
			data->count += 1;
			printf("count: %d\n", data->count);
		}
		else
			if (chk_coll(data) == 0)
				end(data);
	}
}

int		key_press(int keysym, data_t *data)
{
	if (keysym == XK_Escape)
		end(data);
	if (keysym == XK_w)
		render_top(data);
	if (keysym == XK_d)
		render_right(data);
	if (keysym == XK_a)
		render_left(data);
	if (keysym == XK_s)
		render_down(data);
}

void	core_render(data_t *data)
{
	data->mlx_win = mlx_new_window(data->mlx_ptr,
	(data->width * data->img.width), (data->height * data->img.height), "So_long");
	if (data->mlx_win == NULL)
	{
		free(data->mlx_ptr);
		return ;
	}
	mlx_loop_hook(data->mlx_ptr, &render, data);
	mlx_hook(data->mlx_win, KeyPress, KeyPressMask, &key_press, data);
	mlx_hook(data->mlx_win, 17, 0, &end, data);
	mlx_loop(data->mlx_ptr);
	end(data);
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
		data.count = 0;
		data.map = map_core(argv, &data);
		if (data.map != NULL)
			core_render(&data);
	}
	return (1);
}
