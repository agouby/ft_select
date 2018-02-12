/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <agouby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 11:10:45 by agouby            #+#    #+#             */
/*   Updated: 2018/02/12 18:12:12 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static int		read_keys(t_env *e, t_read r)
{
	if (r.keybind == 4)
		return (1);
	if (IS_PRINTABLE(r.keybind))
		key_is_printable(e, r);
	if (!e->bar.buf[0] && r.keybind == SPACE)
		key_is_space(e);
	else if (IS_ARROW(r.keybind))
		motion_arrow(&e->args, r.keybind);
	else if (IS_DELETE(r.keybind))
	{
		if (key_is_delete(e))
			return (1);
	}
	else if (r.keybind == ESC)
		return (1);
	else if (r.keybind == ENTER)
		return (2);
	return (0);
}

static int		loop(t_env *e)
{
	char	*pr;
	t_read	r;
	int		ret;

	while (1)
	{
		fetch_env(e);
		ft_bzero(r.buf, 3);
		read(STDIN, r.buf, 3);
		get_and_put("cl");
		r.keybind = (int)r.buf[0] + (int)r.buf[1] + (int)r.buf[2];
		if ((ret = read_keys(e, r)))
			return (ret - 1);
		pr = tgetstr("cm", NULL);
		tputs(tgoto(pr, 0, 0), 0, putchar);
		resize(0);
		pr = tgetstr("cm", NULL);
		tputs(tgoto(pr, 0, e->bar.pos), 0, putchar);
	}
}

int				main(int ac, char **av)
{
	struct termios	tmios;
	t_env			e;
	int				ret;

	if (ac < 2)
		exit_usage();
	ft_bzero(&e, sizeof(t_env));
	init_window(&tmios);
	init_signals();
	get_args_infos(&e.args, av);
	e.args.sel = e.args.list;
	e.args.last = get_last(e.args.list);
	if (!(e.bar.buf = ft_strnew(1024)))
		ft_memerr();
	fetch_env(&e);
	resize(0);
	ret = loop(&e);
	if (ret == 1)
		print_selected(e.args.list);
	exit_end(0);
	return (EXIT_SUCCESS);
}
