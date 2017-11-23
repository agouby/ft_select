/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <agouby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 02:44:53 by agouby            #+#    #+#             */
/*   Updated: 2017/11/23 00:45:13 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include "ft_printf.h"
# include <fcntl.h>
# include <term.h>
# include <termios.h>

# define	STDIN		0
# define	STDOUT		1
# define	STDERR		2

# define	TERM_VAR	"TERM"

int		prepare_termios(struct termios *tmios);
int		restore_termios(struct termios *tmios);

#endif
