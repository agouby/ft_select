/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <agouby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 11:10:18 by agouby            #+#    #+#             */
/*   Updated: 2018/02/12 14:23:05 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		init_termios(struct termios *tmios)
{
	if ((tcgetattr(STDIN, tmios)) == -1)
		return (-1);
	old_tmios(tmios);
	tmios->c_lflag &= ~(ECHO);
	tmios->c_lflag &= ~(ICANON);
	return (tcsetattr(STDIN, TCSANOW, tmios));
}

int		init_window(struct termios *tmios)
{
	tgetent(NULL, getenv(TERM_VAR));
	if ((init_termios(tmios)) == -1)
		exit(EXIT_FAILURE);
	fetch_tmios(tmios);
	get_and_put("cl");
	get_and_put("vi");
	return (0);
}
