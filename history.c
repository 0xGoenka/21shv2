/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 17:41:20 by eleclet           #+#    #+#             */
/*   Updated: 2016/05/25 16:04:01 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		setcursor(t_line *line)
{
	int posy;

	posy = line->posy;
	while (posy)
	{
		tputs(tgetstr("up", 0), 0, outc);
		posy--;
	}
	tputs(tgoto(tgetstr("ch", 0), 0, 0), 0, outc);
	tputs(tgetstr("cd", 0), 0, outc);
	return (0);
}
t_historic		*history(t_historic *h)
{
	h = (t_historic *)malloc(sizeof(h));
	return (h);
}
