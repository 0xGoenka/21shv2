/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 17:18:07 by eleclet           #+#    #+#             */
/*   Updated: 2016/05/25 16:17:33 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int main()
{
	t_line *l = NULL;
	t_historic *h = NULL;

	h = history(h);

	def_term();
	master(l, h);
	return (0);
}
int		master(t_line *l, t_historic *h)
{
	int i;
	i = 0;

	l = edition_ligne("21sh $>", NULL);
	//setcursor(l);

	while (1)
	{
		if (!quote(l->lst))
			l = mergelst(l ,edition_ligne("quotes>", NULL));
		else
		{
			//lst = l->lst;
				//while (lst)
				//{
				//	ft_putchar(lst->cha);
				//	lst = lst->next;
				//}
				//ft_putchar('\n');
				master(l, h);
		}
	}
}

t_line		*edition_ligne(char *prompt, t_line *line)
{
    int cha;
	t_lst *lst;
    if (!line)
		line = init(line);
	//else
		//setcursor(line);
    ft_putstr(prompt);
	lst = line->lst;
		while (lst)
		{
			ft_putchar(lst->cha);
			lst = lst->next;
		}

    //ft_putstr("quote >");
    while (42)
    {
        if ((cha = readline(line)) > 0)
        {

            add(line, cha);
            printend(line, 0);
            godown(line, 0);
        }
        if (cha == -1) // enter presswed ?
		{
			ft_putchar('\n');
			return (line);
		}
        debugtofile(line, "main");
    }
}

char	readline(t_line *line)
{
	char buf[7];

	ft_bzero(buf,7);
	read(0, buf, 6);

    if (buf[0] == 10 && buf[1] == 0)
        return (-1);
	if (movecursor(buf, line))
		return (0);
    else
	   return (key(buf));
}
