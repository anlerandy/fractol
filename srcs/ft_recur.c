/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recur.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 10:45:07 by alerandy          #+#    #+#             */
/*   Updated: 2018/02/13 13:23:23 by alerandy         ###   ########.fr       */
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

double	ft_pow(double a, double b)
{
	double	i;
	double	nb;

	i = 0;
	nb = a;
	if (b == 0)
		return(1);
	while (i < b)
	{
		nb *= a;
		i += 1;
	}
	return (nb);
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
		data->flag3 ? (xt = fabs(z.x * z.x - z.y * z.y) + c.x) : data->flag3;
		data->flag3 ? (z.y = 2 * (z.x * z.y) + c.y) : data->flag3;
		!data->flag3 && data->pow < 3 ? xt = (z.x * z.x - z.y * z.y) + c.x : i;
		!data->flag3 && data->pow < 3 ? (z.y = 2 * (z.x * z.y) + c.y) : i;
		z.x = xt;
		*color = g_pal[data->col][i % 50];
		if ((z.x * z.x) + (z.y * z.y) > 4)
			return (0);
		i++;
	}
	return (1);
}

int		ft_recurence2(t_coor z, t_coor c, int *color, t_env *data)
{
	int			i;
	double		xt;
	t_coor		tmp1;
	t_coor		tmp2;

	i = 0;
	*color = g_pal[data->col][0];
	while (i < data->iter && data->flag3)
	{
		tmp1 = ft_pow_cmp(z, 2);
		c.x -= 1.;
		tmp1 = ft_addsub_cmpl(tmp1, c, '+');
		tmp2 = ft_addsub_cmpl(z, z, '+');
		c.x -= 1.;
		tmp2 = ft_addsub_cmpl(tmp2, c, '+');
		tmp1 = ft_pow_cmp(tmp1, 2);
		tmp2 = ft_pow_cmp(tmp2, 2);
		z = ft_divi_cmpl(tmp1, tmp2);
		c.x += 2;
		if ((z.x * z.x) + (z.y * z.y) > 4)
			return (0);
		i++;
		*color = g_pal[data->col][i % 50];
	}
	while (i < data->iter && !data->flag3)
	{
		xt = z.x * z.x - z.y * z.y + c.x;
		z.y = fabs(2 * (z.x * z.y) + c.y);
		z.x = fabs(xt);
		if ((z.x * z.x) + (z.y * z.y) > 4)
			return (0);
		i++;
		*color = g_pal[data->col][i % 50];
	}
	return (1);
}
