/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <agouby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 11:10:04 by agouby            #+#    #+#             */
/*   Updated: 2017/11/29 11:10:06 by agouby           ###   ########.fr       */
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

	tmios = fetch_tmios(NULL);
	get_and_put("ve");
	restore_termios(tmios);
	exit(signal);
}
