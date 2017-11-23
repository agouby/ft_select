/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restore.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <agouby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 00:35:45 by agouby            #+#    #+#             */
/*   Updated: 2017/11/23 00:39:24 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		restore_termios(struct termios *tmios)
{
	tmios->c_lflag = (ICANON | ECHO);
	return (tcsetattr(0, 0, tmios));	
}
