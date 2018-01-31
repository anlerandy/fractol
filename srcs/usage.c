/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 14:39:48 by alerandy          #+#    #+#             */
/*   Updated: 2018/01/31 17:03:57 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frac.h"

int		list(void)
{
	ft_putendl("Liste des fractales :\t - Julia");
	ft_putendl("\t\t\t - Mandelbrot");
	ft_putendl("\t\t\t - Pythagore");
	ft_putendl("\t\t\t - Dragon");
	exit(0);
}

int		help(void)
{
	ft_putstr("Commandes de FractaCraft :");
	ft_putendl(" '+' & '-' Augmenter ou Diminuer les itérations.");
	ft_putendl("\t\t\t - 'r' Revenir aux paramètres par défauts.");
	ft_putendl("\t\t\t - 'Roulette souris' Controler le zoom de la fractale.");
	ft_putendl("\t\t\t - 'Flêches clavier' Controler la caméra.");
	ft_putstr("\t\t\t - 'Mouvement de souris' Varié le dessin de la fratale ");
	ft_putstr("(Julia uniquement).\n\t\t\t - 'p' Activer ou Désactiver les mo");
	ft_putendl("uvements de la souris (Julia uniquement).");
	exit(0);
}

void	usage(int err)
{
	if (err == 1)
	{
		ft_putendl("Arguments incorrectes :\t- ./fractol (-l) (-h) [fractale]");
		ft_putendl("\t\t\t-l ou -list : Liste des fractales disponibles.");
		ft_putendl("\t\t\t-h ou -help : Liste des commandes disponibles.");
	}
	if (err == 2)
	{
		ft_putendl("Fractale inconnue.\n");
		list();
	}
	if (err == 3)
		ft_putendl("File is not a supported file : text file or .fdf only.\n");
	if (err == 4)
	{
		ft_putstr("File is not valid : ");
		ft_putendl("must contain a constant size along the lines.\n");
	}
	if (err == ZMAX)
		ft_putendl("\nFile contain a z coordonate too high.\nMax : 5'000.\n");
	exit(0);
}
