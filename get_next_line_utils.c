/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-cast <ana-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:23:02 by ana-cast          #+#    #+#             */
/*   Updated: 2023/10/01 21:28:26 by ana-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

char	*ft_strdup(char *s1)
{
	char	*dest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1[i])
		i++;
	dest = (char *)malloc(sizeof(char) * (i + 1));
	if (dest == NULL)
		return (NULL);
	while (s1[j])
	{
		dest[j] = s1[j];
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*substr;
	unsigned int	s_len;

	if (!s)
		return (NULL);
	s_len = (unsigned int)ft_strlen((char *)s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (start + len > s_len)
		len = s_len - start;
	substr = (char *)malloc(sizeof(char) * len + 1);
	if (!substr)
		return (NULL);
	i = -1;
	while (++i < (unsigned int)len)
		substr[i] = s[start + i];
	substr[i] = '\0';
	return (substr);
}

int	ft_gn_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == (char)c)
			return (++i);
		i++;
	}
	return (0);
}

char	*ft_gn_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*result;
	int		len_s1;
	int		len_s2;

	len_s1 = ft_strlen((char *)s1);
	len_s2 = ft_strlen((char *)s2);
	i = len_s1 + len_s2;
	result = (char *)malloc(sizeof(char) * i + 1);
	if (!result)
		return (free_str((char **)(&s1)));
	i = -1;
	while (++i < len_s1)
		result[i] = s1[i];
	i = -1;
	while (++i < len_s2)
		result[i + len_s1] = s2[i];
	result[i + len_s1] = '\0';
	free_str((char **)(&s1));
	return (result);
}
