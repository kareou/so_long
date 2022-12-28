/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_list_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairou <mkhairou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 13:09:26 by mkhairou          #+#    #+#             */
/*   Updated: 2022/12/27 14:22:56 by mkhairou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	creat_clist(int i, int j, t_vars *vars, int first)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.rd.ptr, 40
		* j, 40 * i);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.co.ptr, 40 * j,
		40 * i);
	if (first)
		ft_lstadd_front(&vars->clst, ft_lstnew("C", i, j));
}

void	creat_tlist(int i, int j, t_vars *vars, int first)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.rd.ptr, 40
		* j, 40 * i);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.trap.ptr, 40
		* j, 40 * i);
	if (first)
		ft_lstadd_front(&vars->tmp, ft_lstnew("X", i, j));
}
