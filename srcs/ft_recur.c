/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recur.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 10:45:07 by alerandy          #+#    #+#             */
/*   Updated: 2018/02/14 22:59:45 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frac.h"
#include "palette.h"
#include <math.h>

t_env	set_env(t_data *data)
{
	t_env	env;

	env.frame = &(data->frame);
	env.win_h = data->win_h;
	env.win_w = data->win_w;
	env.delta.x = (data->max_x - data->min_x) * data->zoom;
	env.delta.y = (data->max_y - data->min_y) * data->zoom;
	env.min_x = data->min_x;
	env.min_y = data->min_y;
	env.zoom = data->zoom;
	env.mouse_x = data->mouse_x;
	env.mouse_y = data->mouse_y;
	env.iter = data->iter;
	env.col = data->col;
	env.flag3 = data->flag3;
	env.pow = data->pow;
	return (env);
}

int		ft_recurence3(t_coor z, t_coor c, int *color, t_env *data)
{
	int			i;
	double		xt;

	i = 0;
	*color = g_pal[data->col][0];
	while (i < data->iter)
	{
		!data->flag3 && data->pow > 2 ? (xt = pow(z.x * z.x + z.y * z.y,
					data->pow / 2) * cos(data->pow * atan2(z.y, z.x)) + c.x) :
								data->flag3;
		!data->flag3 && data->pow > 2 ? (z.y = pow(z.x * z.x + z.y * z.y,
					data->pow / 2) * sin(data->pow * atan2(z.y, z.x)) + c.y) :
								data->flag3;
		data->flag3 ? (xt = fabsl(z.x * z.x - z.y * z.y) + c.x) : data->flag3;
		data->flag3 ? (z.y = 2 * (z.x * z.y) + c.y) : data->flag3;
		!data->flag3 && data->pow < 3 ? xt = (z.x * z.x - z.y * z.y) + c.x : i;
		!data->flag3 && data->pow < 3 ? (z.y = 2 * (z.x * z.y) + c.y) : i;
		z.x = xt;
		if ((z.x * z.x) + (z.y * z.y) > 4)
			return (0);
		i++;
	}
	*color = g_pal[data->col][i % 50];
	return (1);
}

t_coor	magn(t_coor z, t_coor c)
{
	t_coor		tmp1;
	t_coor		tmp2;

	tmp1 = ft_cmpl_mult(z, z);
	c.x -= 1.;
	tmp1 = ft_addsub_cmpl(tmp1, c, '+');
	tmp2 = ft_addsub_cmpl(z, z, '+');
	c.x -= 1.;
	tmp2 = ft_addsub_cmpl(tmp2, c, '+');
	z = ft_divi_cmpl(tmp1, tmp2);
	z = ft_cmpl_mult(z, z);
	c.x += 2;
	return (z);
}

int		ft_recurence2(t_coor z, t_coor c, int *color, t_env *data)
{
	int			i;
	double		xt;

	i = 0;
	*color = g_pal[data->col][0];
	while (i < data->iter && data->flag3)
	{
		z = magn(z, c);
		if ((z.x * z.x) + (z.y * z.y) > 16)
			return (0);
		*color = g_pal[data->col][i % 50];
		i++;
	}
	while (i < data->iter && !data->flag3)
	{
		xt = z.x * z.x - z.y * z.y + c.x;
		z.y = fabsl(2 * (z.x * z.y) + c.y);
		z.x = fabsl(xt);
		if ((z.x * z.x) + (z.y * z.y) > 4)
			return (0);
		i++;
		*color = g_pal[data->col][i % 50];
	}
	return (1);
}
