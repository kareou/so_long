/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairou <mkhairou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 13:35:54 by mkhairou          #+#    #+#             */
/*   Updated: 2022/12/27 11:19:36 by mkhairou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	win_check(t_vars *vars)
{
	if (vars->col == 0)
	{
		vars->map[vars->pos_player.exity][vars->pos_player.exitx] = '0';
		vars->img.door.ptr = mlx_xpm_file_to_image(vars->mlx,
				"./mandatory/textur_mandatory/open.xpm", &vars->img.door.w,
				&vars->img.door.h);
		map_fill(vars);
	}
}

int	win(t_vars *vars)
{
	mlx_clear_window(vars->mlx, vars->win);
	mlx_destroy_window(vars->mlx, vars->win);
	ft_printf(BLACK "oooo    ooo  .ooooo.  oooo  oooo       "
		PURPLE "oooo oooo    ooo  .ooooooo.    ooo..oo.   " DEF "\n");
	ft_printf(BLACK " `88.  .8'  d88' `88b `888  `888        "
		PURPLE "`88. `88.  .8'     d888b    `888P''Y88b  " DEF "\n");
	ft_printf(BLACK "  `88..8'   888   888  888   888         "
		PURPLE "`88..]88..8'      88888     888   888  " DEF "\n");
	ft_printf(BLACK "   `888'    888   888  888   888          "
		PURPLE "`888'`888'       88888     888   888  " DEF "\n");
	ft_printf(BLACK "    .8'     `Y8bod8P'  `V88V''V8P'         "
		PURPLE "`8'  `8'     `Y8boood8P' o888o o888o " DEF "\n");
	ft_printf(BLACK ".o..P' \n");
	ft_printf(BLACK "`Y8P' \n");
	free(vars);
	exit(0);
	return (0);
}
