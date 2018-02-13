/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmpl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 12:00:32 by alerandy          #+#    #+#             */
/*   Updated: 2018/02/13 13:18:00 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frac.h"
#include <math.h>

double		ft_dev_cmpl(t_coor z)
{
	double	nb;

	nb = z.x + z.y;
	return (nb);
}

t_coor		ft_cmpl_mult(t_coor a, t_coor b)
{
	t_coor	tmp;

	tmp.x = a.x + b.x - a.y * b.y;
	tmp.y = 2 * (a.y + b.y);
	return (tmp);
}

t_coor		ft_addsub_cmpl(t_coor a, t_coor b, char c)
{
	t_coor	tmp;

	if (c && c == '-')
	{
		tmp.x = a.x - b.x;
		tmp.y = a.y - b.y;
	}
	else
	{
		tmp.x = a.x + b.x;
		tmp.y = a.y + b.y;
	}
	return (tmp);
}

t_coor		ft_pow_cmp(t_coor a, int pow)
{
	t_coor	tmp;
	int		i;

	i = 0;
	tmp = a;
	while (i < pow)
	{
		tmp = ft_cmpl_mult(tmp, a);
		i++;
	}
	return (tmp);
}

t_coor		ft_divi_cmpl(t_coor a, t_coor b)
{
	t_coor tmp;

	tmp.x = a.x / b.x;
	tmp.y = a.x / b.y + a.y / b.x + a.y / b.y;
	return (tmp);
}
