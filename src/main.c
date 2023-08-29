/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlyu <jlyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 11:43:48 by jlyu              #+#    #+#             */
/*   Updated: 2023/08/11 15:34:25 by jlyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	main(int argc, char *argv[])
{
	if (argc == 2)
		fdf(argv[1]);
	else
	{
		ft_printf("%s: correct command %s <filename>\n",
			strerror(errno), argv[0]);
		exit(0);
	}
	return (0);
}
