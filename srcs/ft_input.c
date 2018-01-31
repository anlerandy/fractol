/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 13:53:12 by alerandy          #+#    #+#             */
/*   Updated: 2018/01/31 17:02:48 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frac.h"
#include "mlx.h"
#include <stdio.h>
#define MOUSEF 550

static int		ft_transl(int key, t_data *data)
{
	if (key == 69 || key == 24)
		data->iter += 1;
	if ((key == 78 || key == 27) && data->iter > 0)
		data->iter -= 1;
	if (key == 123)
	{
		data->max_x -= .1;
		data->min_x -= .1;
	}
	if (key == 124)
	{
		data->max_x += .1;
		data->min_x += .1;
	}
	if (key == 126)
	{
		data->max_y -= .1;
		data->min_y -= .1;
	}
	if (key == 125)
	{
		data->max_y += .1;
		data->min_y += .1;
	}
	return (0);
}

int				ft_zoom(int key, int x, int y, void *param)
{
	t_data *data;
	t_coor delta;

	x = 0;
	y = 0;
	data = (t_data *)param;
	if (key == 5)
		data->zoom *= 1.1;
	delta.x = (data->max_x - data->min_x) * data->zoom;
	delta.y = (data->max_y - data->min_y) * data->zoom;
	if (key == 4)
	{
		data->mousef *= .9;
		data->max_y += data->mouse_y / delta.y / data->mousef;
		data->min_y += data->mouse_y / delta.y / data->mousef;
		data->max_x += data->mouse_x / delta.x / data->mousef;
		data->min_x += data->mouse_x / delta.x / data->mousef;
		data->zoom = data->zoom / 1.1;
	}
	data->frame.img = ft_intset(data->frame.img, BG, data->win_w * data->win_h);
	data->func(data);
	mlx_put_image_to_window(data->mlx, data->win, data->frame.pimg, 0, 0);
	return (0);
}

int				ft_close(void)
{
	ft_putendl("FractaCraft corectly closed.");
	exit(0);
	return (0);
}

int				ft_exit(int key, void *param)
{
	t_data *data;

	data = (t_data *)param;
	if (key == 53)
		ft_close();
	if (key == 35)
		data->flag == 0 ? data->flag++ : data->flag--;
	if (key == 15)
	{
		data->zoom = 1;
		data->posx = data->win_w / 2;
		data->posy = data->win_h / 2;
		data->min_x = -2;
		data->min_y = -2;
		data->max_x = 2;
		data->max_y = 2;
	}
	ft_transl(key, data);
	key == 82 ? (data->flag = (data->flag + 1) % 2) : key;
	data->frame.img = ft_intset(data->frame.img, BG, data->win_w * data->win_h);
	data->func(data);
	mlx_put_image_to_window(data->mlx, data->win, data->frame.pimg, 0, 0);
	return (0);
}
