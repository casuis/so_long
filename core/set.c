/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 13:16:08 by asimon            #+#    #+#             */
/*   Updated: 2022/01/05 19:28:50 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	set_content(cnt_t *content)
{
	content->exit = 'E';
	content->player = 'P';
	content->wall = '1';
	content->space = '0';
	content->collect = 'C';
	content->count_p = 0;
	content->count_e = 0;
}

void	set_img(data_t *data)
{
	data->img.height = 80;
	data->img.width = 80;
	data->img.floor = "../rsrc/floor_texture.xpm";
	data->img.wall = "../rsrc/wall_texture.xpm";
	data->img.collect = "../rsrc/collectible_texture.xpm";
	data->img.perso = "../rsrc/perso_texture.xpm";
	data->img.exit = "../rsrc/exit_texture.xpm";
	data->img.img_wall = mlx_xpm_file_to_image(
	data->mlx_ptr, data->img.wall, &(data->img.width), &(data->img.height));
	data->img.img_floor = mlx_xpm_file_to_image(
	data->mlx_ptr, data->img.floor, &(data->img.width), &(data->img.height));
	data->img.img_exit = mlx_xpm_file_to_image(
	data->mlx_ptr, data->img.exit, &(data->img.width), &(data->img.height));
	data->img.img_collect = mlx_xpm_file_to_image(
	data->mlx_ptr, data->img.collect, &(data->img.width), &(data->img.height));
	data->img.img_perso = mlx_xpm_file_to_image(
	data->mlx_ptr, data->img.perso, &(data->img.width), &(data->img.height));
}
