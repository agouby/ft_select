/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <agouby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 10:25:49 by agouby            #+#    #+#             */
/*   Updated: 2017/11/25 10:29:42 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		get_longest_arg(t_al *list)
{
	int		big;
	int		len;

	big = 0;
	while (list)
	{
		len = ft_strlen(list->name);
		if (big < len)
			big = len;
		list = list->next;
	}
	return (big);
}
