/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzbair <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 16:37:30 by mzbair            #+#    #+#             */
/*   Updated: 2026/07/25 18:40:16 by mzbair           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	grid(char *result, int ligne, int column)
{
	int	value;
	int	succes;

	if (column == 5)
	{
		column = 1;
		if (!check_ligne())
			return (0);
		ligne++;
	}
	if (ligne == 5)
	{
		if (!check_all_colums())
			return (0);
		return (1);
	}
	value = 1;
	while (value <= 4)
	{
		(result + 5 * ligne)[column] = value++;
		succes = grid(result, input, ligne, column + 1);
		if (succes == 1)
			return (1);
	}
	return (0);
}
