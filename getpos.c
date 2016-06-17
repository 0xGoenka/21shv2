#include "sh.h"

int     curscol(int fd)
{
    int             i;
    int             col;
    struct termios  term_curs;
    struct termios  term_set;
    char            *buf;

    i = 0;
    col = 0;
    buf = ft_strnew(16);
    ft_modif_term(&term_curs, 1);
    write(fd, "\033[6n", 4);
    read(fd, buf, 16);
    while (ft_isdigit(buf[i]) == 0)
        i++;
    while (ft_isdigit(buf[i]) == 1)
        i++;
    while (ft_isdigit(buf[i]) == 0)
        i++;
    while (ft_isdigit(buf[i++]) == 1)
        col = col * 10 + buf[i - 1] - 48;
    ft_modif_term(&term_set, 0);
    free(buf);
    return (col);
}

int     cursrow(int fd)
{
    int             i;
    int             row;
    struct termios  term_curs;
    struct termios  term_set;
    char            *buf;

    i = 0;
    row = 0;
    buf = ft_strnew(16);
    ft_modif_term(&term_curs, 1);
    write(fd, "\033[6n", 4);
    read(fd, buf, 16);
    while (ft_isdigit(buf[i]) == 0)
        i++;
    while (ft_isdigit(buf[i++]) == 1)
        row = row * 10 + buf[i - 1] - 48;
    ft_modif_term(&term_set, 0);
    free(buf);
    return (row);
}

void        ft_modif_term(struct termios *term_set, int test)
{
    tcgetattr(0, term_set);
    if (test == 0)
        term_set->c_lflag &= ~(ICANON | ECHO);
    else if (test == 1)
        term_set->c_lflag &= ~(ICANON | ECHO | CREAD);
    tcsetattr(0, TCSANOW, term_set);
}

void 		cursok(t_historic *h)
{
	h->l->posx = h->l->len;
	h->l->poslen = h->l->len;
}
