/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzbair <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 03:19:00 by mzbair            #+#    #+#             */
/*   Updated: 2026/08/02 09:17:21 by mzbair           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	len_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*str_copy(char *str)
{
	char	*copy;
	int		len;
	int		i;

	i = 0;
	len = len_str(str);
	copy = malloc(sizeof(char) * (len +1));
	if (!copy)
		return (NULL);
	copy[len--] = '\0';
	while (i <= len)
	{
		copy[i] = str[i];
		i++;
	}
	return (copy);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*stock;
	char		*cp;

	i = 0;
	stock = malloc(sizeof(t_stock_str) * (ac + 1));
	if (!stock)
		return (NULL);
	stock[ac--].str = 0;
	while (i <= ac)
	{
		stock[i].size = len_str(av[i]);
		stock[i].str = av[i];
		cp = str_copy(av[i]);
		if (cp == NULL)
			return (NULL);
		stock[i].copy = cp;
		i++;
	}
	return (stock);
}
