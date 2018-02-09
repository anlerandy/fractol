/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recur.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 10:45:07 by alerandy          #+#    #+#             */
/*   Updated: 2018/02/09 12:54:11 by alerandy         ###   ########.fr       */
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
		xt = z.x * z.x - z.y * z.y + c.x;
		data->flag3 ? (xt = fabs(z.x * z.x - z.y * z.y) + c.x) : data->flag3;
		z.y = 2 * (z.x * z.y) + c.y;
		z.x = xt;
		if ((z.x * z.x) + (z.y * z.y) > 4)
			return (0);
		i++;
		*color = g_pal[data->col][i % 50];
	}
	return (1);
}

int		ft_recurence2(t_coor z, t_coor c, int *color, t_env *data)
{
	int			i;
	double		xt;

	i = 0;
	*color = g_pal[data->col][0];
	while (i < data->iter)
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
