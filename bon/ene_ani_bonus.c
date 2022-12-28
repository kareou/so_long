/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ene_ani_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairou <mkhairou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:44:04 by mkhairou          #+#    #+#             */
/*   Updated: 2022/12/28 09:45:31 by mkhairou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	d_b(t_vars *vars, int i, int j, t_list *tmp)
{
	if ((vars->map[i + 1][j] && vars->map[i + 1][j] == '0')
	|| (vars->map[i + 1][j] && vars->map[i + 1][j] == 'P'))
	{
		vars->map[i][j] = '0';
		tmp->y += 1;
	}
	if (vars->map[i + 1][j] && vars->map[i + 1][j] == 'P')
		lose(vars);
}

void	d_u(t_vars *vars, int i, int j, t_list *tmp)
{
	if ((vars->map[i - 1][j] && vars->map[i - 1][j] == '0')
	|| (vars->map[i - 1][j] && vars->map[i - 1][j] == 'P'))
	{
		vars->map[i][j] = '0';
		tmp->y -= 1;
	}
	if (vars->map[i - 1][j] && vars->map[i - 1][j] == 'P')
		lose(vars);
}

void	d_r(t_vars *vars, int i, int j, t_list *tmp)
{
	if ((vars->map[i][j + 1] == '0' && vars->map[i][j + 1] == '0')
	|| (vars->map[i][j + 1] == '0' && vars->map[i][j + 1] == 'P'))
	{
		vars->map[i][j] = '0';
		tmp->x += 1;
	}
	if (vars->map[i + 1][j] && vars->map[i + 1][j] == 'P')
		lose(vars);
}

void	d_l(t_vars *vars, int i, int j, t_list *tmp)
{
	if ((vars->map[i][j - 1] && vars->map[i][j - 1] == '0')
	|| (vars->map[i][j - 1] && vars->map[i][j - 1] == 'p'))
	{
		vars->map[i][j] = '0';
		tmp->x -= 1;
	}
	if (vars->map[i - 1][j] && vars->map[i - 1][j] == 'P')
		lose(vars);
}
