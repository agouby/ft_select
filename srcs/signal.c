#include "ft_select.h"

int fd;

int	get_nb_lines(int col, int len_args, int longest)
{
	int	ln;
	int	mod;
	int	full_len;
	int l;

	ln = 1;
	mod = len_args % 2;
	full_len = len_args * longest + len_args;
	if (mod)
		full_len += longest + 1;
	l = full_len;
	while (col <= l && ++ln)
		l = full_len / ln;
	if (l < longest)
		return (0);
	if (ln > len_args / 2 && !mod)
		return (len_args);
	return (ln);
}

void	resize(int signal)
{
	struct winsize	w;
	t_env		*e;
	int		nb_lines;

	(void)signal;
	if (ioctl(STDIN, TIOCGWINSZ, &w) == -1)
		exit(1);
	e = fetch_env(NULL);
	e->args.nb_args = al_len(e->args.list);
	get_and_put("cl");
	nb_lines = get_nb_lines(w.ws_col, e->args.nb_args, e->args.longest);
	print_args(e->args, nb_lines);
}

void	init_signals(void)
{
	fd = open("lol", O_RDWR);
	signal(SIGINT, &exit_end);
	signal(SIGSEGV, &exit_end);
	signal(SIGWINCH, &resize);
}
