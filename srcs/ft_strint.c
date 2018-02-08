/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 09:23:03 by alerandy          #+#    #+#             */
/*   Updated: 2018/02/07 19:35:01 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strint(const char *haystack, char *needle)
{
	size_t		i;

	i = -1;
	while (needle[++i])
		needle[i] = ft_tolower(needle[i]);
	i = 0;
	if (!needle[i])
		return (1);
	if (!haystack[i])
		return (0);
	while (haystack[i] == needle[i] && haystack[i] && needle[i])
	{
		i++;
		if (!needle[i])
			return (1);
	}
	return (0);
}
