/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 17:24:51 by eleclet           #+#    #+#             */
/*   Updated: 2016/05/11 18:05:30 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int        init(t_line *line)
{
    if (!(line->lst = (t_lst *)malloc(sizeof(t_lst))))
        return (0);
    line->posx = 0;
    line->posy = 0;
    line->lenx = 0;
    line->leny = 0;
    line->len = 0;
    line->poslen = 0;
    line->lst->next = NULL;
    line->lst->prev = NULL;
    line->lst->cha = 0;
    return (1);
}

void	add(t_line *line, char cha)
{
    int i;

    i = 0;
    debugtofile(line, "add bug");
	t_lst *before;
	t_lst *after;
	t_lst *begin;
    t_lst *current;

	begin = line->lst;
	while (i < line->poslen)
    {
		line->lst = line->lst->next;
        i++;
    }
	if (!(current = malloc(sizeof(t_lst))))
    {
        debugtofile(line, "return");
		return ;
    }
    ft_putchar(cha);
    before = line->lst;
    after = line->lst->next;

    current->next = after;
    current->prev = before;
    if (after)
        after->prev = current;
    before->next = current;
    current->cha = cha;
	line->lst = begin;
    line->posx++;
    line->poslen++;
    line->lenx++;
    line->len++;
    line->leny = (line->len + 6) / col();
}

void	delelem(t_line *line)
{
	int i;
	t_lst *after;
	t_lst *before;
	t_lst *begin;

	begin = line->lst;
	i = 0;
	if (!line->posx && !line->posy)
		return ;
	while (i < line->poslen)
	{
		if (line->lst)
			line->lst = line->lst->next;
		i++;
	}
	after = line->lst->next;
 	before = line->lst->prev;
	if (after)
		after->prev = before;
	else
		after = NULL;
    if (before)
	   before->next = after;
	line->lst = begin;
    if (line->posx == 0 && line->posy == 1)
    {
        debugtofile(line, "del1");
        tputs(tgetstr("up", 0), 0, outc);
		toend();
        line->posy--;
        line->posx = col() - 8;
        line->lenx = col() - 8;
        line->poslen--;
        line->len--;
        return ;
    }
    if (line->posx == 0 && line->posy > 1)
    {
        debugtofile(line, "del2");
        tputs(tgetstr("up", 0), 0, outc);
		toend();
        line->posy--;
        line->posx = col() - 1;
        line->lenx = col() - 1;
        line->poslen--;
        line->len--;
        return ;
    }

    tputs(tgetstr("le", 0), 0, outc);
    line->posx--;
	line->poslen--;
    line->len--;
    if (line->posy == line->leny && line->leny)
        line->lenx = line->len + 7 - ((line->posy) * col());
    debugtofile(line, "del3");
//    else
//    {
//        line->lenx--
//    }
}
void 		printend(t_line *line)
{
	int i;
	int leny;
	t_lst *lst;

	i = 0;
	leny = 0;
    lst = line->lst;
    tputs(tgetstr("cd", 0), 0, outc);
	lst = lst->next;
	//debugtofile(line, "pend");
    //tputs(tgetstr("sc", 0), 0, outc);
	while (i < line->len)
	{
		if (i >= line->poslen)
		{
			ft_putchar(lst->cha);
		}
		lst = lst->next;
		i++;
	}
    leny = line->leny - line->posy;
    //printf("\n\n%d", leny);
    if (!line->posy)
        tputs(tgoto(tgetstr("ch", 0), 0, line->posx + 7),0 ,outc);
    else
        tputs(tgoto(tgetstr("ch", 0), 0, line->posx),0 ,outc);
    while (leny)
    {
        tputs(tgetstr("up", 0),0 ,outc);
        leny--;
    }


    //tputs(tgetstr("rc", 0), 0, outc);

}


void printlast(t_line *line)
{
    t_lst *lst;

    lst = line->lst;
	while (lst->next)
	{
		lst = lst->next;
	}
    if (lst->cha != 0)
	   ft_putchar(lst->cha);
    else
    {
        line->posx = 0;
    }
}
