#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "./minilibx-linux/mlx.h"
#include <X11/keysym.h>
#include <X11/X.h>

# define WINDOW_WIDTH 600
# define WINDOW_HEIGHT 300

# define MLX_ERROR 1

# define RED_PIXEL 0xFF0000

typedef struct	data_s
{
	void	*mlx_ptr;
	void	*mlx_win;
}				data_t;


typedef struct	rect
{
	int	x;
	int	y;
	int	width;
	int	height;
	int	color;
}			rect_t;

int	nothing_todo(void *data)
{
	return (0);
}

int	key_press(int keysym, data_t *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
		return (0);
	}
	printf("Keypress: %d\n", keysym);
	return (0);
}

int	handle_input(int keysym, data_t *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
		return (0);
	}
	printf("Keyrelease: %d\n", keysym);
	return (0);
}

int	rend_rect(data_t *data, rect_t rect)
{
	int	i;
	int	j;

	if (data->mlx_win == NULL)
		return (1);
	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
	}
}

int	render(data_t *data)
{
	if (data->mlx_win != NULL)
		mlx_pixel_put(data->mlx_ptr, data->mlx_win, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, RED_PIXEL);
	return (0);
}

int	main(int argc, char **argv)
{
	data_t	data;

	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (MLX_ERROR);
	data.mlx_win = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "so_long");
	if (data.mlx_win == NULL)
	{
		free(data.mlx_ptr);
		return (MLX_ERROR);
	}
	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_hook(data.mlx_win, KeyPress, KeyPressMask, &key_press, &data);
	mlx_hook(data.mlx_win, KeyRelease, KeyReleaseMask, &handle_input, &data);
	mlx_loop(data.mlx_ptr);
	mlx_destroy_window(data.mlx_ptr, data.mlx_win);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
	return (EXIT_SUCCESS);
}

