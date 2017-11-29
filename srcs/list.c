/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <agouby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 11:10:36 by agouby            #+#    #+#             */
/*   Updated: 2017/11/29 11:10:37 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_al	*get_last(t_al *lst)
{
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_al	*al_new(char *name)
{
	t_al	*new;

	if (!(new = (t_al *)malloc(sizeof(t_al))))
		ft_memerr();
	new->name = name;
	new->name_len = ft_strlen(name);
	new->select = 0;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	al_addb(t_al **old, t_al *new)
{
	t_al	*tmp;

	if (!*old)
		*old = new;
	else
	{
		tmp = *old;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->prev = tmp;
	}
}

size_t	al_len(t_al *list)
{
	size_t	n;

	n = 0;
	while (list)
	{
		n++;
		list = list->next;
	}
	return (n);
}
