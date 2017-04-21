/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 19:49:51 by abrichar          #+#    #+#             */
/*   Updated: 2017/04/21 15:56:37 by abrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//affiche actuellement la premiere ligne
//tout faire dans la meme fonction puis séparer après
//Pouvoir sauvergarder l'endroit où on est pour pouvoir changer au besoin
//Mettre dans un lne-> quand il y a un \n ?
static t_line	*init_list(t_line *line, int fd)
{
	t_line	*begin;
	t_line	*before;

	begin = line;
	before = NULL;
	while (line && line->fd != fd)
	{
		before = line;
		line = line->next;
	}
	if (!line)
	{
		line = ft_memalloc(sizeof(t_line));
		if (!line)
			return (0);
		line->fd = fd;
	}
}

int			get_next_line(const int fd, char **line)
{
	static t_line *lne = NULL;
	t_line *actual;
 	int		ret;
	int		index;
	char	buff[BUFF_SIZE + 1];

	if (!fd)
		return (-1);
	actual = lne;
	if (actual == lne)
		while ((ret = read(fd, buff, BUFF_SIZE)))
		{
			index = 0;
			while (buff[index])
			{
				while (buff[index] != '\n' && (buff[index]) && index < BUFF_SIZE)
					index++;
				buff[index] = '\0';
				actual.content = ft_strdup(buff);
				actual = actual->next;
				index++;
			}
			*line = ft_strdup(lne.content);
			lne = lne->next;
		}
	else
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
