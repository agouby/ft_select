/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <agouby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 11:09:33 by agouby            #+#    #+#             */
/*   Updated: 2017/11/29 11:12:48 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		delete_arg(t_args *args)
{
	t_al	*tmp;
	t_al	*prev;

	tmp = args->list;
	prev = NULL;
	if (!tmp->next)
		return (-1);
	while (tmp->next && args->sel != tmp && (prev = tmp))
		tmp = tmp->next;
	if (prev)
	{
		args->sel = prev;
		if (tmp->next)
			tmp->next->prev = prev;
		prev->next = tmp->next;
	}
	else
	{
		args->list = args->list->next;
		args->list->prev = NULL;
		args->sel = args->list;
	}
	return (0);
}
