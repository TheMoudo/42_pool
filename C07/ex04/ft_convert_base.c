/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzbair <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 08:47:28 by mzbair            #+#    #+#             */
/*   Updated: 2026/08/01 21:02:58 by mzbair           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		str_len(char *str);
char	*ft_itoa_base(int number, char *base, int base_len);

int	valide(char *base)
{
	int	len;
	int	i;
	int	j;

	len = str_len(base);
	if (len == 0 || len == 1)
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-'
			|| (base[i] >= 9 && base[i] <= 13) || base[i] == ' ')
			return (0);
		j = i + 1;
		while (j < len)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

void	convert_to_ten(char *nbr, char *base, int *pow, int *nb)
{
	int	position;
	int	len;

	len = str_len(base);
	position = check(nbr[0], base);
	if (position != -1)
	{
		convert_to_ten(&nbr[1], base, pow, nb);
		*nb = *nb + (position * (*pow));
		*pow *= len;
	}
}

int	ft_atoi_base(char *nbr, char *base)
{
	int	nb;
	int	pow;
	int	i;
	int	signe;

	i = 0;
	signe = 1;
	while ((nbr[i] >= 9 && nbr[i] <= 13) || nbr[i] == ' ')
		i++;
	while (nbr[i] == '-' || nbr[i] == '+')
	{
		if (nbr[i] == '-')
			signe *= -1;
		i++;
	}
	nb = 0;
	pow = 1;
	convert_to_ten(&nbr[i], base, &pow, &nb);
	return (nb * signe);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		nb_base_ten;
	char	*nb_final_base;

	if (!valide(base_from) || !valide(base_to))
		return (NULL);
	nb_base_ten = ft_atoi_base(nbr, base_from);
	nb_final_base = ft_itoa_base(nb_base_ten, base_to, str_len(base_to));
	return (nb_final_base);
}
