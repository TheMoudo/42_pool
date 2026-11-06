/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzbair <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 08:49:39 by mzbair            #+#    #+#             */
/*   Updated: 2026/07/21 17:49:51 by mzbair           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	def;
	int	i;

	i = 0;
	def = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
		{
			def = (unsigned char)s1[i] - (unsigned char)s2[i];
			return (def);
		}
		i++;
	}
	if (s1[i])
		def = (unsigned char)s1[i];
	if (s2[i])
		def = -(unsigned char)s2[i];
	return (def);
}
