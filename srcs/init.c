/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <agouby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 00:18:34 by agouby            #+#    #+#             */
/*   Updated: 2017/11/23 01:03:36 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		prepare_termios(struct termios *tmios)
{
	if ((tcgetattr(0, tmios)) == -1)
		return (-1);
	tmios->c_iflag &= ~(ICANON);
	tmios->c_lflag &= ~(ECHO);
	return (tcsetattr(0, TCSADRAIN, tmios));
}
