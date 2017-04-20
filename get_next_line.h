/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 22:10:59 by abrichar          #+#    #+#             */
/*   Updated: 2017/04/20 18:07:39 by abrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft/includes/libft.h"
# define BUFF_SIZE 32

typedef struct		s_line
{
	struct s_line	*next;
	int				fd;
	char			*content;
	char			padding[4];
}					t_line;

int		get_next_line(const int fd, char **line);


#endif
