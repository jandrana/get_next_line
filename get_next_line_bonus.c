/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-cast <ana-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:22:59 by ana-cast          #+#    #+#             */
/*   Updated: 2023/10/01 22:47:01 by ana-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*free_str(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

char	*get_result_buffer(char **buffer)
{
	char	*temp;
	char	*result;
	int		nl_pos;

	temp = ft_strdup(*buffer);
	free_str(buffer);
	if (!temp)
		return (NULL);
	if (!ft_gn_strchr(temp, '\n'))
	{
		result = ft_strdup(temp);
		free_str(&temp);
		return (result);
	}
	nl_pos = ft_gn_strchr(temp, '\n');
	result = ft_substr(temp, 0, nl_pos);
	if (!result)
		return (free_str(&temp));
	*buffer = ft_substr(temp, nl_pos, ft_strlen(temp) - nl_pos);
	free_str(&temp);
	if (!*buffer || !*buffer[0])
		free_str(buffer);
	return (result);
}

char	*ft_add_buffer(char *buffer, int fd)
{
	char	*addbuff;
	int		b_read;

	b_read = 1;
	addbuff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!addbuff)
		return (free_str(&buffer));
	while (b_read > 0 && !ft_gn_strchr(buffer, '\n'))
	{
		b_read = read(fd, addbuff, BUFFER_SIZE);
		if (b_read < 0)
		{
			free_str(&addbuff);
			return (free_str(&buffer));
		}
		addbuff[b_read] = '\0';
		if (!buffer && b_read > 0)
			buffer = ft_strdup(addbuff);
		else if (b_read > 0)
			buffer = ft_gn_strjoin(buffer, addbuff);
	}
	free_str(&addbuff);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1392];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer[fd] || !ft_gn_strchr(buffer[fd], '\n'))
		buffer[fd] = ft_add_buffer(buffer[fd], fd);
	if (!buffer[fd])
		return (NULL);
	return (get_result_buffer(&buffer[fd]));
}
