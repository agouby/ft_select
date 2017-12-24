/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <agouby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 02:44:53 by agouby            #+#    #+#             */
/*   Updated: 2017/11/29 11:11:55 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include "ft_printf.h"
# include <fcntl.h>
# include <term.h>
# include <termios.h>
# include <signal.h>
# include <sys/ioctl.h>

# define STDIN				0
# define STDOUT				1
# define STDERR				2

# define TERM_VAR			"TERM"

# define IS_ARROW(X) 		(X > 182  && X < 187)
# define IS_DELETE(X)		(X == DELETE || X == BK_SPACE)
# define IS_PRINTABLE(X)	(X >= SPACE && X <= 125)

# define ARROW_R			185
# define ARROW_L			186
# define ARROW_U			183
# define ARROW_D			184
# define DELETE				126
# define BK_SPACE			127
# define SPACE				32
# define ENTER				10
# define ESC				27

# define CURSOR_CLR			"\e[101m"
# define SELECT_CLR			"\e[42m"
# define CLEAR_CLR			"\e[49m"
# define COMBI_CLR			"\e[105m"
# define UNDERLINE			"\e[4m"
# define BAR_CLR			"\e[100m"
# define LEN_CLR			6

typedef struct	s_al
{
	char		*name;
	int			name_len;
	int			select;
	struct s_al	*next;
	struct s_al *prev;
}				t_al;

typedef struct	s_args
{
	t_al	*list;
	t_al	*sel;
	t_al	*first;
	t_al	*last;
	int		nb_args;
	int		longest;
}				t_args;

typedef	struct	s_bar
{
	int		pos;
	int		len;
	int		i;
	char	*buf;
}				t_bar;

typedef struct	s_read
{
	int	keybind;
	char	buf[3];
}		t_read;

typedef struct	s_env
{
	t_args			args;
	t_bar			bar;
}				t_env;

int				init_termios(struct termios *tmios);
int				restore_termios(struct termios *tmios);

void			get_args_infos(t_args *args, char **av);
void			print_args(t_args args, int nb_lines);

t_al			*al_new(char *name);
void			al_addb(t_al **old, t_al *n);

void			exit_usage(void);

int				get_longest_arg(t_al *list);

int				putchar(int c);

void			motion_arrow(t_args *args, int arrow);

t_al			*get_last(t_al *list);

int				delete_arg(t_args *args);

void			recalc_args(t_args *args);

size_t			al_len(t_al *list);

void			print_selected(t_al *list);

void			print_bar(t_bar bar);

t_al			*search(t_al *list, t_bar bar);

void			get_and_put(char *cmd);

int				init_window(struct termios *tmios);

void			init_signals(void);

void			*fetch_tmios(void *data);
void			*fetch_env(void *data);

void			exit_end(int signal);

void			resize(int signal);

#endif
