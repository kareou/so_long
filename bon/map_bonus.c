/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairou <mkhairou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 10:02:00 by mkhairou          #+#    #+#             */
/*   Updated: 2022/12/28 08:59:02 by mkhairou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_wall(t_vars *vars)
{
	int	i;
	int	j;

	i = -1;
	while (++i < vars->hei)
	{
		j = -1;
		if (i == 0 || i == (vars->hei - 1))
		{
			while (vars->map[i][++j] && ++j < vars->wid)
			{
				if (vars->map[i][j] != '1')
				{
					ft_printf(RED "Invalid walls:"DEF "\n");
					exit(0);
				}
			}
		}
		if (vars->map[i][0] != '1' || vars->map[i][vars->wid - 1] != '1')
		{
			ft_printf(RED "Invalid walls:"DEF "\n");
			exit(0);
		}
	}
	return (0);
}

void	free_m(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < (vars->hei - 1))
	{
		free(vars->tmp_map[i]);
		i++;
	}
}

int	map_creat(t_vars *vars, char *a)
{
	int	fd;

	vars->hei = 0;
	ext_check(a);
	vars->tmp_map = ft_calloc(1024, 1024);
	vars->map = ft_calloc(1024, 1024);
	if (clone(vars, a) == 0)
		exit(0);
	fd = open(a, O_RDONLY);
	vars->hei = 0;
	free_m(vars);
	vars->map[vars->hei] = get_next_line(fd);
	while (vars->map[vars->hei])
	{
		vars->hei++;
		vars->map[vars->hei] = get_next_line(fd);
	}
	map_check(vars);
	check_wall(vars);
	image_init(vars);
	close(fd);
	return (1);
}
