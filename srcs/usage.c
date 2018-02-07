/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 14:39:48 by alerandy          #+#    #+#             */
/*   Updated: 2018/02/07 19:37:52 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frac.h"

int		list(void)
{
	ft_putendl("Liste des fractales :\t - Julia");
	ft_putendl("\t\t\t - Mandelbrot");
	ft_putendl("\t\t\t - Burning ship (N'oubliez pas les guillemets)\n\n");
	ft_putstr("NB : FractaCraft est insensible à la casse (julia = JULIA = Ju");
	ft_putstr("LiA)\n     Les Fractales peuvent être abréviés (p. ex. mandel ");
	ft_putendl("pour mandelbrot ; burn pour Burning ship).");
	exit(0);
}

int		help(void)
{
	ft_putstr("\nCommandes de FractaCraft :");
	ft_putendl(" '+' & '-' Augmenter ou Diminuer les itérations.");
	ft_putendl("\t\t\t - '0' Remettre les itérations par défauts (25).");
	ft_putendl("\t\t\t - 'r' Revenir aux paramètres par défauts.");
	ft_putendl("\t\t\t - 'Roulette souris' Controler le zoom de la fractale.");
	ft_putendl("\t\t\t - 'Flêches clavier' Controler la caméra.");
	ft_putstr("\t\t\t - 'Mouvement de souris' Varié le dessin de la fratale ");
	ft_putstr("(Julia uniquement).\n\t\t\t - 'p' Activer ou Désactiver les mo");
	ft_putendl("uvements de la souris (Julia uniquement).");
	ft_putstr("\t\t\t - '2' Centrer sur le deuxième bâteau (Burning ship uniq");
	ft_putendl("uement).");
	ft_putendl("\t\t\t - 'h' Affiche l'aide dans le terminale.");
	exit(0);
}

int		help2(void)
{
	ft_putstr("\nCommandes de FractaCraft :");
	ft_putendl(" '+' & '-' Augmenter ou Diminuer les itérations.");
	ft_putendl("\t\t\t - '0' Remettre les itérations par défauts (25).");
	ft_putendl("\t\t\t - 'r' Revenir aux paramètres par défauts.");
	ft_putendl("\t\t\t - 'Roulette souris' Controler le zoom de la fractale.");
	ft_putendl("\t\t\t - 'Flêches clavier' Controler la caméra.");
	ft_putstr("\t\t\t - 'Mouvement de souris' Varié le dessin de la fratale ");
	ft_putstr("(Julia uniquement).\n\t\t\t - 'p' Activer ou Désactiver les mo");
	ft_putendl("uvements de la souris (Julia uniquement).");
	ft_putstr("\t\t\t - '2' Centrer sur le deuxième bâteau (Burning ship uniq");
	ft_putendl("uement).");
	ft_putendl("\t\t\t - 'h' Affiche l'aide dans le terminale.");
	return (0);
}

void	usage(int err)
{
	if (err == 1)
	{
		ft_putendl("");
		ft_putendl("Arguments incorrectes :\t- ./fractol (-l) (-h) [fractale]");
		ft_putendl("\t\t\t-l ou -list : Liste des fractales disponibles.");
		ft_putendl("\t\t\t-h ou -help : Liste des commandes disponibles.");
		ft_putstr("NB : Il ne peux y avoir qu'un seul argument en paramètres");
	}
	if (err == 2)
	{
		ft_putendl("\nFractale inconnue.\n");
		list();
	}
	exit(0);
}

int		none(void)
{
	usage(2);
	return (1);
}