/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairou <mkhairou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 10:59:25 by mkhairou          #+#    #+#             */
/*   Updated: 2022/12/27 11:55:13 by mkhairou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	close_win(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	free(vars);
	exit(0);
}

int	key_hook(int keyword, t_vars *vars)
{
	if (keyword == escape)
		close_win(vars);
	if (keyword == move_right || keyword == d)
		move_r(vars);
	if (keyword == move_left || keyword == a)
		move_l(vars);
	if (keyword == move_up || keyword == w)
		move_u(vars);
	if (keyword == move_back || keyword == s)
		move_d(vars);
	return (0);
}

void	put_text(t_vars *vars)
{
	vars->mv = ft_itoa(vars->move);
	vars->cole = ft_itoa(vars->col);
	mlx_string_put(vars->mlx, vars->win, 0, 0, 0xffffffff, "moves");
	mlx_string_put(vars->mlx, vars->win, 100, 0, 0xffff00ff, vars->mv);
	free(vars->mv);
	mlx_string_put(vars->mlx, vars->win, 0, 20, 0xffffffff, "COINS TO GO");
	mlx_string_put(vars->mlx, vars->win, 200, 20, 0xff00ffff, vars->cole);
	free(vars->cole);
}

int	main(int ac, char *av[])
{
	t_vars	*vars;

	if (ac == 1)
		ft_printf(RED "ERROR1" DEF "\n");
	if (ac > 1)
	{
		ext_check(av[1]);
		if (!ext_check(av[1]))
			exit(0);
	}
	vars = ft_calloc(sizeof(t_vars), 1024);
	map_creat(vars, av[1]);
	fill_all(vars);
	map_fill(vars, 1);
	mlx_hook(vars->win, 2, 0, key_hook, vars);
	mlx_hook(vars->win, 17, 0, close_win, vars);
	put_text(vars);
	mlx_loop_hook(vars->mlx, &test, vars);
	mlx_loop(vars->mlx);
}
