/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 09:25:10 by alerandy          #+#    #+#             */
/*   Updated: 2018/02/09 10:46:06 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frac.h"
#include "mlx.h"
#include <pthread.h>

void	*pth_julia(void *arg)
{
	t_env		*data;
	t_coor		p;
	t_coor		c;
	t_coor		z;
	int			color;

	data = (t_env *)arg;
	p.y = -1 + ((data->win_h / THREADS) * (data->part - 1));
	c.x = data->mouse_x / (data->win_w / 2);
	c.y = data->mouse_y / (data->win_h / 2);
	while (++p.y < data->win_h / THREADS * data->part)
	{
		z.y = (p.y / data->win_h) * data->delta.y + (data->min_y * data->zoom);
		p.x = -1;
		while (++p.x < data->win_w)
		{
			z.x = (p.x / data->win_w) * data->delta.x + (data->min_x *
			data->zoom);
			z.z = (p.x * 4) + (p.y * data->frame->s_l);
			if (ft_recurence3(z, c, &color, data) == 0)
				*(int*)(data->frame->img + (int)z.z) = color;
		}
	}
	pthread_exit(NULL);
}

int		julia(t_data *data)
{
	pthread_t	pth[THREADS];
	int			i;
	t_env		env[THREADS];

	i = 0;
	while (i < THREADS)
	{
		env[i] = set_env(data);
		env[i].part = i + 1;
		pthread_create(&pth[i], NULL, pth_julia, &(env[i]));
		++i;
	}
	i = 0;
	while (i < THREADS)
		pthread_join(pth[i++], NULL);
	return (1);
}

void	*pth_mandel(void *arg)
{
	int			color;
	t_coor		p;
	t_coor		c;
	t_coor		z;
	t_env		*data;

	data = (t_env *)arg;
	p.y = -1 + ((data->win_h / THREADS) * (data->part - 1));
	z.x = 0;
	z.y = 0;
	while (++p.y < data->win_h / THREADS * data->part)
	{
		c.y = (p.y / data->win_h) * data->delta.y + (data->min_y * data->zoom);
		p.x = -1;
		while (++p.x < data->win_w)
		{
			c.x = (p.x / data->win_w) * data->delta.x + (data->min_x *
			data->zoom);
			data->delta.z = (p.x * 4) + (p.y * data->frame->s_l);
			if (ft_recurence3(z, c, &color, data) == 0)
				*(int*)(data->frame->img + (int)data->delta.z) = color;
		}
	}
	pthread_exit(NULL);
}

int		mandel(t_data *data)
{
	pthread_t	pth[THREADS];
	int			i;
	t_env		env[THREADS];

	i = 0;
	while (i < THREADS)
	{
		env[i] = set_env(data);
		env[i].part = i + 1;
		pthread_create(&pth[i], NULL, pth_mandel, &(env[i]));
		++i;
	}
	i = 0;
	while (i < THREADS)
		pthread_join(pth[i++], NULL);
	return (1);
}
