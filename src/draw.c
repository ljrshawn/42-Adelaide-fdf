/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlyu <jlyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 14:50:23 by jlyu              #+#    #+#             */
/*   Updated: 2023/08/17 11:02:21 by jlyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static t_coordinate	*get_start_point(int *data, int unit, int size)
{
	t_coordinate	*result;

	result = malloc(sizeof(t_coordinate));
	if (result == NULL)
		exit(1);
	result->x = (size - unit * data[1]) / 2;
	result->y = (size - unit * data[0]) / 2;
	return (result);
}

static void	draw_img(t_vars *vars, int **data, int ratio)
{
	t_coordinate	*ini;
	int				*window;

	window = malloc(4 * sizeof(int));
	if (window == NULL)
		exit(1);
	window[0] = 360 * ratio / (2 * data[0][0]);
	if (window[0] > 360 * ratio / (2 * data[0][1]))
		window[0] = 360 * ratio / (2 * data[0][1]);
	window[1] = ratio;
	ini = get_start_point(data[0], window[0], 360 * ratio);
	draw_img_util(vars, data, window, ini);
	free(ini);
	free(window);
}

void	fdf_draw(int **data)
{
	t_vars	vars;
	int		ratio;

	ratio = data[0][1] / data[0][0];
	if (data[0][1] % data[0][0] != 0)
		ratio += 1;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 360 * ratio, 360 * ratio, "fdf");
	draw_img(&vars, data, ratio);
	mlx_hook(vars.win, 2, 1L << 0, close_win_esc, &vars);
	mlx_hook(vars.win, 17, 1L << 5, close_win_mouse, &vars);
	mlx_loop(vars.mlx);
}
