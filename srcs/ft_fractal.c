/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 09:25:10 by alerandy          #+#    #+#             */
/*   Updated: 2018/01/24 21:53:47 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frac.h"
#include "mlx.h"

int		ft_recurence(double xo, double yo, int *color)
{
	int			i;
	double		x;
	double		y;
	double		xt;

	i = 0;
	x = 0;
	y = 0;
	*color = RED;
	while (i < 50)
	{
		xt = x * x - y * y + xo;
		y = 2 * (x * y) + yo;
		x = xt;
		if ((x * x) + (y * y) > 4)
			return (0);
		i++;
		*color += i * 10;
	}
	return (1);
}


int		julia()
{
	return (1);
}

int		mandel(t_data *data)
{
	int			i;
	int			color;
	t_coor		p;
	t_coor		po;
	t_coor		delta;

	delta.x = (data->max_x - data->min_x) * data->zoom;
	delta.y = (data->max_y - data->min_y) * data->zoom;
	p.y = 0;
	po.x = 0;
	po.y = 0;
	color = RED;
	while (p.y < data->win_h)
	{
		po.y = (p.y / data->win_h) * delta.y + (data->min_y * data->zoom);
		p.x = 0;
		while(p.x < data->win_w)
		{
			po.x = (p.x / data->win_w) * delta.x + (data->min_x * data->zoom);
			i = (p.x * 4) + (p.y * data->frame.s_l);
			if (ft_recurence(po.x, po.y, &color) == 0)
				*(int*)(data->frame.img + i) = color;
			p.x++;
		}
		p.y++;
	}
	return (1);
}

int		none()
{
	usage(2);
	return (1);
}
