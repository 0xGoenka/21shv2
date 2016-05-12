/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 17:18:07 by eleclet           #+#    #+#             */
/*   Updated: 2016/05/04 19:13:56 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int        main()
{
    int cha;
    t_line line;

    init(&line);
    def_term();
    ft_putstr("21sh $>");
    while (42)
    {
        //if (line.lst->next && !line.lst->next->next)
        //    printlast(&line);
        if ((cha = readline(&line)))
        {

            add(&line, cha);
            printend(&line);
            godown(&line);
        }
        debugtofile(&line, "main");
    }
    return (0);
}

char	readline(t_line *line)
{
	char buf[7];

	ft_bzero(buf,7);
	read(0, buf, 6);

	if (movecursor(buf, line))
		return (0);
    else
	   return (key(buf));
}
