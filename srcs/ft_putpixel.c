/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpixel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 15:44:50 by alerandy          #+#    #+#             */
/*   Updated: 2018/01/24 16:02:49 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "frac.h"
#include <math.h>

void		ft_img_pixel_put(t_data **data, int x, int y, int c)
{
	int	i;
	int	color;

	color = WHITE;
	(c == -1 ? (color = BLUE) : color);
	(c == 0 ? (color = WHITE) : color);
	(c == 1 ? (color = YELLOW) : color);
	if (x < 0 || x >= (*data)->win_w || y < 0 || y >= (*data)->win_h)
		return ;
	i = (x * 4) + (y * (*data)->frame.s_l);
	*(int*)((*data)->frame.img + i) = color;
}
