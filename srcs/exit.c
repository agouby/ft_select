/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <agouby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 11:10:04 by agouby            #+#    #+#             */
/*   Updated: 2018/01/02 19:14:21 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	exit_usage(void)
{
	ft_dprintf(STDERR, "usage: ft_select [...]\n");
	exit(STDERR);
}

void	exit_end(int signal)
{
	struct termios	*tmios;
	t_env			*e;

	tmios = fetch_tmios(NULL);
	e = fetch_env(NULL);
	get_and_put("ve");
	restore_termios(tmios);
	ft_strdel(&e->bar.buf);
	exit(signal);
}
