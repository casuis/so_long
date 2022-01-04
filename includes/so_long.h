/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 19:21:35 by asimon            #+#    #+#             */
/*   Updated: 2022/01/04 20:00:10 by asimon           ###   ########.fr       */
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

typedef struct	img
{
	void	*mlx_img;
	char	*adrss;
	int	bpp;
	int	line_len;
	int	endian;
}			img_t;

typedef struct	data_s
{
	void	*mlx_ptr;
	void	*mlx_win;
	img_t	*mlx_img;
}				data_t;

int		chk_map(char **argv);
int		ft_strchr(char *str, char *cmp);
void	ft_error(char *str);
int		ft_strlen(char *str);
char	*ft_strdup(char *str);
char	*ft_strncpy(char *str, int nb);
int		gnl(int fd, char **str);
char	*ft_strjoin(char *s1, char *s2);
int		ft_same_char(char *str);

#endif
