/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 16:22:44 by abrichar          #+#    #+#             */
/*   Updated: 2017/05/27 16:38:58 by abrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main(int argc, char **argv)
{
	int fd01;
	int	fd02;
	char *line;

	if (argc || argv)
		;
	fd01 = open("test01", O_RDONLY);
	fd02 = open("test02", O_RDONLY);
	get_next_line(fd01, &line);
	printf("%s\n", line);
	get_next_line(fd02, &line);
	printf("%s\n", line);
	get_next_line(fd01, &line);
	printf("%s\n", line);
	get_next_line(fd02, &line);
	printf("%s\n", line);
	close(fd01);
	return (0);
}
