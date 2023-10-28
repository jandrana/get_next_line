/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-cast <ana-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:22:56 by ana-cast          #+#    #+#             */
/*   Updated: 2023/10/01 21:28:18 by ana-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif /* BUFFER_SIZE */

int		ft_strlen(const char *str);
char	*ft_strdup(char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_gn_strchr(const char *s, int c);
char	*ft_gn_strjoin(char const *s1, char const *s2);
char	*free_str(char **str);
char	*ft_add_buffer(char *buffer, int fd);
char	*get_result_buffer(char **buffer);
char	*get_next_line(int fd);

#endif /* GET_NEXT_LINE_H */
