/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairou <mkhairou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 10:15:49 by mkhairou          #+#    #+#             */
/*   Updated: 2022/12/27 11:55:44 by mkhairou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	valid(t_vars *vars)
{
	if (vars->exit > 1 || vars->exit == 0)
	{
		ft_printf("map should have 1 exit\n");
		mlx_destroy_window(vars->mlx, vars->win);
	}
	if (vars->pla > 1 || vars->pla == 0)
	{
		ft_printf("map sould have 1 playe\n");
		mlx_destroy_window(vars->mlx, vars->win);
	}
	if (vars->col == 0)
	{
		ft_printf("map should have atleast 1 collectabel\n");
		mlx_destroy_window(vars->mlx, vars->win);
	}
}

void	check_rek(t_vars *vars)
{
	int	i;

	i = 1;
	if (ft_strlen(vars->map[vars->hei - 1]) != vars->wid)
	{
		ft_printf(RED "MAP IS NOT RECK\n" DEF);
		exit(0);
	}
	while (vars->map[i] && i < vars->hei - 1)
	{
		if (ft_strlen(vars->map[i]) - 1 != vars->wid)
		{
			ft_printf(RED "MAP IS NOT RECK\n" DEF);
			exit(0);
		}
		i++;
	}
}

void	check_ele(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j])
		{
			if (ft_strchr("01PECX\n", vars->map[i][j]) == NULL)
			{
				ft_printf(RED "INCORERCT ELEMENTS\n" DEF);
				exit(0);
			}
			else
				j++;
		}
		i++;
	}
}

void	map_check(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	check_rek(vars);
	check_ele(vars);
	while (vars->map[i] && i < vars->hei - 1)
	{
		j = 0;
		while (vars->map[i][j])
		{
			if (vars->map[i][j] == 'E')
				vars->exit++;
			if (vars->map[i][j] == 'P')
				vars->pla++;
			if (vars->map[i][j] == 'C')
				vars->col++;
			j++;
		}
		i++;
	}
	ft_printf(YEL "AMOUNT OF COINS YOU NEED " RED "%d" DEF "\n", vars->col);
	valid(vars);
}
