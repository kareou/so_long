/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairou <mkhairou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 22:16:08 by mkhairou          #+#    #+#             */
/*   Updated: 2022/12/05 15:51:06 by mkhairou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*rad(int fd, char *line)
{
	char	*contain;
	int		rd;

	contain = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!contain)
		return (NULL);
	rd = 1;
	while (!ft_strchr(line, '\n') && rd != 0)
	{
		rd = read(fd, contain, BUFFER_SIZE);
		if (rd == -1)
		{
			free(line);
			free(contain);
			return (NULL);
		}
		contain[rd] = '\0';
		line = ft_strjoin(line, contain);
	}
	free(contain);
	return (line);
}

char	*clean(char *line)
{
	char	*contain;
	int		i;

	i = 0;
	if (!line[i])
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	contain = (char *)malloc((i + 2) * sizeof(char));
	if (!contain)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		contain[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
	{
		contain[i] = line[i];
		i++;
	}
	contain[i] = '\0';
	return (contain);
}

char	*lft(char *line)
{
	char	*a;
	int		i;
	int		j;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (!line[i] || (line[i] == '\n' && line[i + 1] == '\0'))
	{
		free(line);
		return (NULL);
	}
	a = (char *)malloc(sizeof(char) * (ft_strlen(line) - i));
	if (!a)
		return (NULL);
	i++;
	j = 0;
	while (line[i])
		a[j++] = line[i++];
	a[j] = '\0';
	free(line);
	return (a);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*nline;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	nline = rad(fd, nline);
	if (!nline)
		return (NULL);
	line = clean(nline);
	nline = lft(nline);
	return (line);
}
