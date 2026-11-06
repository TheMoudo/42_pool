/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzbair <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 10:10:17 by mzbair            #+#    #+#             */
/*   Updated: 2026/07/21 17:50:53 by mzbair           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	int				def;
	unsigned int	i;

	i = 0;
	def = 0;
	while (s1[i] && s2[i] && i < n)
	{
		if (s1[i] != s2[i])
		{
			def = (unsigned char)s1[i] - (unsigned char)s2[i];
			return (def);
		}
		i++;
	}
	if (s1[i] && i < n)
		def = (unsigned char)s1[i];
	if (s2[i] && i < n)
		def = -(unsigned char)s2[i];
	return (def);
}
