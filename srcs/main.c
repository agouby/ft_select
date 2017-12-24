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

void		*fetch_env(void *data)
{
	static void	*sgt_env = NULL;

	if (data)
		sgt_env = data;
	return (sgt_env);
}

void		*fetch_tmios(void *data)
{
	static void	*sgt_tmios = NULL;

	if (data)
		sgt_tmios = data;
	return (sgt_tmios);
}

int		putchar(int c)
{
	return (write(STDOUT, &c, 1));
}

static int		loop(t_env	*e)
{
	char	*pr;
	struct	winsize	ws;
	t_read	r;
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
		ft_bzero(r.buf, 3);
		fetch_env(e);
		read(STDIN, r.buf, 3);
		get_and_put("cl");
		r.keybind = (int)r.buf[0] + (int)r.buf[1] + (int)r.buf[2];
		if (r.keybind == 4)
			return (0);
		if (IS_PRINTABLE(r.keybind))
		{
			if (!e->bar.buf[0] && r.keybind == SPACE)
				;
			else
			{
				e->bar.buf[e->bar.i] = r.buf[0];
				if ((srch = search(e->args.list, e->bar)))
				{
					e->args.sel = srch;
					e->bar.i++;
				}
				else
					e->bar.buf[e->bar.i] = 0;
			}
		}
		if (!e->bar.buf[0] && r.keybind == SPACE)
		{
			e->args.sel->select = !e->args.sel->select;
			e->args.sel = e->args.sel->next ? e->args.sel->next : e->args.first;
		}
		else if (IS_ARROW(r.keybind))
			motion_arrow(&e->args, r.keybind);
		else if (IS_DELETE(r.keybind))
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
		else if (r.keybind == ESC)
			return (0);
		else if (r.keybind == ENTER)
			return (1);
		pr = tgetstr("cm", NULL);
		tputs(tgoto(pr, 0, 0), 0, putchar);
		resize(0);
		pr = tgetstr("cm", NULL);
		tputs(tgoto(pr, 0, e->bar.pos), 0, putchar);
//		print_bar(e->bar);
	}
}

int		main(int ac, char **av)
{
	struct termios	tmios;
	t_env	e;

	if (ac < 2)
		exit_usage();
	ft_bzero(&e, sizeof(t_env));
	init_window(&tmios);
	init_signals();
	get_args_infos(&e.args, av);
	e.args.sel = e.args.list;
	e.args.last = get_last(e.args.list);
	fetch_env(&e);
	resize(0);
	int ret = loop(&e);
	if (ret == 1)
		print_selected(e.args.list);
	exit_end(0);
	return (EXIT_SUCCESS);
}
