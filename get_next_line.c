/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 19:49:51 by abrichar          #+#    #+#             */
/*   Updated: 2017/03/27 10:40:32 by abrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//affiche actuellement la premiere ligne
//tout faire dans la meme fonction puis séparer après
int			get_next_line(const int fd, char **line)
{
	int		ret;
	int		index;
	char	buff[BUFF_SIZE + 1];
	int		control;
	static int	nbre_line;

	nbre_line = 0;
	control = 0;
	if (!fd)
		return (-1);
	while ((ret = read(fd, buff, BUFF_SIZE)) && control != -1)
	{
		index = 0;
		while (buff[index] != '\n' && buff[index] != '\0' && index < BUFF_SIZE)
			index++;
		if (buff[index] == '\n')
		{
			control = -1;
			nbre_line++;
		}
		buff[index] = '\0';
		//Besoin de sauvegarder la ligne pour que je puisse afficher la bonne ligne
		*line = ft_strdup(buff);
		//Besoin de sauvegarder toute la ligne dans une variable pour pouvoir l afficher a partir du main
		ft_putstr(*line);
		ft_putnbr(nbre_line);
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
	close(fd);
	return (0);
}
