/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairou <mkhairou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 10:53:30 by mkhairou          #+#    #+#             */
/*   Updated: 2022/12/27 11:20:10 by mkhairou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_player(t_vars *vars)
{
	int	i;
	int	j;

	vars->tmp_col = 0;
	i = 0;
	while (vars->tmp_map[i])
	{
		j = 0;
		while (vars->tmp_map[i][j])
		{
			if (vars->tmp_map[i][j] == 'C' || vars->tmp_map[i][j] == 'E')
				vars->tmp_col++;
			if (vars->tmp_map[i][j] == 'P')
			{
				vars->pos_player.tmp_y = i;
				vars->pos_player.tmp_x = j;
			}
			j++;
		}
		i++;
	}
}

int	valid_path(t_vars *vars, int y, int x)
{
	if (vars->tmp_map[y][x] != '1')
	{
		if (vars->tmp_map[y][x] == 'C' || vars->tmp_map[y][x] == 'E')
			vars->tmp_col -= 1;
		vars->tmp_map[y][x] = '1';
		if (vars->tmp_map[y][x + 1] != '1')
			valid_path(vars, y, x + 1);
		if (vars->tmp_map[y][x - 1] != '1')
			valid_path(vars, y, x - 1);
		if (vars->tmp_map[y - 1][x] != '1')
			valid_path(vars, y - 1, x);
		if (vars->tmp_map[y + 1][x] != '1')
			valid_path(vars, y + 1, x);
		if (vars->tmp_col != 0)
			return (0);
	}
	return (1);
}

int	clone(t_vars *vars, char *a)
{
	int	fd;

	fd = open(a, O_RDONLY);
	vars->tmp_map[vars->hei] = get_next_line(fd);
	if (vars->tmp_map[vars->hei] == NULL)
	{
		ft_printf(RED "file is empty" DEF "\n");
		return (0);
	}
	while (vars->tmp_map[vars->hei])
	{
		vars->hei++;
		vars->tmp_map[vars->hei] = get_next_line(fd);
	}
	vars->tmp_map[vars->hei] = 0;
	vars->wid = ft_strlen(vars->tmp_map[0]) - 1;
	close(fd);
	find_player(vars);
	if (valid_path(vars, vars->pos_player.tmp_y, vars->pos_player.tmp_x) == 0)
	{
		ft_printf(RED "MAP HAS NO SOLUTION" DEF "\n");
		return (0);
	}
	return (1);
}
