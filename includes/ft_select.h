/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <agouby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 02:44:53 by agouby            #+#    #+#             */
/*   Updated: 2017/11/25 12:16:08 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include "ft_printf.h"
# include <fcntl.h>
# include <term.h>
# include <termios.h>
# include <sys/ioctl.h>

# define	STDIN		0
# define	STDOUT		1
# define	STDERR		2

# define	TERM_VAR	"TERM"

typedef struct	s_al
{
	char		*name;
	int			name_len;
	int			select;
	struct s_al	*next;
}				t_al;

typedef struct	s_args
{
	t_al	*list;
	t_al	*sel;
	t_al	*first;
	int		nb_args;
	int		longest;
}				t_args;

typedef struct	s_env
{
	t_args	args;
	struct winsize	ws;
}				t_env;

int		init_termios(struct termios *tmios);
int		restore_termios(struct termios *tmios);

void	get_args_infos(t_args *args, int ac, char **av);
void	print_args(t_al *args, t_al *sel, int longest);

t_al	*al_new(char *name);
void	al_addb(t_al **old, t_al *n);

void	exit_usage(void);

int		get_longest_arg(t_al *list);

#endif
