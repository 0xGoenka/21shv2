/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 17:18:49 by eleclet           #+#    #+#             */
/*   Updated: 2016/05/03 19:31:22 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_H
# define SH_H
# include "libft/libft.h"
# include <unistd.h>
# include <stdio.h> //sdd
# include <termcap.h>
# include <termios.h>
# include <curses.h>
# include <sys/ioctl.h>

typedef struct          s_lst
{
    char                cha;
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
int        init(t_line *line);
void	   add(t_line *line, char cha);
void       printlast(t_line *line);
void	   delelem(t_line *line);
void	   printend(t_line *line);
void       goodcol(t_line *line);
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
void    godown(t_line *line);

#endif
