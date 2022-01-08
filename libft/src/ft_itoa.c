/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 18:50:26 by asimon            #+#    #+#             */
/*   Updated: 2022/01/08 21:38:55 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char	*ft_count(int nb, int *size)
{
	char	*ret;

	*size = 1;
	if (nb < 0 && nb != -2147483648)
	{
		nb = -nb;
		(*size)++;
	}
	else if (nb == -2147483648)
	{
		*size = 11;
		ret = (char *)malloc(sizeof(char) * (*size + 1));
		return (ret);
	}
	while (nb / 10 > 0)
	{
		nb /= 10;
		*size += 1;
	}
	ret = (char *)malloc(sizeof(char) * (*size + 1));
	return (ret);
}

static char	*ft_insert(char *ret, int neg, int size, int n)
{
	while ((size > 0 && neg == 0) || (size > 1 && neg == 1))
	{
		ret[--size] = (n % 10 + 48);
		n /= 10;
	}
	if (neg == 1)
	{
		ret[size - 1] = '-';
	}
	return (ret);
}

char	*ft_itoa(int n)
{
	char	*ret;
	int		neg;
	int		size[2];

	neg = 0;
	size[0] = 0;
	ret = ft_count(n, &size[0]);
	if (ret == NULL)
		return (NULL);
	size[1] = size[0];
	if (n < 0 && n != -2147483648)
	{
		n = -n;
		neg = 1;
	}
	else if (n == -2147483648)
	{
		ret[size[0] - 1] = '8';
		n = (n / 10) * -1;
		neg = 1;
		size[1] -= 1;
	}
	ret = ft_insert(ret, neg, size[1], n);
	ret[size[0]] = '\0';
	return (ret);
}
