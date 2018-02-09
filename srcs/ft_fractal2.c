
#include "frac.h"
#include "mlx.h"
#include <pthread.h>

void	*pth_burn(void *arg)
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
			if (ft_recurence2(z, c, &color, data) == 0)
				*(int*)(data->frame->img + (int)data->delta.z) = color;
		}
	}
	pthread_exit(NULL);
}

int		burn(t_data *data)
{
	pthread_t	pth[THREADS];
	int			i;
	t_env		env[THREADS];

	i = 0;

	data->flag2 = 1;
	while (i < THREADS)
	{
		env[i] = set_env(data);
		env[i].part = i + 1;
		pthread_create(&pth[i], NULL, pth_burn, &(env[i]));
		++i;
	}
	i = 0;
	while (i < THREADS)
		pthread_join(pth[i++], NULL);
	return (1);
}
