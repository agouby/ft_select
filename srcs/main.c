/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <agouby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 02:45:33 by agouby            #+#    #+#             */
/*   Updated: 2017/11/27 01:18:48 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		putc(int c)
{
	return (write(STDOUT, &c, 1));
}

static int		loop(t_env	*e)
{
	char	buf[3];
	char	*pr;
	struct	winsize	ws;

	if (ioctl(STDIN, TIOCGWINSZ, &ws) == -1)
		return (EXIT_FAILURE);
	e->bar.pos = ws.ws_row;
	e->bar.len = ws.ws_col;
	if (!(e->bar.buf = ft_strnew(e->bar.len)))
		ft_memerr();
	print_bar(e->bar);
	while (1)
	{
		if (ioctl(STDIN, TIOCGWINSZ, &ws) == -1)
			return (EXIT_FAILURE);
		e->bar.pos = ws.ws_row;
		e->bar.len = ws.ws_col;
		ft_bzero(buf, 3);
		read(STDIN, buf, 3);
		pr = tgetstr("cl", NULL);
		tputs(pr, 0, putc);
		if (buf[0] == 4)
			return (0);
		if (IS_PRINTABLE(buf[0]))
		{
			if (!e->bar.buf[0] && buf[0] == SPACE)
				;
			else
			{
				e->bar.buf[e->bar.i] = buf[0];
				e->bar.i++;
			}
		}
		if (!e->bar.buf[0] && buf[0] == SPACE)
		{
			e->args.sel->select = !e->args.sel->select;
			e->args.sel = e->args.sel->next ? e->args.sel->next : e->args.first;
		}
		else if (IS_ARROW(buf[0], buf[1]))
			motion_arrow(&e->args, buf[2]);
		else if (IS_DELETE(buf[0]))
		{
			if (e->bar.buf[0] != '\0')
				e->bar.buf[--e->bar.i] = '\0';
			else
			{
				if (delete_arg(&e->args) == -1)
					return (0);
				recalc_args(&e->args);
			}
		}
		else if (buf[0] == ESC)
			return (0);
		else if (buf[0] == ENTER)
			return (1);
		pr = tgetstr("cm", NULL);
		tputs(tgoto(pr, 0, 0), 0, putc);
		print_args(e->args.list, e->args.sel, e->args.longest);
		pr = tgetstr("cm", NULL);
		tputs(tgoto(pr, 0, e->bar.pos), 0, putc);
		print_bar(e->bar);
	}
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
	tputs(prout, 0, &putc);
	prout = tgetstr("vi", NULL);
	tputs(prout, 0, &putc);
	get_args_infos(&e.args, av);
	e.args.sel = e.args.list;
	e.args.last = get_last(e.args.list);
	print_args(e.args.list, e.args.list, e.args.longest);
	int ret = loop(&e);
	prout = tgetstr("cl", NULL);
	tputs(prout, 0, &putc);
	prout = tgetstr("ve", NULL);
	tputs(prout, 0, &putc);
	if (ret == 1)
		print_selected(e.args.list);
	restore_termios(&tmios);
	return (EXIT_SUCCESS);
}
