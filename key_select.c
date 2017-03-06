/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_select.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-floc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 23:28:28 by ale-floc          #+#    #+#             */
/*   Updated: 2016/04/18 23:33:55 by ale-floc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void				touch_key_up(t_select *env)
{
	t_list			*tmp;

	if (env->size != 1)
	{
		tmp = env->begin;
		while (tmp->focus != 1)
			tmp = tmp->next;
		if (env->begin->next->focus == 1)
		{
			env->begin->next->focus = 0;
			env->begin->focus = 1;
		}
		else
		{
			tmp->focus = 0;
			tmp = tmp->prev;
			tmp->focus = 1;
		}
	}
}

void				touch_key_down(t_select *env)
{
	t_list			*tmp;

	if (env->size != 1)
	{
		tmp = env->begin;
		while (tmp->focus != 1)
			tmp = tmp->next;
		if (env->begin->prev->focus == 1)
		{
			env->begin->prev->focus = 0;
			env->begin->focus = 1;
		}
		else
		{
			tmp->focus = 0;
			tmp = tmp->next;
			tmp->focus = 1;
		}
	}
}

void				touch_key_echap(void)
{
	struct termios	term;

	tgetent(NULL, getenv("TERM"));
	tcgetattr(get_select()->fd, &term);
	term.c_lflag |= (ICANON);
	term.c_lflag |= (ECHO);
	clear_term();
	tputs(tgetstr("ve", NULL), 0, my_std);
	tcsetattr(get_select()->fd, TCSADRAIN, &term);
	close(get_select()->fd);
	exit(0);
}

void				touch_key_space(t_list *list)
{
	t_list			*tmp;

	tmp = list;
	while (tmp->focus != 1)
		tmp = tmp->next;
	tmp->select = (tmp->select == 0) ? 1 : 0;
	tmp->focus = 0;
	tmp = tmp->next;
	tmp->focus = 1;
}

t_list				*touch_key_delete(t_select *env)
{
	t_list			*tmp;
	int				i;

	i = 0;
	tmp = env->begin;
	while (tmp->focus != 1 && ++i)
		tmp = tmp->next;
	env->begin = (!i) ? dlt_maillon(env) : dlt_other_maillon(env);
	if (env->size == 0)
		touch_key_echap();
	return (env->begin);
}
