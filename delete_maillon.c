/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_maillon.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-floc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 23:40:49 by ale-floc          #+#    #+#             */
/*   Updated: 2016/04/18 23:42:47 by ale-floc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_list		*dlt_maillon(t_select *env)
{
	t_list	*tmp;

	tmp = env->begin;
	env->begin = tmp->next;
	env->begin->prev->prev->next = env->begin;
	env->begin->prev = tmp->prev;
	tmp->focus = 0;
	env->begin->focus = 1;
	free(tmp->str);
	free(tmp);
	env->size = env->size - 1;
	return (env->begin);
}

t_list		*dlt_other_maillon(t_select *env)
{
	t_list	*tmp;
	t_list	*save;
	t_list	*tamp;

	tmp = env->begin;
	save = tmp;
	while (tmp->focus != 1)
		tmp = tmp->next;
	tmp->prev->next = tmp->next;
	tmp->next->prev = tmp->prev;
	tmp->focus = 0;
	tmp->next->focus = 1;
	tamp = tmp;
	while (tamp != save)
		tamp = tamp->next;
	env->begin = tamp;
	free(tmp->str);
	free(tmp);
	env->size = env->size - 1;
	return (env->begin);
}
