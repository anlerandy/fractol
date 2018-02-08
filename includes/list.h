/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 13:30:33 by alerandy          #+#    #+#             */
/*   Updated: 2018/02/07 12:25:13 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include "frac.h"

t_frac	g_frac[] =
{
	{&julia, "julia", "Ensemble de Julia"},
	{&mandel, "mandelbrot", "Ensemble de Mandelbrot"},
	{&mandel, "mandel", "Ensemble de Mandelbrot"},
	{&burn, "burning", "The Burning Ship"},
	{&burn, "ship", "The Burning Ship"},
	{&burn, "burn", "The Burning Ship"},
	{&burn, "burning ship", "The Burning Ship"},
	{&help, "-h", NULL},
	{&help, "-aide", NULL},
	{&list, "-liste", NULL},
	{&help, "-help", NULL},
	{&list, "-list", NULL},
	{&list, "-l", NULL},
	{&ft_close, "exit", NULL},
	{&none, NULL, NULL},
};

#endif
