/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <agouby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 02:45:33 by agouby            #+#    #+#             */
/*   Updated: 2017/11/25 12:13:22 by agouby           ###   ########.fr       */
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
	t_env	e;

	if (ac < 2)
		exit_usage();
	ft_bzero(&e, sizeof(t_env));
	term = getenv(TERM_VAR);
	tgetent(NULL, term);
	if ((init_termios(&tmios)) == -1)
		return (EXIT_FAILURE);
	prout = tgetstr("cl", NULL);
	tputs(prout, 0, &pc);
	prout = tgetstr("vi", NULL);
	tputs(prout, 0, &pc);
	get_args_infos(&e.args, ac, av);
	e.args.sel = e.args.list;
	print_args(e.args.list, e.args.list, e.args.longest);
	ioctl(STDIN, TIOCGWINSZ, &e.ws);
	char	buf[3];

	while (1)
	{
		if (ioctl(STDIN, TIOCGWINSZ, &e.ws) == -1)
			return (EXIT_FAILURE);
		read(STDIN, buf, 3);
		if (buf[0] == 27 && buf[1] == 91 && buf[2] == 67)
		{
			prout = tgetstr("cl", NULL);
			tputs(prout, 0, &pc);
			e.args.sel = e.args.sel->next;
			if (e.args.sel == NULL)
				e.args.sel = e.args.first;
			print_args(e.args.list, e.args.sel, e.args.longest);
		}
		if (*buf == 4)
			break ;
	}
	prout = tgetstr("ve", NULL);
	tputs(prout, 0, &pc);
	restore_termios(&tmios);
	return (EXIT_SUCCESS);
}
