/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 16:22:06 by eleclet           #+#    #+#             */
/*   Updated: 2016/05/23 19:29:27 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		quote(t_lst *l)
{
	int i;

	i = 0;
	while (l)
	{
		if (l->cha == 39) // cha == quote ?
			i++;
		l = l->next;
	}
	if (i % 2 != 0)
		return (0);
	else
	return (1);
}

t_line		*mergelst(t_line *a, t_line *b)
{
	t_line *merge;
	t_lst *la;
	t_lst *lb;
	la = a->lst->next;
	merge = (t_line *)malloc(sizeof(*merge));
	merge->lst = (t_lst *)malloc(sizeof(t_lst));
	while (la->next)
		la = la->next;
	lb = b->lst->next;

	merge->poslen = a->poslen + 1 + b->poslen;
	merge->len = a->len + 1 + b->len;
	merge->posx = a->posx + 1 + b->posx;
	merge->posy = a->posy + 1 + b->posy;
	merge->lenx = a->lenx + 1 + b->lenx;
	merge->leny = a->leny + 1 + b->leny;
	merge->lst->cha = '\n';
	merge->lst->next = lb;
	merge->lst->prev = la;
	lb->prev = merge->lst;
	la->next = merge->lst;
	merge->lst->len = len_n(merge->lst);
	printf(" %d ", merge->lst->len);
	return (a);
}

int		len_n(t_lst *l)
{
	int i;

	i = 0;
	l = l->prev;
	while (l->cha != '\n')
	{
		if (l->prev)
			l = l->prev;
		else
			break;
		i++;
	}
	return (i);
}
