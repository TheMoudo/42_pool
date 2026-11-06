/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzbair <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 19:22:38 by mzbair            #+#    #+#             */
/*   Updated: 2026/08/01 20:47:19 by mzbair           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	existe(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	count_word(char *str, char *charset)
{
	int	i;
	int	count;

	if (!str[0])
		return (0);
	i = 1;
	count = 0;
	if (!existe(str[0], charset))
		count++;
	while (str[i])
	{
		if (existe(str[i - 1], charset) && !existe(str[i], charset))
			count++;
		i++;
	}
	return (count);
}

int	count_chars(char *str, char *charset)
{
	int	i;

	i = 0;
	while (str[i] && !existe(str[i], charset))
		i++;
	return (i);
}

void	impliment(char *str, char *out, int chars)
{
	int	i;

	i = 0;
	while (i < chars)
	{
		out[i] = str[i];
		i++;
	}
	out[chars] = '\0';
}

char	**ft_split(char *str, char *charset)
{
	int		words;
	char	**out;
	int		i;
	int		chars;
	int		element;

	words = count_word(str, charset);
	out = malloc(sizeof(char *) * (words + 1));
	if (!out)
		return (NULL);
	out[words--] = NULL;
	i = 0;
	element = 0;
	while (element <= words)
	{
		while (str[i] && existe(str[i], charset))
			i++;
		chars = count_chars(&str[i], charset);
		out[element] = malloc(sizeof(char) * (chars +1));
		if (!out[element])
			return (NULL);
		impliment(&str[i], out[element], chars);
		i += chars + (0 * element++);
	}
	return (out);
}
