/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <agouby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 17:48:29 by agouby            #+#    #+#             */
/*   Updated: 2018/02/12 18:09:24 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	key_is_space(t_env *e)
{
	e->args.sel->select = !e->args.sel->select;
	e->args.sel = e->args.sel->next ? e->args.sel->next : e->args.first;
}

int		key_is_delete(t_env *e)
{
	t_al *srch;

	if (e->bar.buf[0] != '\0')
	{
		e->bar.buf[--e->bar.i] = '\0';
		if ((srch = search(e->args.list, e->bar)))
			e->args.sel = srch;
	}
	else
	{
		if (delete_arg(&e->args) == -1)
			return (1);
		recalc_args(&e->args);
	}
	return (0);
}

void	key_is_printable(t_env *e, t_read r)
{
	struct winsize	w;
	t_al			*srch;

	if (ioctl(STDIN, TIOCGWINSZ, &w) == -1)
		exit_end(1);
	if (e->bar.i >= w.ws_col || (!e->bar.buf[0] && r.keybind == SPACE))
		return ;
	e->bar.buf[e->bar.i] = r.buf[0];
	if ((srch = search(e->args.list, e->bar)))
	{
		e->args.sel = srch;
		e->bar.i++;
	}
	else
		e->bar.buf[e->bar.i] = 0;
}
