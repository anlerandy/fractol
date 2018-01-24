/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 12:07:38 by alerandy          #+#    #+#             */
/*   Updated: 2018/01/24 21:52:18 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frac.h"
#include "mlx.h"
#include "list.h"

static void	ft_input(t_data *data)
{
	data->func(data);
	mlx_put_image_to_window(data->mlx, data->win, data->frame.pimg, 0, 0);
	mlx_hook(data->win, 2, 0, ft_exit, (void *)data);
	mlx_hook(data->win, 17, 0, ft_close, 0);
	mlx_mouse_hook(data->win, ft_zoom, (void *)data);
	mlx_loop(data->mlx);
}

char		*ft_intset(char *tab, int i, int size)
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

static void	set_data(t_data *data, char **av)
{
	data->win_w = 1100;
	data->win_h = 1100;
	data->name = ft_strjoin(WIN, av[1]);
	data->zoom = 1;
	data->depth = 1;
	data->rotx = 45;
	data->roty = 0;
	data->rotz = -60;
	data->posx = data->win_w / 2;
	data->posy = data->win_h / 2;
	data->min_x = -2;
	data->min_y = -2;
	data->max_x = 2;
	data->max_y = 2;
}

int			main(int ac, char **av)
{
	t_data	*data;
	int		i;
	int		a;

	a = 0;
	i = 0;
	ac != 2 ? usage(1) : ac;
	if (!(data = ft_memalloc(sizeof(t_data))))
		return (-1);
	while (g_frac[i].frac && !a)
	{
		if ((a = ft_strint(av[1], g_frac[i].frac)) == 1)
			data->func = g_frac[i].func;
		else
			i++;
	}
	g_frac[i].frac == NULL ? g_frac[i].func() : i;
	if (!(data->mlx = mlx_init()))
		return (-1);
	set_data(data, av);
	if (!(data->win = mlx_new_window(data->mlx, data->win_w, data->win_h,
					data->name)))
		return (-1);
	data->frame.pimg = mlx_new_image(data->mlx, data->win_w, data->win_h);
	data->frame.img = mlx_get_data_addr(data->frame.pimg, &(data->frame.bpp),
			&(data->frame.s_l), &(data->frame.ndia));
	data->frame.img = ft_intset(data->frame.img, WHITE,
			data->win_w * data->win_h);
	ft_input(data);
	return (1);
}
