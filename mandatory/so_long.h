/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairou <mkhairou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:02:54 by mkhairou          #+#    #+#             */
/*   Updated: 2022/12/28 10:15:47 by mkhairou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../getline/get_next_line.h"
# include "../printf/ft_printf.h"
# include <fcntl.h>
# include <mlx.h>
# include <stdlib.h>

# define GREEN "\033[0;92m"
# define DEF "\033[0m"
# define RED "\033[0;31m"
# define YEL "\033[0;33m"
# define CYAN "\033[0;36m"
# define BLUE "\033[0;34m"
# define BLACK "\033[0;30m"
# define PURPLE "\033[0;35m"

typedef enum s_moves
{
	move_up = 126,
	move_right = 124,
	move_left = 123,
	move_back = 125,
	escape = 53,
	a = 0,
	d = 2,
	s = 1,
	w = 13,
}			t_moves;

typedef struct s_img
{
	void	*ptr;
	int		w;
	int		h;
}			t_img;

typedef struct s_image
{
	t_img	rd;
	t_img	co;
	t_img	avatar;
	t_img	door;
	t_img	wall;
}			t_image;

typedef struct s_pos
{
	int		x;
	int		y;
	int		tmp_x;
	int		tmp_y;
	int		exitx;
	int		exity;
}			t_pos;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	int		hei;
	int		wid;
	char	**map;
	char	**tmp_map;
	t_pos	pos_player;
	t_image	img;
	int		pla;
	int		exit;
	int		col;
	int		tmp_col;
	int		move;
}			t_vars;

void		map_fill(t_vars *vars);
int			map_creat(t_vars *vars, char *a);
void		move_r(t_vars *vars);
void		move_l(t_vars *vars);
void		move_u(t_vars *vars);
void		move_d(t_vars *vars);
void		map_check(t_vars *vars);
int			move_check(t_vars *vars, char move);
void		win_check(t_vars *vars);
int			win(t_vars *vars);
int			key_hook(int keyword, t_vars *vars);
char		ext_check(const char *a);
int			ft_printf(const char *a, ...);
void		*ft_calloc(size_t count, size_t size);
void		ft_bzero(void *s, size_t n);
void		fill_all(t_vars *vars);
void		map_valid(t_vars *vars);
int			close_win(t_vars *vars);
int			clone(t_vars *vars, char *a);
int			valid_path(t_vars *vars, int y, int x);
void		find_player(t_vars *vars);
void		image_init(t_vars *vars);
#endif