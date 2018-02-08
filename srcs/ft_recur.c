
#include "frac.h"
#include "palette.h"
#include <math.h>

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
	}
	return (1);
}

int		ft_recurence2(t_coor z, t_coor c, int *color, t_data *data)
{
	int			i;
	double		xt;

	i = 0;
	*color = RED;
	while (i < data->iter)
	{
		xt = z.x * z.x - z.y * z.y + c.x;
		z.y = fabs(2 * (z.x * z.y) + c.y);
		z.x = fabs(xt);
		if ((z.x * z.x) + (z.y * z.y) > 4)
			return (0);
		i++;
		*color = g_pal[i % 25];
	}
	return (1);
}
