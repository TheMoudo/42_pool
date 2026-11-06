/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzbair <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 20:43:11 by mzbair            #+#    #+#             */
/*   Updated: 2026/07/30 12:38:17 by mzbair           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	valide(char *str, int len)
{
	int	i;
	int	j;

	if (len == 0 || len == 1)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-'
			|| (str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
			return (0);
		j = i +1;
		while (j < len)
		{
			if (str[i] == str[j])
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

void	convert(char *str, char *base, int *nb, int *pow)
{
	int	position;
	int	len;

	len = str_len(base);
	position = check(str[0], base);
	if (position != -1)
	{
		convert(&str[1], base, nb, pow);
		*nb = (*nb) + (position * (*pow));
		(*pow) *= len;
	}
}

int	ft_atoi_base(char *str, char *base)
{
	int	base_len;
	int	i;
	int	signe;
	int	nb;
	int	pow;

	base_len = str_len(base);
	if (!valide(base, base_len))
		return (0);
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	signe = 1;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signe *= -1;
		i++;
	}
	nb = 0;
	pow = 1;
	convert(&str[i], base, &nb, &pow);
	return (nb * signe);
}
