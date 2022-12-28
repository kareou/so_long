/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairou <mkhairou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:35:13 by mkhairou          #+#    #+#             */
/*   Updated: 2022/12/27 11:26:27 by mkhairou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, vars->wid * 40, 40 * vars->hei,
			"Hello world!");
	vars->img.wall.ptr = mlx_xpm_file_to_image(vars->mlx,
			"./mandatory/textur_mandatory/wall.xpm", &vars->img.wall.w,
			&vars->img.wall.h);
	vars->img.rd.ptr = mlx_xpm_file_to_image(vars->mlx,
			"./mandatory/textur_mandatory/road.xpm", &vars->img.rd.w,
			&vars->img.rd.h);
	vars->img.avatar.ptr = mlx_xpm_file_to_image(vars->mlx,
			"./mandatory/textur_mandatory/avatar.xpm", &vars->img.avatar.w,
			&vars->img.avatar.h);
	vars->img.co.ptr = mlx_xpm_file_to_image(vars->mlx,
			"./mandatory/textur_mandatory/c1.xpm", &vars->img.co.w,
			&vars->img.co.h);
	vars->img.door.ptr = mlx_xpm_file_to_image(vars->mlx,
			"./mandatory/textur_mandatory/exit.xpm", &vars->img.co.w,
			&vars->img.co.h);
	if (!vars->mlx || !vars->win || !vars->img.wall.ptr || !vars->img.rd.ptr
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
	if (a == 'C')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.co.ptr, 40 * j,
			40 * i);
}

void	map_fill(t_vars *vars)
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
			if (vars->map[i][j] == 'C')
				do_stuf(i, j, vars, 'C');
			if (vars->map[i][j] == 'P')
				do_stuf(i, j, vars, 'P');
		}
	}
}
