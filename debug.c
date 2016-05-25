/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 13:39:14 by eleclet           #+#    #+#             */
/*   Updated: 2016/05/24 12:38:08 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "sh.h"

int		debugtofile(t_line *line, char *s)
{
	int fd;
	int i;
	t_lst *lst;

	if (!line)
		return (0);
	i = 0;
	lst = line->lst;
	fd = open("debug.txt", O_WRONLY);
	if (fd == -1)
	{
		ft_putstr("Open error occured\n");
		close(fd);
		return (0);
	}
	lst = line->lst;
	while (lst)
	{
		lst = lst->next;
		i++;
	}

	dprintf(fd, "countlst ");
	dprintf(fd, "%d ", i);
	dprintf(fd, "posx ");
	dprintf(fd, "%d ", line->posx);
	dprintf(fd, "col ");
	dprintf(fd, "%d ", col());
	dprintf(fd, "posy ");
	dprintf(fd, "%d ", line->posy);
	dprintf(fd, " lenx ");
	dprintf(fd, "%d", line->lenx);
	dprintf(fd, " leny ");
	dprintf(fd, "%d", line->leny);
	dprintf(fd, " len ");
	dprintf(fd,  "%d  ", line->len);
	dprintf(fd, " lenpos ");
	dprintf(fd,  "%d", line->poslen);
	dprintf(fd, " debug : ");
	dprintf(fd,  "%s                                         ", s);
	close(fd);
	return (1);
}
