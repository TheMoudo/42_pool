/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzbair <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 14:54:42 by mzbair            #+#    #+#             */
/*   Updated: 2026/07/25 18:11:03 by mzbair           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	int	pow;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	pow = nb * ft_recursive_power(nb, power - 1);
	return (pow);
}
