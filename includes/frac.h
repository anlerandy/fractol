/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 11:49:31 by alerandy          #+#    #+#             */
/*   Updated: 2018/02/07 19:46:06 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAC_H
# define FRAC_H

# include "get_next_line.h"

# define WIN "FractaCraft 0.03.3  /  "
# define BLUR 0x99000000
# define BG 0
# define BLUE 0x000000ff
# define WHITE 0x00ffffff
# define YELLOW 0x00ffff00
# define RED 0x00ff0000
# define ZMAX 5000

typedef struct	s_coor
{
	double		x;
	double		y;
	float		z;
}				t_coor;

typedef struct	s_frame
{
	void		*pimg;
	char		*img;
	int			bpp;
	int			s_l;
	int			ndia;
}				t_frame;

typedef struct	s_data
{
	void		*mlx;
	void		*win;
	char		*name;
	int			win_h;
	int			win_w;
	double		zoom;
	double		min_x;
	double		max_x;
	double		min_y;
	double		max_y;
	t_coor		center;
	double		mouse_x;
	double		mouse_y;
	double		mousef;
	int			flag;
	int			flag2;
	int			iter;
	t_frame		frame;
	int			(*func)();
}				t_data;

typedef struct	s_frac
{
	int			(*func)();
	char		*frac;
	char		*name;
}				t_frac;

void			ft_tabdel(void *tab, int len);
void			ft_memclr(void *ap, size_t len);
int				ft_exit(int key, void *param);
char			*ft_intset(char *tab, int i, int size);
int				ft_zoom(int key, int x, int y, void *param);
void			usage(int err);
int				ft_close(void);
int				ft_strint(const char *haystack, const char *needle);
int				ft_controler(int x, int y, void *param);

int				julia();
int				mandel();
int				burn();
int				list();
int				help();
int				help2();
int				none();

#endif
