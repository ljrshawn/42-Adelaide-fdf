/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlyu <jlyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 11:43:44 by jlyu              #+#    #+#             */
/*   Updated: 2023/08/17 11:04:23 by jlyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <stdio.h>

# include "../lib/libft/libft.h"
# include "../lib/minilibx/mlx.h"
# include "get_next_line.h"
# include "../lib/printf/ft_printf.h"

typedef struct s_coordinate
{
	double	x;
	double	y;
	double	altitude;
}	t_coordinate;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}	t_vars;

void	fdf_draw(int **data);
void	draw_img_util(t_vars *vars, int **data,
			int *window, t_coordinate *ini);
void	draw_line_util(t_vars *vars, t_coordinate **points,
			double *coordinator, int **data);

void	fdf(char *file);
int		get_2d_size(void **tem);
void	free_2d_array(void **matrix);
void	get_feature(int **res, int size);
void	copy_feature(int **data, int **res, int index);

int		close_win_esc(int keycode, t_vars *vars);
int		close_win_mouse(void);

#endif