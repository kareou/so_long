/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coin_ani_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairou <mkhairou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 10:37:33 by mkhairou          #+#    #+#             */
/*   Updated: 2022/12/28 09:20:31 by mkhairou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	chos_dir(int i, t_list *tmp, t_vars *vars)
{
	if (i == 0)
		d_u(vars, tmp->y, tmp->x, tmp);
	if (i == 1)
		d_b(vars, tmp->y, tmp->x, tmp);
	if (i == 2)
		d_r(vars, tmp->y, tmp->x, tmp);
	if (i == 3)
		d_l(vars, tmp->y, tmp->x, tmp);
}

void	an(t_vars *vars, int i)
{
	if (i == 0)
	{
		vars->img.trap.ptr = mlx_xpm_file_to_image(vars->mlx,
				"./bon/t_b/mob1.xpm", &vars->img.trap.w,
				&vars->img.trap.h);
	}
	if (i == 1)
	{
		vars->img.trap.ptr = mlx_xpm_file_to_image(vars->mlx,
				"./bon/t_b/mob2.xpm", &vars->img.trap.w,
				&vars->img.trap.h);
	}
	if (i == 2)
	{
		vars->img.trap.ptr = mlx_xpm_file_to_image(vars->mlx,
				"./bon/t_b/mob3.xpm", &vars->img.trap.w,
				&vars->img.trap.h);
	}
}

void	animation_t(t_vars *vars)
{
	int		i;
	t_list	*e;

	e = vars->tmp;
	while (e != NULL)
	{
		i = rand() % 4;
		an(vars, i);
		chos_dir(i, e, vars);
		vars->map[e->y][e->x] = 'X';
		map_fill(vars, 0);
		put_text(vars);
		e = e->next;
	}
}
