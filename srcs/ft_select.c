/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <agouby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 02:45:33 by agouby            #+#    #+#             */
/*   Updated: 2017/11/23 01:21:33 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		pc(int c)
{
	return (write(1, &c, 1));
}

int		main(int ac, char **av)
{
	(void)ac;
	(void)av;
	struct termios	tmios;
	char	*term;
	char	*prout;

	term = getenv(TERM_VAR);
	tgetent(NULL, term);
	if ((prepare_termios(&tmios)) == -1)
		return (-1);
	prout = tgetstr("cl", NULL);
	tputs(prout, 0, &pc);
//	prout = tgetstr("vi", NULL);
//	tputs(prout, 0, &pc);
	restore_termios(&tmios);
	while (1);
	return (EXIT_SUCCESS);
}
