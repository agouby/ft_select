/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <agouby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 03:19:18 by agouby            #+#    #+#             */
/*   Updated: 2017/11/25 12:12:29 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	get_args_infos(t_args *args, int ac, char **av)
{
	av++;
	args->nb_args = ac - 1;
	while (*av)
	{
		al_addb(&args->list, al_new(*av));
		av++;
	}
	args->first = args->list;
	args->longest = get_longest_arg(args->list);
}
