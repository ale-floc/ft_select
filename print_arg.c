/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-floc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 23:35:31 by ale-floc          #+#    #+#             */
/*   Updated: 2016/04/18 23:36:40 by ale-floc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	print_surligne(char *str)
{
	tputs(tgetstr("us", NULL), 0, my_std);
	ft_putendl_fd(str, get_select()->fd);
	tputs(tgetstr("ue", NULL), 0, my_std);
}

void	print_select_surligne(char *str)
{
	tputs(tgetstr("so", NULL), 0, my_std);
	tputs(tgetstr("us", NULL), 0, my_std);
	ft_putendl_fd(str, get_select()->fd);
	tputs(tgetstr("ue", NULL), 0, my_std);
	tputs(tgetstr("se", NULL), 0, my_std);
}

void	print_select(char *str)
{
	tputs(tgetstr("so", NULL), 0, my_std);
	ft_putendl_fd(str, get_select()->fd);
	tputs(tgetstr("se", NULL), 0, my_std);
}

void	print_base(char *str)
{
	ft_putendl_fd(str, get_select()->fd);
}
