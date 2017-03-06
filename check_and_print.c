/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-floc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 23:43:41 by ale-floc          #+#    #+#             */
/*   Updated: 2016/04/19 00:20:50 by ale-floc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		print_column(t_list *list)
{
	if (list->select == 0 && list->focus == 1)
		print_surligne(list->str);
	else if (list->select == 1 && list->focus == 0)
		print_select(list->str);
	else if (list->select == 1 && list->focus == 1)
		print_select_surligne(list->str);
	else
		print_base(list->str);
}

int			size_of_line(t_list *line, int limit)
{
	int		i;
	int		save;
	t_list	*list;

	i = 0;
	save = 0;
	list = line;
	while (i != get_select()->line - 1)
	{
		if (save < ft_strlen(list->str))
			save = ft_strlen(list->str);
		list = list->next;
		i++;
		if ((limit + i) == get_select()->size)
			break ;
	}
	return (save + 5);
}

int			size_to_small(int size_long)
{
	if ((size_long - 5) > get_select()->column)
	{
		clear_term();
		ft_putendl_fd("Size to small !!", get_select()->fd);
		return (1);
	}
	return (0);
}

void		check_screen_secu(t_list *list, int save)
{
	if (get_select()->secu == 0)
		get_select()->stock = size_of_line(list, save);
}

void		check_screen(t_select *env)
{
	int		nb_line;
	int		save;
	t_list	*list;

	list = init_check_screen(&nb_line);
	while (get_select()->final != env->size)
	{
		while (nb_line != (get_select()->line - 1))
		{
			check_screen_secu(list, save);
			tputs(tgoto(tgetstr("cm", NULL),
						get_select()->size_long, nb_line), 0, my_std);
			get_select()->secu = 1;
			print_column(list);
			list = list->next;
			nb_line = check_incrementation(nb_line);
			if (get_select()->final == get_select()->size)
				break ;
		}
		save += nb_line;
		nb_line = 0;
		get_select()->secu = 0;
		get_select()->size_long += get_select()->stock;
	}
	size_to_small(get_select()->size_long);
}
