/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzbair <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 17:35:24 by mzbair            #+#    #+#             */
/*   Updated: 2026/07/23 11:11:29 by mzbair           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	put_char(char c)
{
	write(1, &c, 1);
}

int	valide(char *base, int lenth)
{
	int	i;
	int	j;

	if (lenth == 0 || lenth == 1)
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (j < lenth)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		len_base;
	char	tab[32];
	int		i;
	long	n;

	n = nbr;
	len_base = len(base);
	if (!valide(base, len_base))
		return ;
	i = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n == 0)
		tab[i++] = base[0];
	while (n > 0)
	{
		tab[i] = base[n % len_base];
		n = n / len_base;
		i++;
	}
	while (i > 0)
		put_char(tab[--i]);
}
