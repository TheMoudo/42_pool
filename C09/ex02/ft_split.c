/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzbair <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 11:07:08 by mzbair            #+#    #+#             */
/*   Updated: 2026/08/04 12:31:16 by mzbair           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_sep(char c, char *charset)
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

int	count_words(char *str, char *charset)
{
	int	i;
	int	words;

	if (!str[0])
		return (0);
	words = 0;
	i = 1;
	if (!is_sep(str[0], charset))
		words++;
	while (str[i])
	{
		if (is_sep(str[i - 1], charset) && !is_sep(str[i], charset))
			words++;
		i++;
	}
	return (words);
}

int	count_chars(char *str, char *charset)
{
	int	i;

	i = 0;
	while (str[i] && !is_sep(str[i], charset))
		i++;
	return (i);
}

void	impliment(char *str, char *element, int chars)
{
	int	i;

	i = 0;
	while (i < chars)
	{
		element[i] = str[i];
		i++;
	}
	element[chars] = '\0';
}

char	**ft_split(char *str, char *charset)
{
	char	**out;
	int		chars;
	int		words;
	int		element;
	int		i;

	words = count_words(str, charset);
	out = malloc(sizeof(char *) * (words + 1));
	if (!out)
		return (NULL);
	out[words--] = NULL;
	element = 0;
	i = 0;
	while (element <= words)
	{
		while (str[i] && is_sep(str[i], charset))
			i++;
		chars = count_chars(&str[i], charset);
		out[element] = malloc(sizeof(char) * (chars + 1));
		if (!out[element])
			return (NULL);
		impliment(&str[i], out[element], chars);
		i = i + chars + 0 * element++;
	}
	return (out);
}
