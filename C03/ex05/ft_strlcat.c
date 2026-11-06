/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzbair <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 12:22:42 by mzbair            #+#    #+#             */
/*   Updated: 2026/07/21 17:06:33 by mzbair           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	k;
	unsigned int	i;
	unsigned int	dest_size;
	unsigned int	src_size;

	dest_size = 0;
	while (dest[dest_size] && dest_size < size)
		dest_size++;
	src_size = 0;
	while (src[src_size])
		src_size++;
	if (dest_size == size)
		return (src_size + dest_size);
	k = 0;
	i = dest_size;
	while (src[k] && i < (size - 1))
	{
		dest[i] = src[k];
		k++;
		i++;
	}
	dest[i] = '\0';
	return (src_size + dest_size);
}
