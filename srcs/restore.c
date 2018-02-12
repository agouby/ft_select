/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restore.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <agouby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 11:11:12 by agouby            #+#    #+#             */
/*   Updated: 2018/02/12 14:24:20 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		restore_termios(void)
{
	struct termios	*tmios;

	tmios = old_tmios(NULL);
	return (tcsetattr(STDIN, TCSANOW, tmios));
}

void	recalc_args(t_args *args)
{
	args->first = args->list;
	args->longest = get_longest_arg(args->list);
	args->last = get_last(args->list);
}
