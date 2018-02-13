/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 11:49:31 by alerandy          #+#    #+#             */
/*   Updated: 2018/02/13 12:58:14 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAC_H
# define FRAC_H

# include "get_next_line.h"

# define WIN "FractaCraft 0.05  /  "
# define BLUR 0xF0000000
# define BG 0x00000000
# define BLUE 0x000000ff
# define WHITE 0x00ffffff
# define YELLOW 0x00ffff00
# define RED 0x00ff0000
# define THREADS 32

typedef struct	s_coor
{
	double		x;
	double		y;
	double		z;
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
	int			flag;
	int			flag2;
	int			flag3;
	int			iter;
	t_frame		frame;
	int			part;
	int			col;
	double		pow;
	int			back;
	int			(*func)();
}				t_data;

typedef struct	s_env
{
	int			win_h;
	int			win_w;
	double		zoom;
	int			part;
	double		mouse_x;
	double		mouse_y;
	t_coor		delta;
	double		min_y;
	double		min_x;
	t_frame		*frame;
	int			iter;
	int			col;
	double		pow;
	int			flag3;
}				t_env;

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

t_coor			ft_pow_cmp(t_coor a, int pow);
t_coor		ft_addsub_cmpl(t_coor a, t_coor b, char c);
t_coor			ft_cmpl_mult(t_coor a, t_coor b);
double			ft_dev_cmpl(t_coor z);
t_coor			ft_divi_cmpl(t_coor a, t_coor b);

int				second(char *av);
t_env			set_env(t_data *data);
int				ft_recurence2(t_coor z, t_coor c, int *color, t_env *data);
int				ft_recurence3(t_coor z, t_coor c, int *color, t_env *data);

int				julia();
int				mandel();
int				burn();
int				celt();
int				stati();
int				advanced();
int				list();
int				help();
int				help2();
int				none();

#endif
