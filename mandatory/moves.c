/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairou <mkhairou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 22:19:44 by mkhairou          #+#    #+#             */
/*   Updated: 2022/12/27 11:22:32 by mkhairou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_check(t_vars *vars, char move)
{
	if (move == '1')
		return (0);
	else if (move == 'C')
	{
		vars->col -= 1;
		ft_printf(YEL "NUMBER OF MOBS YOU NEED TO KILL" RED "%d" DEF "\n",
			vars->col);
		win_check(vars);
		return (1);
	}
	else if (move == 'E' && vars->col == 0)
	{
		vars->move++;
		ft_printf(CYAN "Movement count: " GREEN "%d" DEF "\n", vars->move);
		win(vars);
		return (1);
	}
	else if (move == 'E')
		return (1);
	else
		return (1);
}

void	move_r(t_vars *vars)
{
	if (move_check(vars, vars->map[vars->pos_player.y][vars->pos_player.x + 1]))
	{
		vars->move++;
		ft_printf(CYAN "Movement count: " GREEN "%d" DEF "\n", vars->move);
		vars->map[vars->pos_player.y][vars->pos_player.x] = '0';
		vars->map[vars->pos_player.exity][vars->pos_player.exitx] = 'E';
		if (vars->map[vars->pos_player.y][vars->pos_player.x + 1] == 'C')
		{
			vars->map[vars->pos_player.y][vars->pos_player.x + 1] = '0';
			map_fill(vars);
		}
		vars->img.avatar.ptr = mlx_xpm_file_to_image(vars->mlx,
				"./mandatory/textur_mandatory/avatar.xpm", &vars->img.avatar.w,
				&vars->img.avatar.h);
		vars->map[vars->pos_player.y][vars->pos_player.x + 1] = 'P';
		map_fill(vars);
	}
}

void	move_l(t_vars *vars)
{
	if (move_check(vars, vars->map[vars->pos_player.y][vars->pos_player.x - 1]))
	{
		vars->move++;
		ft_printf(CYAN "Movement count: " GREEN "%d" DEF "\n", vars->move);
		vars->map[vars->pos_player.y][vars->pos_player.x] = '0';
		vars->map[vars->pos_player.exity][vars->pos_player.exitx] = 'E';
		if (vars->map[vars->pos_player.y][vars->pos_player.x - 1] == 'C')
		{
			vars->map[vars->pos_player.y][vars->pos_player.x - 1] = '0';
			map_fill(vars);
		}
		vars->img.avatar.ptr = mlx_xpm_file_to_image(vars->mlx,
				"./mandatory/textur_mandatory/avatar_r.xpm",
				&vars->img.avatar.w, &vars->img.avatar.h);
		vars->map[vars->pos_player.y][vars->pos_player.x - 1] = 'P';
		map_fill(vars);
	}
}

void	move_u(t_vars *vars)
{
	if (move_check(vars, vars->map[vars->pos_player.y - 1][vars->pos_player.x]))
	{
		vars->move++;
		ft_printf(CYAN "Movement count: " GREEN "%d" DEF "\n", vars->move);
		vars->map[vars->pos_player.y][vars->pos_player.x] = '0';
		vars->map[vars->pos_player.exity][vars->pos_player.exitx] = 'E';
		if (vars->map[vars->pos_player.y - 1][vars->pos_player.x] == 'C')
		{
			vars->map[vars->pos_player.y - 1][vars->pos_player.x] = '0';
			map_fill(vars);
		}
		vars->img.avatar.ptr = mlx_xpm_file_to_image(vars->mlx,
				"./mandatory/textur_mandatory/avatar_up.xpm",
				&vars->img.avatar.w, &vars->img.avatar.h);
		vars->map[vars->pos_player.y - 1][vars->pos_player.x] = 'P';
		map_fill(vars);
	}
}

void	move_d(t_vars *vars)
{
	if (move_check(vars, vars->map[vars->pos_player.y + 1][vars->pos_player.x]))
	{
		vars->move++;
		ft_printf(CYAN "Movement count: " GREEN "%d" DEF "\n", vars->move);
		vars->map[vars->pos_player.y][vars->pos_player.x] = '0';
		vars->map[vars->pos_player.exity][vars->pos_player.exitx] = 'E';
		if (vars->map[vars->pos_player.y + 1][vars->pos_player.x] == 'C')
		{
			vars->map[vars->pos_player.y + 1][vars->pos_player.x] = '0';
			map_fill(vars);
		}
		vars->img.avatar.ptr = mlx_xpm_file_to_image(vars->mlx,
				"./mandatory/textur_mandatory/avatar_down.xpm",
				&vars->img.avatar.w, &vars->img.avatar.h);
		vars->map[vars->pos_player.y + 1][vars->pos_player.x] = 'P';
		map_fill(vars);
	}
}
