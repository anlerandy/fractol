/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 11:49:31 by alerandy          #+#    #+#             */
/*   Updated: 2018/01/24 20:54:00 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAC_H
# define FRAC_H

# include "get_next_line.h"

# define WIN "FractaCraft 0.01  /  "
# define BLUR 0x99000000
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
	void		*win2;
	char		*name;
	int			win_h;
	int			win_w;
	double		zoom;
	double		depth;
	double		min_x;
	double		max_x;
	double		min_y;
	double		max_y;
	double		posx;
	double		posy;
	double		rotx;
	double		roty;
	double		rotz;
	int			flag;
	t_frame		frame;
	int			(*func)();
}				t_data;

typedef struct	s_frac
{
	int			(*func)();
	char		*frac;
}				t_frac;

void			ft_tabdel(void *tab, int len);
void			ft_memclr(void *ap, size_t len);
int				ft_exit(int key, void *param);
char			*ft_intset(char *tab, int i, int size);
int				ft_zoom(int key, int x, int y, void *param);
void			usage(int err);
int				ft_close(void);
int				ft_strint(const char *haystack, const char *needle);

int				julia();
int				mandel();
int				none();

#endif
