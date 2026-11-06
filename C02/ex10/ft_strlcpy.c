/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzbair <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 20:33:38 by mzbair            #+#    #+#             */
/*   Updated: 2026/07/19 10:31:11 by mzbair           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	size_src(char *src)
{
	unsigned int	i;

	i = 0;
	while (src[i])
	{
		i++;
	}
	return (i);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	if (size == 0)
		return (size_src(src));
	i = 0;
	while (i < (size - 1) && src[i])
	{
		dest [i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (size_src(src));
}
