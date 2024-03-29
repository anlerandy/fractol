/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 14:39:48 by alerandy          #+#    #+#             */
/*   Updated: 2018/02/12 09:49:07 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frac.h"

int		list(void)
{
	char	*line;

	line = NULL;
	ft_putendl("\nListe des fractales :\t - Julia");
	ft_putendl("\t\t\t - Advanced Julia");
	ft_putendl("\t\t\t - Mandelbrot");
	ft_putendl("\t\t\t - Celtic Mandelbrot");
	ft_putendl("\t\t\t - Burning ship\n\n");
	ft_putstr("NB : FractaCraft est insensible à la casse (julia = JULIA = Ju");
	ft_putstr("LiA)\n     Les Fractales peuvent être abréviées (p. ex. mandel");
	ft_putendl(" pour mandelbrot ; burn pour Burning ship).\n\n");
	ft_putstr("Tapez le nom de la fractale que vous voulez lancer (exit pour ");
	ft_putstr("quitter) : ");
	get_next_line(0, &line);
	second(line);
	return (0);
}

int		help(void)
{
	char	*line;

	line = NULL;
	help2();
	ft_putendl("\t\t\t - 'h' Affiche l'aide dans le terminal.\n\n");
	ft_putstr("Tapez le nom de la fractale que vous voulez lancer (exit pour ");
	ft_putstr("quitter) : ");
	get_next_line(0, &line);
	second(line);
	return (0);
}

int		help2(void)
{
	ft_putstr("\nCommandes de FractaCraft :");
	ft_putendl(" '+' & '-' Augmenter ou Diminuer les itérations.");
	ft_putendl("\t\t\t - '0' Remettre les itérations par défauts (25).");
	ft_putendl("\t\t\t - 'r' Revenir aux paramètres par défauts.");
	ft_putendl("\t\t\t - 'c' Changer de palette de couleur.");
	ft_putendl("\t\t\t - 'b' Changer de type de fond (Transparent ou Opaque).");
	ft_putendl("\t\t\t - 'Roulette souris' Contrôler le zoom de la fractale.");
	ft_putendl("\t\t\t - 'Flèches clavier' Contrôler la caméra.");
	ft_putstr("\t\t\t - 'Mouvement de souris' Varier le dessin de la fratale ");
	ft_putstr("(Julia uniquement).\n\t\t\t - 'p' Activer ou Désactiver les mo");
	ft_putendl("uvements de la souris (Julia uniquement).");
	ft_putstr("\t\t\t - '2' Centrer sur le deuxième bâteau (Burning ship uniq");
	ft_putendl("uement).");
	ft_putstr("\t\t\t - 'z' & 'x' Diminuer ou augmenter la puissance du Mande");
	ft_putstr("lbrot & de Julia (Multibrot & Juliasse).\n\t\t\t - 's");
	ft_putendl("hift' Retour au Mandelbrot (Multibrot & Juliasse uniquement).");
	return (0);
}

void	usage(int err)
{
	if (err == 1)
	{
		ft_putendl("");
		ft_putendl("Arguments incorrects :\t- ./fractol (-l) (-h) [fractale]");
		ft_putendl("\t\t\t-l ou -list : Liste des fractales disponibles.");
		ft_putendl("\t\t\t-h ou -help : Liste des commandes disponibles.\n");
		ft_putstr("NB : Il ne peut y avoir qu'un seul argument en paramètres.");
		ft_putendl("\n");
	}
	if (err == 2)
	{
		ft_putendl("\nFractale inconnue.");
		list();
		return ;
	}
	exit(0);
}

int		none(void)
{
	usage(2);
	return (1);
}
