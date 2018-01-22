/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 12:07:38 by alerandy          #+#    #+#             */
/*   Updated: 2018/01/22 13:26:54 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frac.h"
#include "mlx.h"

static void	ft_input(t_data *data)
{
	data->frame.img = ft_intset(data->frame.img, WHITE,
			data->win_w * data->win_h);
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

static void	set_data(t_data *data, int ac, char **av)
{
	if (ac == 4)
	{
		data->win_w = ft_atoi(av[2]) < 100 ? 1100 : ft_atoi(av[2]);
		data->win_h = ft_atoi(av[3]) < 100 ? data->win_w : ft_atoi(av[3]);
	}
	else
	{
		data->win_w = 1100;
		data->win_h = 1100;
	}
	data->posx = data->win_w / 3;
	data->posy = data->win_h / 2;
	data->zoom = 2;
	data->depth = 1;
	data->rotx = 45;
	data->roty = 0;
	data->rotz = -60;
}

int			main(int ac, char **av)
{
	t_data	*data;

	if (ac != 2)
		usage(1);
	if (!(data = ft_memalloc(sizeof(t_data))))
		return (-1);
	set_data(data, ac, av);
	if (!(data->mlx = mlx_init()))
		return (-1);
	if (!(data->win = mlx_new_window(data->mlx, data->win_w, data->win_h, WIN)))
		return (-1);
	data->frame.pimg = mlx_new_image(data->mlx, data->win_w, data->win_h);
	data->frame.img = mlx_get_data_addr(data->frame.pimg, &(data->frame.bpp),
			&(data->frame.s_l), &(data->frame.ndia));
	data->frame.img = ft_intset(data->frame.img, BLUR,
			data->win_w * data->win_h);
	ft_input(data);
	return (1);
}
