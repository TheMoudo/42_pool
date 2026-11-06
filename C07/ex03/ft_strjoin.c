/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzbair <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 09:05:36 by mzbair            #+#    #+#             */
/*   Updated: 2026/07/29 19:30:19 by mzbair           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_len(char **strs, int size)
{
	int	len;
	int	i;
	int	j;

	len = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			len++;
			j++;
		}
		i++;
	}
	return (len);
}

void	implement_concat(char *concat, char **strs, char *sep, int size)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			concat[k++] = strs[i][j++];
		if (i < size -1)
		{
			j = 0;
			while (sep[j])
				concat[k++] = sep[j++];
		}
		i++;
	}
	concat[k] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*concat;
	int		strs_len;
	int		sep_len;

	if (size == 0)
	{
		concat = malloc(sizeof(char));
		concat[0] = '\0';
		return (concat);
	}
	strs_len = ft_len(strs, size);
	sep_len = 0;
	while (sep[sep_len])
		sep_len++;
	concat = malloc(sizeof(char) * (strs_len + sep_len * (size - 1) + 1));
	if (! concat)
		return (NULL);
	implement_concat(concat, strs, sep, size);
	return (concat);
}
