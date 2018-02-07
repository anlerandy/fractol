/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 09:25:10 by alerandy          #+#    #+#             */
/*   Updated: 2018/02/07 18:52:50 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frac.h"
#include "palette.h"
#include "mlx.h"
#include <math.h>

int		ft_recurence(t_coor z, t_coor c, int *color, t_data *data)
{
	int			i;
	double		xt;

	i = 0;
	*color = RED;
	while (i < data->iter)
	{
		xt = z.x * z.x - z.y * z.y + c.x;
		z.y = 2 * (z.x * z.y) + c.y;
		z.x = xt;
		if ((z.x * z.x) + (z.y * z.y) > 4)
			return (0);
		i++;
		*color = g_pal[i % 25];
	}
	return (1);
}

int		ft_recurence2(t_coor z, t_coor c, int *color, t_data *data)
{
	int			i;
	double		xt;

	i = 0;
	*color = RED;
	while (i < data->iter)
	{
		xt = z.x * z.x - z.y * z.y + c.x;
		z.y = fabs(2 * (z.x * z.y) + c.y);
		z.x = fabs(xt);
		if ((z.x * z.x) + (z.y * z.y) > 4)
			return (0);
		i++;
		*color = g_pal[i % 25];
	}
	return (1);
}

int		julia(t_data *data)
{
	int			color;
	t_coor		p;
	t_coor		c;
	t_coor		z;
	t_coor		delta;

	delta.x = (data->max_x - data->min_x) * data->zoom;
	delta.y = (data->max_y - data->min_y) * data->zoom;
	p.y = -1;
	c.x = data->mouse_x / (data->win_w / 2);
	c.y = data->mouse_y / (data->win_h / 2);
	while (++p.y < data->win_h)
	{
		z.y = (p.y / data->win_h) * delta.y + (data->min_y * data->zoom);
		p.x = -1;
		while (++p.x < data->win_w)
		{
			z.x = (p.x / data->win_w) * delta.x + (data->min_x * data->zoom);
			z.z = (p.x * 4) + (p.y * data->frame.s_l);
			if (ft_recurence(z, c, &color, data) == 0)
				*(int*)(data->frame.img + (int)z.z) = color;
		}
	}
	return (1);
}

int		mandel(t_data *data)
{
	int			color;
	t_coor		p;
	t_coor		c;
	t_coor		z;
	t_coor		delta;

	delta.x = (data->max_x - data->min_x) * data->zoom;
	delta.y = (data->max_y - data->min_y) * data->zoom;
	p.y = -1;
	z.x = 0;
	z.y = 0;
	while (++p.y < data->win_h)
	{
		c.y = (p.y / data->win_h) * delta.y + (data->min_y * data->zoom);
		p.x = -1;
		while (++p.x < data->win_w)
		{
			c.x = (p.x / data->win_w) * delta.x + (data->min_x * data->zoom);
			delta.z = (p.x * 4) + (p.y * data->frame.s_l);
			if (ft_recurence(z, c, &color, data) == 0)
				*(int*)(data->frame.img + (int)delta.z) = color;
		}
	}
	return (1);
}

int		burn(t_data *data)
{
	int			color;
	t_coor		p;
	t_coor		c;
	t_coor		z;
	t_coor		delta;

	data->flag2 = 1;
	delta.x = (data->max_x - data->min_x) * data->zoom;
	delta.y = (data->max_y - data->min_y) * data->zoom;
	p.y = -1;
	z.x = 0;
	z.y = 0;
	while (++p.y < data->win_h)
	{
		c.y = (p.y / data->win_h) * delta.y + (data->min_y * data->zoom);
		p.x = -1;
		while (++p.x < data->win_w)
		{
			c.x = (p.x / data->win_w) * delta.x + (data->min_x * data->zoom);
			delta.z = (p.x * 4) + (p.y * data->frame.s_l);
			if (ft_recurence2(z, c, &color, data) == 0)
				*(int*)(data->frame.img + (int)delta.z) = color;
		}
	}
	return (1);
}
