/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arekoune <arekoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 10:33:42 by arekoune          #+#    #+#             */
/*   Updated: 2024/05/27 13:16:17 by arekoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
void	ft_read(char **line, int fd);
char	*join_reste(char *line, char *reste);
char	*reture_line(char *line, char **reture);
int		check_line(char *str);
char	*str_join_next(char *s1, char *s2);
char	*mini_join(char *s1, char *s2, char *str);
int		str_len_next(char *str);

#endif