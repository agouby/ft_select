/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <agouby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 03:07:58 by agouby            #+#    #+#             */
/*   Updated: 2017/11/25 11:06:06 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_al	*al_new(char *name)
{
	t_al	*new;

	if (!(new = (t_al *)malloc(sizeof(t_al))))
		ft_memerr();
	new->name = name;
	new->name_len = ft_strlen(name);
	new->next = NULL;
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
	}
}
