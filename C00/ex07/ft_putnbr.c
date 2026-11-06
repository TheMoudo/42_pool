/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzbair <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 14:07:05 by mzbair            #+#    #+#             */
/*   Updated: 2026/07/16 16:17:10 by mzbair           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_rkm(int nb, int *n)
{
	*n = 0;
	while (nb != 0)
	{
		nb = nb / 10;
		(*n)++;
	}
}

void	ft_putnbr(int nb)
{
	int		n;
	int		i;
	char	tab[12];

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb == 0)
	{
		write(1, "0", 1);
		return ;
	}
	if (nb < 0)
	{
		nb = nb * -1;
		write(1, "-", 1);
	}
	ft_rkm(nb, &n);
	i = n;
	while (i > 0)
	{
		tab[--i] = (nb % 10) + '0';
		nb = nb / 10;
	}
	write(1, tab, n);
}

/*int main(){
	ft_putnbr(-2147483648);
}*/
