/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arazzok <arazzok@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 15:17:50 by arazzok           #+#    #+#             */
/*   Updated: 2023/10/14 15:16:55 by arazzok          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	static char	*stock[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stock[fd] = read_and_stock(fd, stock[fd]);
	if (!stock[fd])
		return (NULL);
	line = extract_line(stock[fd]);
	stock[fd] = clear_stock(stock[fd]);
	return (line);
}

char	*read_and_stock(int fd, char *stock)
{
	char	*buff;
	int		rd_chars;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	rd_chars = 1;
	while (!is_newline(stock) && rd_chars != 0)
	{
		rd_chars = (int)read(fd, buff, BUFFER_SIZE);
		if (rd_chars == -1)
		{
			free(buff);
			free(stock);
			return (NULL);
		}
		buff[rd_chars] = '\0';
		stock = ft_strjoin(stock, buff);
	}
	free(buff);
	return (stock);
}

char	*extract_line(char *stock)
{
	int		i;
	char	*line;

	i = 0;
	if (!stock[i])
		return (NULL);
	while (stock[i] && stock[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (stock[i] && stock[i] != '\n')
	{
		line[i] = stock[i];
		i++;
	}
	if (stock[i] && stock[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*clear_stock(char *stock)
{
	int		i;
	int		j;
	char	*clean;

	i = 0;
	while (stock[i] && stock[i] != '\n')
		i++;
	if (!stock[i])
	{
		free(stock);
		return (NULL);
	}
	clean = (char *)malloc(sizeof(char) * (ft_strlen(stock) - i + 1));
	if (!clean)
		return (NULL);
	i++;
	j = 0;
	while (stock[i])
		clean[j++] = stock[i++];
	clean[j] = '\0';
	free(stock);
	return (clean);
}
