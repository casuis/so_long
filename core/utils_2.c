/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 19:07:33 by asimon            #+#    #+#             */
/*   Updated: 2022/01/04 19:59:25 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int		ft_same_char(char *str)
{
	int		i;
	char	buff;

	i = 0;
	if (str)
		buff = str[0];
	else
		return (-1);
	while (str[i])
	{
		if (str[i] != buff)
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		y;
	char	*ret;

	i = 0;
	y = 0;
	ret = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (ret == NULL)
		return (NULL);
	while (s1[i])
	{
		ret[i] = s1[i];
		i++;
	}
	while (s2[y])
	{
		ret[i] = s2[y];
		i++;
		y++;
	}
	ret[i] = '\0';
	return (ret);
}
