/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairou <mkhairou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:35:13 by mkhairou          #+#    #+#             */
/*   Updated: 2022/12/27 15:04:33 by mkhairou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	fill_all(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (i < (vars->hei - 1))
	{
		j = 0;
		while (j < (vars->wid - 1))
		{
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img.rd.ptr, 40
				* j, 40 * i);
			j++;
		}
		i++;
	}
}

void	image_init(t_vars *vars)
{
	vars->t_time = 0;
	vars->tmp = NULL;
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, vars->wid * 40, 40 * vars->hei,
			"Hello world!");
	vars->img.wall.ptr = mlx_xpm_file_to_image(vars->mlx, "./bon/t_b/wall.xpm",
			&vars->img.wall.w, &vars->img.wall.h);
	vars->img.trap.ptr = mlx_xpm_file_to_image(vars->mlx,
			"./bon/t_b/mob1.xpm", &vars->img.trap.w, &vars->img.trap.h);
	vars->img.rd.ptr = mlx_xpm_file_to_image(vars->mlx,
			"./bon/t_b/road.xpm", &vars->img.rd.w, &vars->img.rd.h);
	vars->img.avatar.ptr = mlx_xpm_file_to_image(vars->mlx, "./bon/t_b/a1.xpm",
			&vars->img.avatar.w, &vars->img.avatar.h);
	vars->img.co.ptr = mlx_xpm_file_to_image(vars->mlx,
			"./bon/t_b/ca.xpm", &vars->img.co.w, &vars->img.co.h);
	vars->img.door.ptr = mlx_xpm_file_to_image(vars->mlx,
			"./bon/t_b/exit.xpm", &vars->img.co.w, &vars->img.co.h);
	if (!vars->mlx || !vars->win || !vars->img.wall.ptr
		|| !vars->img.trap.ptr || !vars->img.rd.ptr
		|| !vars->img.avatar.ptr || !vars->img.co.ptr || !vars->img.door.ptr)
	{
		ft_printf(RED "EROOR IMG\n" DEF);
		exit(0);
	}
}

void	do_stuf(int i, int j, t_vars *vars, char a)
{
	if (a == 'E')
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.door.ptr, 40
			* j, 40 * i);
		vars->pos_player.exitx = j;
		vars->pos_player.exity = i;
	}
	if (a == 'P')
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.avatar.ptr, 40
			* j, 40 * i);
		vars->pos_player.y = i;
		vars->pos_player.x = j;
	}
}

void	map_fill(t_vars *vars, int first)
{
	int	i;
	int	j;

	i = -1;
	while (vars->map[++i])
	{
		j = -1;
		while (vars->map[i][++j])
		{
			if (vars->map[i][j] == '1')
				mlx_put_image_to_window(vars->mlx, vars->win,
					vars->img.wall.ptr, 40 * j, 40 * i);
			if (vars->map[i][j] == '0')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->img.rd.ptr,
					40 * j, 40 * i);
			if (vars->map[i][j] == 'E')
				do_stuf(i, j, vars, 'E');
			if (vars->map[i][j] == 'X')
				creat_tlist(i, j, vars, first);
			if (vars->map[i][j] == 'C')
				creat_clist(i, j, vars, first);
			if (vars->map[i][j] == 'P')
				do_stuf(i, j, vars, 'P');
		}
	}
}
