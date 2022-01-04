#include "../includes/so_long.h"

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

int	rend_one_block(data_t *data)
{
	void	*img_txt;
	int		width;
	int		height;
	int		x;
	int		y;

	width = 128;
	height = 128;
	x = 0;
	y = 0;
	img_txt = mlx_xpm_file_to_image(data->mlx_ptr, "./silver.xpm", &width, &height);
	if (img_txt != NULL)
	{
		while (y < WINDOW_WIDTH)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, img_txt, y, 0);
			y += width;
		}
		
	}
	else
		printf("fail to open img");
	return (1);
}

int	render(data_t *data)
{
	if (data->mlx_ptr != NULL)
	{
		rend_one_block(data);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	data_t	data;
	if (argc != 1)
		return (0);
	else
	{
		if (chk_map(argv) == 0)
			return (0);
		data.mlx_ptr = mlx_init();
		if (data.mlx_ptr == NULL)
			return (MLX_ERROR);
		data.mlx_win = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "so_long");
		if (data.mlx_win == NULL)
		{
			free(data.mlx_ptr);
			return (MLX_ERROR);
		}
		data.mlx_img = mlx_new_image(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
		mlx_loop_hook(data.mlx_ptr, &render, &data);
		mlx_hook(data.mlx_win, KeyPress, KeyPressMask, &key_press, &data);
		mlx_hook(data.mlx_win, KeyRelease, KeyReleaseMask, &handle_input, &data);
		mlx_loop(data.mlx_ptr);
		mlx_destroy_window(data.mlx_ptr, data.mlx_win);
		mlx_destroy_display(data.mlx_ptr);
		free(data.mlx_ptr);
	}
	return (EXIT_SUCCESS);
}

