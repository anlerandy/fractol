/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 13:30:33 by alerandy          #+#    #+#             */
/*   Updated: 2018/01/31 16:59:43 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include "frac.h"

t_frac	g_frac[] =
{
	{&julia, "julia", "Ensemble de Julia"},
	{&mandel, "mandelbrot", "Ensemble de Mandelbrot"},
	{&dragon, "dragon", "Courbe du dragon Heighway"},
	{&help, "-h", NULL},
	{&help, "-aide", NULL},
	{&list, "-liste", NULL},
	{&help, "-help", NULL},
	{&list, "-list", NULL},
	{&list, "-l", NULL},
	{&none, NULL, NULL},
};

#endif
