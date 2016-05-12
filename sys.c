/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sys.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 12:07:30 by eleclet           #+#    #+#             */
/*   Updated: 2016/04/26 12:11:34 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int     col(void)
{
    struct winsize w;

    ioctl(0, TIOCGWINSZ, &w);
    return (w.ws_col);
}
int     row(void)
{
    struct winsize w;

    ioctl(0, TIOCGWINSZ, &w);
    return (w.ws_row);
}
