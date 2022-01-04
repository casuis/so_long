#include "../includes/so_long.h"

char	*get_map(int fd)
{
	char	*line_map;
	char	*buff;
	int		char_count;
	char	*tmp_buff;

	line_map = ft_strdup("");
	char_count = gnl(fd, &line_map);
	if (char_count > 0 && ft_same_char(line_map))
	{
		tmp_buff = ft_strdup("");
		while (char_count > 0)
		{
			free(tmp_buff);
			buff = ft_strjoin(buff, line_map);
			free(line_map);
			line_map = ft_strdup("");
			char_count = gnl(fd, &line_map);
			tmp_buff = buff;
		}
		if (ft_same_char(buff))
			return (buff);
		free(buff);
	}
	ft_error("Error: Map invalide\n");
	return (NULL);
}

void	parse_map(int fd)
{
}

int	chk_map(char **str)
{
	int	fd;

	fd = 0;
	if (ft_strchr(str[1], ".ber") == 0)
	{
		ft_error("Error: no correct format map founded\n");
		ft_error("Expected: *.ber\n");
		return (0);
	}
	else
	{
		fd = open(str[1], O_RDONLY);
		if (fd != 0)
			parse_map(fd);
		else
		{
			ft_error("Error: open failed\n");
			return (0);
		}
	}
}
