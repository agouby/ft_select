#include "ft_select.h"

int	get_nb_lines(int col, int len_args, int longest)
{
	int	ln;
	int	full_len;
	int	l;

	ln = 1;
	if (len_args % 2)
		len_args++;
	full_len = len_args * longest + len_args;
	l = full_len;
	while (col <= l && ++ln)
		l = full_len / ln;
	if (l < longest)
		return (0);
	if (ln > len_args / 2)
		return (len_args);
	return (ln);
}

void	resize(int signal)
{
	struct winsize	w;
	t_env		*e;
	int		nb_lines;

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
//	if (e->bar.len < w.ws_col)
		print_bar(e->bar);
}

void	init_signals(void)
{
	signal(SIGINT, &exit_end);
	signal(SIGSEGV, &exit_end);
	signal(SIGWINCH, &resize);
}
