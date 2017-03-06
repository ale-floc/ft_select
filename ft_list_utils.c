/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-floc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 23:43:09 by ale-floc          #+#    #+#             */
/*   Updated: 2016/04/18 23:43:25 by ale-floc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		ft_listlen(t_list *list, t_list *temp)
{
	int	nb;

	nb = 1;
	while (list != temp)
	{
		list = list->next;
		nb++;
	}
	return (nb);
}
