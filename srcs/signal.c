/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <agouby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 19:13:03 by agouby            #+#    #+#             */
/*   Updated: 2018/01/02 19:13:47 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		get_nb_lines(int col, int len_args, int longest)
{
	int	ln;
	int	full_len;

	if (col < ++longest)
		return (0);
	full_len = len_args * longest;
	if (full_len < longest)
		return (0);
	if (full_len <= col)
		return (1);
	ln = longest;
	int cnt = 0;
	while (1)
	{
		if (ln > col)
			break;
		ln += longest;
		cnt++;
	}
	ln = len_args / cnt + 1;
//	ln = (len_args + 1) / ln;
//	while (ln < len_args && ((len_args + 1) / ln) * longest >= col)
//		ln++;
/*	if (len_args % 2)
		while (col - (len_args / ln + len_args % 2) * longest < 0)
			ln++;
	else
		while (col - (len_args / ln + ((((len_args + 1) / ln) % ln) ? 1 : 0)) * longest < 0)
			ln++;
*/	return (ln);
}

void	resize(int signal)
{
	struct winsize	w;
	t_env			*e;
	int				nb_lines;

	(void)signal;
	tputs(tgoto(tgetstr("cm", NULL), 0, 0), 0, putchar);
	if (ioctl(STDIN, TIOCGWINSZ, &w) == -1)
		exit(1);
	e = fetch_env(NULL);
	e->bar.pos = w.ws_row;
	e->bar.len = w.ws_col;
	e->args.nb_args = al_len(e->args.list);
	get_and_put("cl");
	nb_lines = get_nb_lines(w.ws_col, e->args.nb_args, e->args.longest);
	print_args(e->args, nb_lines);
	tputs(tgoto(tgetstr("cm", NULL), 0, e->bar.pos), 0, putchar);
	print_bar(e->bar);
}

void	init_signals(void)
{
	signal(SIGINT, &exit_end);
	signal(SIGSEGV, &exit_end);
	signal(SIGWINCH, &resize);
}
