/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 13:53:12 by alerandy          #+#    #+#             */
/*   Updated: 2018/02/12 09:49:43 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frac.h"
#include "mlx.h"

char			*ft_intset(char *tab, int i, int size)
{
	int x;

	x = 0;
	while (x < size)
	{
		((int*)tab)[x] = i;
		x++;
	}
	return (tab);
}

static int		ft_transl(int key, t_data *data)
{
	key == 6 && data->pow > 2 ? (data->pow -= 1) : key;
	key == 7 && data->pow < 5 ? (data->pow += 1) : key;
	key == 257 || key == 258 ? (data->pow = 2) : key;
	if (key == 11)
		data->back = (data->back == (int)BLUR ? BG : BLUR);
	if (key == 8)
		data->col < 4 ? data->col++ : (data->col = 0);
	key == 4 ? help2() : key;
	if (key == 69 || key == 24)
		data->iter += 1;
	if ((key == 78 || key == 27) && data->iter > 0)
		data->iter -= 1;
	if (key == 123)
		data->center.x -= .1 * data->zoom;
	if (key == 124)
		data->center.x += .1 * data->zoom;
	if (key == 126)
		data->center.y -= .1 * data->zoom;
	if (key == 125)
		data->center.y += .1 * data->zoom;
	data->min_x = -2 + data->center.x / data->zoom;
	data->min_y = -2 + data->center.y / data->zoom;
	data->max_x = 2 + data->center.x / data->zoom;
	data->max_y = 2 + data->center.y / data->zoom;
	return (0);
}

int				ft_zoom(int key, int x, int y, void *param)
{
	t_data		*data;

	data = (t_data *)param;
	x = y;
	if (key == 5)
		data->zoom *= 1.1;
	if (key == 4)
		data->zoom = data->zoom / 1.1;
	data->min_x = -2 + data->center.x / data->zoom;
	data->min_y = -2 + data->center.y / data->zoom;
	data->max_x = 2 + data->center.x / data->zoom;
	data->max_y = 2 + data->center.y / data->zoom;
	data->frame.img = ft_intset(data->frame.img, data->back, data->win_w *
			data->win_h);
	data->func(data);
	mlx_put_image_to_window(data->mlx, data->win, data->frame.pimg, 0, 0);
	return (0);
}

int				ft_close(void)
{
	ft_putendl("FractaCraft a fermé correctement.");
	exit(0);
	return (0);
}

int				ft_exit(int key, void *param)
{
	t_data *data;

	data = (t_data *)param;
	key == 53 ? ft_close() : key;
	if (key == 35)
		data->flag == 0 ? data->flag++ : data->flag--;
	if (key == 15)
	{
		data->zoom = 1;
		data->center.x = 0;
		data->center.y = 0;
	}
	if ((key == 19 || key == 84) && data->flag2)
	{
		data->zoom = 0.022;
		data->center.x = -1.75;
		data->center.y = -.0376;
	}
	ft_transl(key, data);
	key == 82 ? (data->iter = 25) : key;
	data->frame.img = ft_intset(data->frame.img, data->back, data->win_w *
			data->win_h);
	data->func(data);
	mlx_put_image_to_window(data->mlx, data->win, data->frame.pimg, 0, 0);
	return (0);
}
