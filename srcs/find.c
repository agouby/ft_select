/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <agouby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 11:09:53 by agouby            #+#    #+#             */
/*   Updated: 2017/11/29 11:12:32 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_al	*search(t_al *list, t_bar bar)
{
	int	len;

	len = ft_strlen(bar.buf);
	while (list)
	{
		if (!ft_strncmp(list->name, bar.buf, len))
			return (list);
		list = list->next;
	}
	return (NULL);
}
