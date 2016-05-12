/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 20:03:53 by eleclet           #+#    #+#             */
/*   Updated: 2016/05/12 18:16:39 by eleclet          ###   ########.fr       */
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

int   godown(t_line *line, int pad)
{
    if (!line->posy && line->posx == col() - 7 - pad)
    {
        tputs(tgetstr("do", 0), 0, outc);
        line->posx = 0;
        line->lenx = 0;
        line->posy++;
        return (1);
        //line->leny++;
    }
    else
    {
        if (line->posx == col() - pad && line->posy > 0)
        {
            tputs(tgetstr("do", 0), 0, outc);
            line->posx = 0;
            line->lenx = 0;
            line->posy++;
            return (1);
            //line->leny++;
        }
    }
    return (0);
}
