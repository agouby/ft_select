/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <agouby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 03:19:18 by agouby            #+#    #+#             */
/*   Updated: 2017/11/25 23:21:27 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	get_args_infos(t_args *args, char **av)
{
	av++;
	while (*av)
	{
		al_addb(&args->list, al_new(*av));
		av++;
	}
	args->first = args->list;
	args->longest = get_longest_arg(args->list);
}
