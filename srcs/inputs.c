/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <agouby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 11:10:28 by agouby            #+#    #+#             */
/*   Updated: 2017/11/29 11:10:28 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	motion_arrow(t_args *args, char arrow)
{
	if (al_len(args->list) == 1)
		return ;
	if (arrow == ARROW_R)
		args->sel = (!args->sel->next) ? args->first : args->sel->next;
	else if (arrow == ARROW_L)
		args->sel = (!args->sel->prev) ? args->last : args->sel->prev;
}
