/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acomet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 17:05:34 by acomet            #+#    #+#             */
/*   Updated: 2022/10/24 16:42:09 by acomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_get_beyond_line(char *str)
{
	char	*temp;
	int		i;
	int		j;

	if (str == NULL)
		return (NULL);
	temp = NULL;
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	j = 0;
	while (str[i + j] != '\0')
		j++;
	if (j != 0)
	{
		temp = malloc(sizeof(char) * (j + 1));
		if (temp == NULL)
			return (NULL);
		ft_strcpy(temp, str + i + 1);
	}
	free (str);
	return (temp);
}

static char	*ft_get_final_str(char *str)
{
	char	*final_str;
	int		i;

	if (str == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\n')
		i++;
	final_str = malloc(sizeof(char) * (i + 1));
	if (final_str == NULL)
		return (NULL);
	ft_strlcpy(final_str, str, i + 1);
	return (final_str);
}

static char	*ft_the_next_line(int fd, char *str, int i)
{
	char	*buffer;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	buffer[0] = '\0';
	while ((ft_strchr(buffer) == -1) && (i > 0))
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[i] = '\0';
		str = ft_strjoin(str, buffer);
	}
	free(buffer);
	if (i == 0 && str[0] == '\0')
	{
		free(str);
		str = NULL;
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str[1024];
	char		*final_str;
	int			i;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	i = 1;
	str[fd] = ft_the_next_line(fd, str[fd], i);
	final_str = ft_get_final_str(str[fd]);
	str[fd] = ft_get_beyond_line(str[fd]);
	return (final_str);
}
