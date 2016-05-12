/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 20:03:53 by eleclet           #+#    #+#             */
/*   Updated: 2016/05/11 16:03:53 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void    toend(void)
{
    int i;
    int len;

    len = col();
    i = 0;
    while (i < len)
    {
        tputs(tgetstr("nd", 0), 0, outc);
        i++;

    }
}

void    godown(t_line *line)
{
    if (!line->posy && line->posx == col() - 7)
    {
        tputs(tgetstr("do", 0), 0, outc);
        line->posx = 0;
        line->lenx = 0;
        line->posy++;
        //line->leny++;
    }
    else
    {
        if (line->posx == col() && line->posy > 0)
        {
            tputs(tgetstr("do", 0), 0, outc);
            line->posx = 0;
            line->lenx = 0;
            line->posy++;
            //line->leny++;
        }
    }
}
