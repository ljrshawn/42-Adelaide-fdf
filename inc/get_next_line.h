/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlyu <jlyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 09:29:35 by jlyu              #+#    #+#             */
/*   Updated: 2023/08/11 15:12:17 by jlyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BS
#  define BS 1000
# endif

char	*get_next_line_utils(int fd, char	*buffer);
char	*get_next_line(int fd);
int		get_str_len(char *c);
void	copy_buffer(char *res, char *readBuffer, int i);
char	*str_join(char *res, char *rem, int i, int j);

#endif
