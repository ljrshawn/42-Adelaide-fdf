/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlyu <jlyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 14:50:18 by jlyu              #+#    #+#             */
/*   Updated: 2023/08/16 11:45:10 by jlyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static void	fdc_copy_new(char **tem, int **res, int size, int index)
{
	int	i;
	int	num;

	res[index - 1] = malloc((size + 1) * sizeof(int));
	if (res[index - 1] == NULL)
	{
		ft_printf("%s\n", strerror(errno));
		exit (1);
	}
	i = 0;
	while (i < size)
	{
		num = ft_atoi(tem[i]);
		res[index - 1][i] = num;
		if (res[0][2] > num)
			res[0][2] = num;
		if (res[0][3] < num)
			res[0][3] = num;
		i++;
	}
	res[index] = NULL;
}

static void	fdc_copy_old_util(int **data, int **res, int size, int i)
{
	int	j;

	res[i] = malloc((size + 1) * sizeof(int));
	if (res[i] == NULL)
	{
		ft_printf("%s\n", strerror(errno));
		exit (1);
	}
	j = 0;
	while (j < size)
	{
		res[i][j] = data[i][j];
		j++;
	}
	res[i][j] = '\0';
}

static void	fdc_copy_old(int **data, int **res, int size, int index)
{
	int	i;

	if (data == NULL)
	{
		get_feature(res, size);
		return ;
	}
	copy_feature(data, res, index);
	i = 1;
	while (i < index)
	{
		fdc_copy_old_util(data, res, size, i);
		i++;
	}
	free_2d_array((void **) data);
}

static int	**fdf_save_data(char **tem, int **data)
{
	int	**res;
	int	m;
	int	n;

	m = get_2d_size((void **)tem);
	if (data == NULL)
		n = 2;
	else
		n = get_2d_size((void **)data) + 1;
	res = malloc((n + 1) * sizeof(int *));
	if (res == NULL)
		return (NULL);
	fdc_copy_old(data, res, m, n - 1);
	fdc_copy_new(tem, res, m, n);
	return (res);
}

void	fdf(char *file)
{
	int		fd;
	char	*str;
	char	**tem;
	int		**data;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("%s: Failed to open the file\n", strerror(errno));
		return ;
	}
	str = get_next_line(fd);
	while (str)
	{
		tem = ft_split(str, ' ');
		free(str);
		data = fdf_save_data(tem, data);
		free_2d_array((void **)tem);
		if (data == NULL)
			return ;
		str = get_next_line(fd);
	}
	close(fd);
	fdf_draw(data);
	free_2d_array((void **)data);
}
