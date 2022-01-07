/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 02:12:39 by arthur            #+#    #+#             */
/*   Updated: 2022/01/07 18:34:17 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int				gnl(int fd, char **str);
char			**ft_split(char *str, char sep);
void			ft_putstr(char *str);
void			ft_putchar(char c);
long long int	ft_atoi(const char *str);
int				ft_isdigit(int c);
char			*ft_itoa(int n);
size_t			ft_strlen(const char *str);

#endif
