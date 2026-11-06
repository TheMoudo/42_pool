/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzbair <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 06:57:43 by mzbair            #+#    #+#             */
/*   Updated: 2026/08/02 09:06:24 by mzbair           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	put_nbr(int nb)
{
	char	c;

	if (nb > 9)
		put_nbr(nb / 10);
	c = (nb % 10) + '0';
	write(1, &c, 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;
	int	j;

	i = 0;
	while (par[i].str != 0)
	{
		j = 0;
		while (par[i].str[j])
			write(1, &par[i].str[j++], 1);
		write(1, "\n", 1);
		put_nbr(par[i].size);
		write(1, "\n", 1);
		j = 0;
		while (par[i].copy[j])
			write(1, &par[i].copy[j++], 1);
		write(1, "\n", 1);
		i++;
	}
}
