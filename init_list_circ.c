/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list_circ.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-floc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 23:04:20 by ale-floc          #+#    #+#             */
/*   Updated: 2016/04/18 23:04:32 by ale-floc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_list		*ft_listpush(char *str, t_list *list)
{
	t_list	*tmp;

	tmp = list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = init_one_list(str, tmp);
	return (list);
}

t_list		*list_circulaire_init(t_list *list, t_select *env)
{
	t_list	*tmp;
	t_list	*temp;
	t_list	*listmp;

	tmp = list;
	temp = list;
	listmp = list;
	while (temp->next)
		temp = temp->next;
	tmp->prev = temp;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = listmp;
	env->end = temp;
	env->size = ft_listlen(list, env->end);
	return (tmp);
}

t_list		*init_one_list(char *str, t_list *tmp)
{
	t_list	*temp;

	temp = (t_list *)malloc(sizeof(t_list));
	temp->next = NULL;
	temp->prev = (tmp) ? tmp : NULL;
	temp->focus = (tmp) ? 0 : 1;
	temp->str = ft_strdup(str);
	temp->size_str = ft_strlen(str);
	temp->select = 0;
	return (temp);
}

void		init_list(char **argv, t_select *env)
{
	int		i;
	t_list	*tmp;

	i = 1;
	tmp = init_one_list(argv[i], NULL);
	i++;
	while (argv[i])
	{
		tmp = ft_listpush(argv[i], tmp);
		i++;
	}
	list_circulaire_init(tmp, get_select());
	env->begin = tmp;
}
