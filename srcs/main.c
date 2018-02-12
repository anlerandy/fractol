/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 12:07:38 by alerandy          #+#    #+#             */
/*   Updated: 2018/02/12 12:45:36 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frac.h"
#include "mlx.h"
#include "list.h"

static void	ft_input(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->win, data->frame.pimg, 0, 0);
	mlx_hook(data->win, 2, 0, ft_exit, (void *)data);
	mlx_hook(data->win, 17, 0, ft_close, 0);
	mlx_hook(data->win, 6, (1L << 6), &ft_controler, (void *)data);
	mlx_mouse_hook(data->win, ft_zoom, (void *)data);
	mlx_loop(data->mlx);
}

static void	set_data(t_data *data, int i)
{
	data->win_w = 1100;
	data->win_h = 1100;
	if (!(data->name = ft_strjoin(WIN, g_frac[i].name)))
		data->name = "Untitled - Unexpected Error";
	data->zoom = 1;
	data->min_x = -2;
	data->min_y = -2;
	data->max_x = 2;
	data->max_y = 2;
	data->iter = 25;
	data->flag3 = 0;
	data->pow = 2;
	data->center.x = 0;
	data->center.y = 0;
	data->back = BG;
}

static int	set_image(t_data *data)
{
	if (!(data->win = mlx_new_window(data->mlx, data->win_w, data->win_h,
					data->name)))
		return (-1);
	data->frame.pimg = mlx_new_image(data->mlx, data->win_w, data->win_h);
	data->frame.img = mlx_get_data_addr(data->frame.pimg, &(data->frame.bpp),
			&(data->frame.s_l), &(data->frame.ndia));
	data->frame.img = ft_intset(data->frame.img, 0,
			data->win_w * data->win_h);
	return (0);
}

int			second(char *av)
{
	int		i;
	int		a;
	t_data	*data;

	a = 0;
	i = 0;
	if (!(data = ft_memalloc(sizeof(t_data))))
		return (-1);
	while (g_frac2[i].frac && !a)
	{
		if ((a = ft_strint(g_frac2[i].frac, av)) == 1)
			data->func = g_frac2[i].func;
		else
			i++;
	}
	g_frac2[i].name == NULL ? free(data) : i;
	g_frac2[i].name == NULL ? g_frac2[i].func() : i;
	if (!(data->mlx = mlx_init()))
		return (-1);
	set_data(data, i);
	set_image(data);
	data->func(data);
	ft_input(data);
	return (1);
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
		if ((a = ft_strint(g_frac[i].frac, av[1])) == 1)
			data->func = g_frac[i].func;
		else
			i++;
	}
	g_frac[i].name == NULL ? free(data) : i;
	g_frac[i].name == NULL ? g_frac[i].func() : i;
	if (!(data->mlx = mlx_init()))
		return (-1);
	set_data(data, i);
	set_image(data);
	data->func(data);
	ft_input(data);
	return (1);
}
