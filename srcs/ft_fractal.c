/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 09:25:10 by alerandy          #+#    #+#             */
/*   Updated: 2018/01/29 21:30:35 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frac.h"
#include "palette.h"
#include "mlx.h"

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
/*		*color += ((i * 0x000a0a));*/
	}
	return (1);
}

int		julia(t_data *data)
{
	int			i;
	int			color;
	t_coor		p;
	t_coor		c;
	t_coor		z;
	t_coor		delta;

	delta.x = (data->max_x - data->min_x) * data->zoom;
	delta.y = (data->max_y - data->min_y) * data->zoom;
	p.y = 0;
	c.x = data->mouse_x / (data->win_w / 2);
	c.y = data->mouse_y / (data->win_h / 2);
	while (p.y < data->win_h)
	{
		z.y = (p.y / data->win_h) * delta.y + (data->min_y * data->zoom);
		p.x = 0;
		while (p.x < data->win_w)
		{
			z.x = (p.x / data->win_w) * delta.x + (data->min_x * data->zoom);
			i = (p.x * 4) + (p.y * data->frame.s_l);
			if (ft_recurence(z, c, &color, data) == 0)
				*(int*)(data->frame.img + i) = color;
			p.x++;
		}
		p.y++;
	}
	return (1);
}

int		mandel(t_data *data)
{
	int			i;
	int			color;
	t_coor		p;
	t_coor		c;
	t_coor		z;
	t_coor		delta;

	delta.x = (data->max_x - data->min_x) * data->zoom;
	delta.y = (data->max_y - data->min_y) * data->zoom;
	p.y = 0;
	z.x = 0;
	z.y = 0;
	while (p.y < data->win_h)
	{
		c.y = (p.y / data->win_h) * delta.y + (data->min_y * data->zoom);
		p.x = 0;
		while (p.x < data->win_w)
		{
			c.x = (p.x / data->win_w) * delta.x + (data->min_x * data->zoom);
			i = (p.x * 4) + (p.y * data->frame.s_l);
			if (ft_recurence(z, c, &color, data) == 0)
				*(int*)(data->frame.img + i) = color;
			p.x++;
		}
		p.y++;
	}
	return (1);
}

int		none(void)
{
	usage(2);
	return (1);
}
