/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restore.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <agouby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 00:35:45 by agouby            #+#    #+#             */
/*   Updated: 2017/11/25 23:34:48 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		restore_termios(struct termios *tmios)
{
	tmios->c_lflag = (ICANON | ECHO);
	return (tcsetattr(STDIN, TCSANOW, tmios));	
}

void	recalc_args(t_args *args)
{
	args->first = args->list;
	args->longest = get_longest_arg(args->list);
	args->last = get_last(args->list);
}
