/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlyu <jlyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 17:11:59 by jlyu              #+#    #+#             */
/*   Updated: 2023/08/16 11:37:49 by jlyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	get_2d_size(void **tem)
{
	int		m;
	void	**matrix;

	m = 0;
	matrix = tem;
	while (*matrix)
	{
		matrix++;
		m++;
	}
	return (m);
}

void	free_2d_array(void **matrix)
{
	void	**tem;

	tem = matrix;
	while (*tem)
	{
		free(*tem);
		tem++;
	}
	free(matrix);
}

void	get_feature(int **res, int size)
{
	res[0] = malloc((5) * sizeof(int));
	if (res[0] == NULL)
	{
		ft_printf("%s\n", strerror(errno));
		exit (1);
	}
	res[0][0] = 0;
	res[0][1] = size;
	res[0][2] = 0;
	res[0][3] = 0;
	res[0][4] = '\0';
}

void	copy_feature(int **data, int **res, int index)
{
	res[0] = malloc((5) * sizeof(int));
	if (res[0] == NULL)
	{
		ft_printf("%s\n", strerror(errno));
		exit (1);
	}
	res[0][0] = index;
	res[0][1] = data[0][1];
	res[0][2] = data[0][2];
	res[0][3] = data[0][3];
	res[0][4] = '\0';
}
