/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 17:18:49 by eleclet           #+#    #+#             */
/*   Updated: 2016/05/25 16:03:26 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_H
# define SH_H
# include "libft/libft.h"
# include <unistd.h>
# include <curses.h>
# include <term.h>
# include <stdio.h> //sdd
# include <termcap.h>
# include <termios.h>
# include <sys/ioctl.h>

typedef struct          s_lst
{
    char                cha;
	short				len;
    struct s_lst        *next;
    struct s_lst        *prev;
}                       t_lst;

typedef struct          s_line
{
    t_lst   *lst;
    int     prompt;
    int     posx;
    int     posy;
    int     poslen;
    int     lenx;
    int     leny;
    int     len;
}                       t_line;
// lst.c

typedef struct			s_glob
{
	t_line				l;
	struct s_glob		*n;
	struct s_glob		*p;
}						t_glob;

typedef struct			s_historic
{
	t_line				l;
	t_line				*n;
	t_line				*p;
}						t_historic;
//history.c
int		setcursor(t_line *line);
t_historic		*history(t_historic *h);
//quote.c
int		len_n(t_lst *l);
int		quote(t_lst *l);
t_line		*mergelst(t_line *a, t_line *b);
//main.c
int			master(t_line *l, t_historic *h);
t_line		*edition_ligne(char *prompt, t_line *line);
char	readline(t_line *line);
//lst.c
t_line		*init(t_line *line);
void		add(t_line *line, char cha);
void 		printlast(t_line *line);
void 		delelem(t_line *line);
void 		printend(t_line *line, int bo);
void 		goodcol(t_line *line);
// defterm.c
int		def_term(void);
// main
char	readline(t_line *line);
//key.c
char    key(char *s);
void    goright(t_line *line);
void    goleft(t_line *line);
int	    movecursor(char *s, t_line *line);
// outc,c
int 	outc(int c);
// sys,c
int     col(void);
int     row(void);
// ebug,c
int		debugtofile(t_line *line, char *s);
// cursor.c
void     toend(void);
int     godown(t_line *line, int pad);

#endif
