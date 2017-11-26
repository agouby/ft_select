/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <agouby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 00:18:34 by agouby            #+#    #+#             */
/*   Updated: 2017/11/25 23:21:51 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		init_termios(struct termios *tmios)
{
	if ((tcgetattr(STDIN, tmios)) == -1)
		return (-1);
	tmios->c_lflag &= ~(ECHO);
	tmios->c_lflag &= ~(ICANON);
	return (tcsetattr(STDIN, TCSANOW, tmios));
}
