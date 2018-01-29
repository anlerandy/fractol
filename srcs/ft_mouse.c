/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 13:04:08 by alerandy          #+#    #+#             */
/*   Updated: 2018/01/29 21:41:47 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "frac.h"

int			ft_controler(int x, int y, void *param)
{
	t_data	*data;
	t_coor	p;
	t_coor	delta;

	data = (t_data *)param;
	delta.x = (data->max_x - data->min_x) * data->zoom;
	delta.y = (data->max_y - data->min_y) * data->zoom;
	p.y = ((y - (data->win_h / 2)) * (delta.y / 2)) / (data->win_h / 2);
	p.x = ((x - (data->win_w / 2)) * (delta.x / 2)) / (data->win_w / 2);
	if (!data->flag)
	{
		data->mouse_x = x - (data->win_w / 2);
		data->mouse_y = y - (data->win_h / 2);
	}
/*	ft_putstr("Coordonnées x : ");
	ft_putnbr(data->mouse_x);
	ft_putstr(" (");
	ft_putnbr(p.x);
	ft_putendl(")");
	ft_putstr("Coordonnées y : ");
	ft_putnbr(data->mouse_y * -1);
	ft_putstr(" (");
	ft_putnbr(p.y);
	ft_putendl(")"); */
	data->frame.img = ft_intset(data->frame.img, BG, data->win_w * data->win_h);
	data->func(data);
	mlx_put_image_to_window(data->mlx, data->win, data->frame.pimg, 0, 0);
	return (0);
}
