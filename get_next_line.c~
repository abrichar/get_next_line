/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 19:49:51 by abrichar          #+#    #+#             */
/*   Updated: 2017/04/20 18:15:01 by abrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//affiche actuellement la premiere ligne
//tout faire dans la meme fonction puis séparer après
//Pouvoir sauvergarder l'endroit où on est pour pouvoir changer au besoin
int			get_next_line(const int fd, char **line)
{
	static t_line *lne = NULL;
 	int		ret;
	int		index;
	char	buff[BUFF_SIZE + 1];
	int		control;

	control = 0;
	if (!fd)
		return (-1);
	while ((ret = read(fd, buff, BUFF_SIZE)) && control != -1)
	{
		index = 0;
		while (buff[index] != '\n' && buff[index] != '\0' && index < BUFF_SIZE)
			index++;
		if (buff[index] == '\n')
			control = -1;
		buff[index] = '\0';
		*line = ft_strdup(buff);
	}
	if ((ret = read(fd, *line, BUFF_SIZE)) == 0)
		return (0);
	return (1);
}

int		main(void)
{
	int			fd;
	char		*line;

	line = 0;
	fd = open("test", O_RDONLY);
	get_next_line(fd, &line);
	ft_putendl(line);
	get_next_line(fd, &line);
	close(fd);
	return (0);
}
