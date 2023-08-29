/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlyu <jlyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 10:58:06 by jlyu              #+#    #+#             */
/*   Updated: 2023/08/17 11:04:56 by jlyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static t_coordinate	*get_point(int **data, t_coordinate *ini, int *window)
{
	t_coordinate	*result;
	double			theta1;
	double			x;
	double			y;

	result = malloc(sizeof(t_coordinate));
	if (result == NULL)
		exit(1);
	x = ini->x + window[3] * window[0] - (360 * window[1] / 2);
	y = ini->y + window[2] * window[0] - (360 * window[1] / 2);
	x = x - y * 0.5;
	theta1 = (float) 30 * M_PI / 180.0;
	x = x * cos(theta1) - y * sin(theta1);
	y = x * sin(theta1) + y * cos(theta1);
	if (data[window[2] + 1][window[3]] > 0)
		y -= (((float)data[window[2] + 1][window[3]]
					/ data[0][3])) * 2 * window[0];
	if (data[window[2] + 1][window[3]] < 0)
		y += (((float)data[window[2] + 1][window[3]]
					/ data[0][2])) * 2 * window[0];
	result->x = x + (360 * window[1] / 2);
	result->y = y + (360 * window[1] / 2);
	result->altitude = data[window[2] + 1][window[3]];
	return (result);
}

static void	draw_line(t_vars *vars, t_coordinate *start,
	t_coordinate *end, int **data)
{
	double			*coordinator;
	t_coordinate	**points;

	coordinator = malloc(5 * sizeof(double));
	if (coordinator == NULL)
		exit(1);
	coordinator[0] = end->x - start->x;
	coordinator[1] = end->y - start->y;
	coordinator[5] = sqrt((coordinator[0] * coordinator[0])
			+ (coordinator[1] * coordinator[1]));
	coordinator[0] /= coordinator[5];
	coordinator[1] /= coordinator[5];
	coordinator[2] = start->x;
	coordinator[3] = start->y;
	points = malloc(2 * sizeof(t_coordinate *));
	if (points == NULL)
		exit(1);
	points[0] = start;
	points[1] = end;
	draw_line_util(vars, points, coordinator, data);
	free(coordinator);
	free(points);
}

static void	draw_util_1(t_vars *vars, int **data,
	int *window, t_coordinate *ini)
{
	t_coordinate	*start;
	t_coordinate	*end;

	start = get_point(data, ini, window);
	window[2] += 1;
	end = get_point(data, ini, window);
	draw_line(vars, start, end, data);
	free(start);
	free(end);
	window[2] -= 1;
}

static void	draw_util_2(t_vars *vars, int **data,
	int *window, t_coordinate *ini)
{
	t_coordinate	*start;
	t_coordinate	*end;

	start = get_point(data, ini, window);
	window[3] += 1;
	end = get_point(data, ini, window);
	draw_line(vars, start, end, data);
	free(start);
	free(end);
	window[3] -= 1;
}

void	draw_img_util(t_vars *vars, int **data, int *window, t_coordinate *ini)
{
	window[2] = 0;
	while (window[2] < data[0][0])
	{
		window[3] = 0;
		while (window[3] < data[0][1])
		{
			if (window[2] != data[0][0] - 1)
				draw_util_1(vars, data, window, ini);
			if (window[3] != data[0][1] - 1)
				draw_util_2(vars, data, window, ini);
			window[3]++;
		}
		window[2]++;
	}
}
