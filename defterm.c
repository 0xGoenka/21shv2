/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defterm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 16:53:28 by eleclet           #+#    #+#             */
/*   Updated: 2016/04/18 16:56:08 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		def_term(void)
{
	char			*term_name;
	struct termios	term;

	if (!(term_name = getenv("TERM")))
		return (-1);
	if (tgetent(NULL, term_name) == ERR)
		return (-1);
	if (tcgetattr(0, &term) == -1)
		return (-1);
	term.c_lflag &= ~(ECHO | ICANON);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSANOW, &term) == -1)
		return (-1);
	return (1);
}
