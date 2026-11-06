/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzbair <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 15:53:16 by mzbair            #+#    #+#             */
/*   Updated: 2026/07/19 15:35:41 by mzbair           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	is_apper_case(char *c)
{
	if (*c >= 'A' && *c <= 'Z')
		*c += 32;
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	if (str[0] >= 'a' && str[0] <= 'z')
		str[0] -= 32;
	i = 1;
	while (str[i])
	{
		if (str[i - 1] >= '0' && str[i - 1] <= '9')
			is_apper_case(&str[i]);
		else if (str[i - 1] >= 'A' && str[i - 1] <= 'Z')
			is_apper_case(&str[i]);
		else if (str[i - 1] >= 'a' && str[i - 1] <= 'z')
			is_apper_case(&str[i]);
		else if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		i++;
	}
	return (str);
}
