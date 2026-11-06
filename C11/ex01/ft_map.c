/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzbair <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 10:10:30 by mzbair            #+#    #+#             */
/*   Updated: 2026/08/05 10:29:17 by mzbair           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	*map;
	int	i;

	i = 0;
	map = malloc(sizeof(int) * length);
	if (!map)
		return (NULL);
	while (i < length)
	{
		map[i] = f(tab[i]);
		i++;
	}
	return (map);
}
