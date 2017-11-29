/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <agouby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 11:10:45 by agouby            #+#    #+#             */
/*   Updated: 2017/11/29 11:10:46 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_select.h"

int		putchar(int c)
{
	return (write(STDOUT, &c, 1));
}

static int		loop(t_env	*e)
{
	char	buf[3];
	char	*pr;
	struct	winsize	ws;
	t_al	*srch;

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
		get_and_put("cl");
		if (buf[0] == 4)
			return (0);
		if (IS_PRINTABLE(buf[0]))
		{
			if (!e->bar.buf[0] && buf[0] == SPACE)
				;
			else
			{
				e->bar.buf[e->bar.i] = buf[0];
				if ((srch = search(e->args.list, e->bar)))
				{
					e->args.sel = srch;
					e->bar.i++;
				}
				else
					e->bar.buf[e->bar.i] = 0;
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
			{
				e->bar.buf[--e->bar.i] = '\0';
				if ((srch = search(e->args.list, e->bar)))
					e->args.sel = srch;
			}
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
		tputs(tgoto(pr, 0, 0), 0, putchar);
		print_args(e->args.list, e->args.sel, e->args.longest);
		pr = tgetstr("cm", NULL);
		tputs(tgoto(pr, 0, e->bar.pos), 0, putchar);
		print_bar(e->bar);
	}
}

int		main(int ac, char **av)
{
	struct termios	tmios;
	char	*term;
	char	*prout;
	t_env	e;

	if (ac < 2)
		exit_usage();
	ft_bzero(&e, sizeof(t_env));
	tgetent(NULL, getenv(TERM_VAR));
	init_window(&tmios);
	get_args_infos(&e.args, av);
	e.args.sel = e.args.list;
	e.args.last = get_last(e.args.list);
	print_args(e.args.list, e.args.list, e.args.longest);
	int ret = loop(&e);
	get_and_put("cl");
	get_and_put("ve");
	restore_termios(&tmios);
	if (ret == 1)
		print_selected(e.args.list);
	return (EXIT_SUCCESS);
}
