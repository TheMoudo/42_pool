/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzbair <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 19:13:56 by mzbair            #+#    #+#             */
/*   Updated: 2026/07/17 12:33:46 by mzbair           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	replace;

	i = 0;
	while (i < size)
	{
		size--;
		replace = tab[i];
		tab[i] = tab[size];
		tab[size] = replace;
		i++;
	}
}
