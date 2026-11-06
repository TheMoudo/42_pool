/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzbair <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 09:31:36 by mzbair            #+#    #+#             */
/*   Updated: 2026/08/01 15:20:40 by mzbair           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	alocation_size(long nb, int len)
{
	int	i;

	i = 1;
	while (nb >= len)
	{
		nb /= len;
		i++;
	}
	return (i);
}	

char	*ft_itoa_base(int number, char *base, int base_len)
{
	char	*out;
	int		i;
	long	nb;

	nb = number;
	i = 0;
	if (nb < 0)
	{
		i++;
		nb = -nb;
	}
	i += alocation_size(nb, base_len);
	out = malloc(sizeof(char) * (i + 1));
	if (!out)
		return (NULL);
	out[i--] = '\0';
	while (i >= 0)
	{
		out[i--] = (base[nb % base_len]);
		nb = nb / base_len;
	}
	if (number < 0)
		out[0] = '-';
	return (out);
}
