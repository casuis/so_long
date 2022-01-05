/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 19:21:35 by asimon            #+#    #+#             */
/*   Updated: 2022/01/05 19:36:58 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include "../includes/mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>
# include <fcntl.h>

# define WINDOW_WIDTH 1800
# define WINDOW_HEIGHT 900

# define MLX_ERROR 1

# define RED_PIXEL 0xFF0000
# define GREEN_PIXEL 0x00FF00

typedef struct	img_s
{
	void	*img_floor;
	void	*img_perso;
	void	*img_exit;
	void	*img_wall;
	void	*img_collect;
	int		height;
	int		width;
	char	*perso;
	char	*floor;
	char	*wall;
	char	*collect;
	char	*exit;
}				img_t;

typedef struct	cnt_s
{
	char	exit;
	char	collect;
	char	player;
	char	wall;
	char	space;
	int		count_p;
	int		count_e;
	int		count_c;
}				cnt_t;

typedef struct	data_s
{
	void	*mlx_ptr;
	void	*mlx_win;
	img_t	*mlx_img;
	int		width;
	int		height;
	char	**map;
	cnt_t	content;
	img_t	img;
}				data_t;

typedef struct pos_s
{
	int		x;
	int		y;
}				pos_t;


int		chk_map(char **argv);
int		ft_strchr(char *str, char *cmp);
void	*ft_error(char *str);
int		ft_strlen(char *str);
char	*ft_strdup(char *str);
char	*ft_strncpy(char *str, int nb);
int		gnl(int fd, char **str);
char	*ft_strjoin(char *s1, char *s2);
int		ft_same_char(char *str);
char	*get_map(int fd);
char	**ft_split(char *str, char sep);
int		ft_check_col(char *map_line, char col, data_t *data);
int		ft_check_line(char *map_line, char wall, data_t *data);
int		ft_check_other(char *map_line, cnt_t *content);
void	set_content(cnt_t *content);
int		ft_check_format(char **map);
char	**map_core(char **str, data_t *data);
void	set_img(data_t *data);

#endif
