/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzbair <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 11:01:50 by mzbair            #+#    #+#             */
/*   Updated: 2026/08/05 11:18:08 by mzbair           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	tazayod;
	int	tana9oss;

	i = 0;
	tazayod = 1;
	tana9oss = 1;
	while (i < (length - 1))
	{
		if (f(tab[i], tab[i +1]) > 0)
			tazayod = 0;
		if (f(tab[i], tab[i +1]) < 0)
			tana9oss = 0;
		i++;
	}
	if (tana9oss || tazayod)
		return (1);
	return (0);
}
