/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-floc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 23:34:18 by ale-floc          #+#    #+#             */
/*   Updated: 2016/04/19 00:20:06 by ale-floc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_error(char *str, int fd)
{
	ft_putendl_fd(str, fd);
	exit(-1);
}

int		my_std(int c)
{
	ft_putchar_fd(c, get_select()->fd);
	return (0);
}

void	clear_term(void)
{
	tputs(tgetstr("ho", NULL), 0, my_std);
	tputs(tgetstr("cd", NULL), 0, my_std);
}

int		check_incrementation(int nb_line)
{
	get_select()->final++;
	nb_line++;
	return (nb_line);
}
