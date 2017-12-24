/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <agouby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 11:11:29 by agouby            #+#    #+#             */
/*   Updated: 2017/11/29 11:11:31 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		get_longest_arg(t_al *list)
{
	int		big;

	big = 0;
	while (list)
	{
		if (big < list->name_len)
			big = list->name_len;
		list = list->next;
	}
	return (big);
}

void	get_and_put(char *cmd)
{
	char	*s;

	s = tgetstr(cmd, NULL);
	tputs(s, 0, &putchar);
}
