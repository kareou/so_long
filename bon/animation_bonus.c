/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairou <mkhairou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 10:20:04 by mkhairou          #+#    #+#             */
/*   Updated: 2022/12/28 09:40:12 by mkhairou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	animation_c(t_vars *vars)
{
	if (vars->t_time % 100 == 0)
	{
		vars->img.avatar.ptr = mlx_xpm_file_to_image(vars->mlx,
				"./bon/t_b/a1.xpm", &vars->img.avatar.w, &vars->img.avatar.h);
	}
	if (vars->t_time % 200 == 0)
	{
		vars->img.avatar.ptr = mlx_xpm_file_to_image(vars->mlx,
				"./bon/t_b/a2.xpm", &vars->img.avatar.w, &vars->img.avatar.h);
	}
	if (vars->t_time % 300 == 0)
	{
		vars->img.avatar.ptr = mlx_xpm_file_to_image(vars->mlx,
				"./bon/t_b/a3.xpm", &vars->img.avatar.w, &vars->img.avatar.h);
	}
	if (vars->t_time % 400 == 0)
	{
		vars->img.avatar.ptr = mlx_xpm_file_to_image(vars->mlx,
				"./bon/t_b/a4.xpm", &vars->img.avatar.w, &vars->img.avatar.h);
	}
	fill_all(vars);
	map_fill(vars, 0);
	put_text(vars);
}

int	test(t_vars *vars)
{
	if (vars->t_time % 2200 == 0)
		animation_t(vars);
	if (vars->t_time % 2200 == 0)
		animation_c(vars);
	vars->t_time++;
	return (1);
}
