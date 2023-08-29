/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlyu <jlyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 11:02:38 by jlyu              #+#    #+#             */
/*   Updated: 2023/08/17 11:04:10 by jlyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static int	fdf_get_color(double per)
{
	if (per <= 1.0 && per > 0.9)
		return (0x800080);
	if (per <= 0.9 && per > 0.8)
		return (0xFF00FF);
	if (per <= 0.8 && per > 0.7)
		return (0xFF0000);
	if (per <= 0.7 && per > 0.6)
		return (0xFF4500);
	if (per <= 0.6 && per > 0.5)
		return (0xFFA500);
	if (per <= 0.5 && per > 0.4)
		return (0xFFFF00);
	if (per <= 0.4 && per > 0.3)
		return (0xADFF2F);
	if (per <= 0.3 && per > 0.2)
		return (0x008000);
	if (per <= 0.2 && per > 0.1)
		return (0x00FFFF);
	else
		return (0x0000FF);
}

static double	draw_line_util_cal(t_coordinate **points, int i,
	double *coordinator, int **data)
{
	if (points[0]->altitude > points[1]->altitude)
		return ((float)((points[1]->altitude + ((points[0]->altitude
						- points[1]->altitude) * ((float) i / coordinator[5]))
				- data[0][2]) / (data[0][3] - data[0][2])));
	else if (points[0]->altitude < points[1]->altitude)
		return ((float)((points[1]->altitude - ((points[1]->altitude
						- points[0]->altitude) * ((float) i / coordinator[5]))
				- data[0][2]) / (data[0][3] - data[0][2])));
	else
		return ((float)((points[0]->altitude - data[0][2])
			/ (data[0][3] - data[0][2])));
}

void	draw_line_util(t_vars *vars, t_coordinate **points,
	double *coordinator, int **data)
{
	int		color;
	double	persent;
	int		i;

	i = (int) coordinator[5];
	while (i)
	{
		persent = draw_line_util_cal(points, i, coordinator, data);
		color = fdf_get_color(persent);
		mlx_pixel_put(vars->mlx, vars->win, coordinator[2],
			coordinator[3], color);
		coordinator[2] += coordinator[0];
		coordinator[3] += coordinator[1];
		--i;
	}
}
