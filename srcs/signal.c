#include "ft_select.h"

int	get_nb_lines(int col, int len_args, int longest)
{
	int	ln;
	int	mod;
	int	full_len;

	ln = 1;
	while (1)
	{
		full_len = len_args * longest;
		if (col > full_len)
			return (ln);
		mod = len_args % 2;
		len_args = len_args / 2 + mod;
		ln++;
	}
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
	if (!e->args.list)
		ft_printf("wanna cry");
	e->args.nb_args = al_len(e->args.list);
	nb_lines = get_nb_lines(w.ws_col, e->args.nb_args, e->args.longest);
	get_and_put("cl");
	print_args(e->args, nb_lines);
}

void	init_signals(void)
{
	signal(SIGINT, &exit_end);
//	signal(SIGSEGV, &exit_end);
	signal(SIGWINCH, &resize);
}
