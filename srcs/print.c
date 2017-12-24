/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <agouby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 11:11:03 by agouby            #+#    #+#             */
/*   Updated: 2017/11/29 11:11:04 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	print_selected(t_al *list)
{
	while (list && !list->select)
		list = list->next;
	if (list)
		ft_printf("%s", list->name);
	else
		return ;
	while ((list = list->next))
	{
		if (list->select)
			ft_printf(" %s", list->name);
	}
}

void	write_spaces(int n)
{
	char	str[n];

	ft_memset(str, ' ', n);
	write(STDOUT, str, n);
}

void	print_tab(char **tabe)
{
	while (*tabe)
		ft_printf("%s\n", *tabe++);
}

void	print_index(t_al *list, t_al *sel, int index, int longest)
{
	int i;
	t_al	*arg;

	i = 0;
	while (list && index != i)
	{
		list = list->next;
		i++;
	}
	arg = list;
	if (arg == sel)
		write(STDOUT, UNDERLINE, 4);
	if (arg->select)
		write(STDOUT, SELECT_CLR, LEN_CLR);
	if (arg == sel && arg->select)
		write(STDOUT, COMBI_CLR, LEN_CLR);
	write(STDOUT, arg->name, arg->name_len);
	write(STDOUT, CLEAR_CLR, LEN_CLR);
	write(STDOUT, "\e[0m", 4);
	write_spaces(longest - arg->name_len + 1);
//	if (arg->next)
//		write(STDOUT, " ", 1);
}

void	print_args(t_args args, int nb_lines)
{
	int decal;
	int i;
	int	nb_per_line;
	int mod;
	int j;

//	print_index(args.list, args.sel, 1, args.longest);
	decal = 0;
	i = 0;
	mod = args.nb_args % nb_lines;
	nb_per_line = args.nb_args / nb_lines;
	int lol;

	lol = nb_per_line;
	while (i < nb_lines)
	{
//		ft_printf("%d\n", nb_per_line);
		j = decal;
		nb_per_line = lol;
		while (nb_per_line)
		{
			if (j == 0 && mod)
			{
				++nb_per_line;
				mod = 0;
			}
	//		ft_printf("J = %d\n", j);
			print_index(args.list, args.sel, j, args.longest);
			j += nb_lines;
			--nb_per_line;
		}
		ft_printf("\n");
		++i;
		++decal;
	}
}

void	print_bar(t_bar bar)
{
	char	*pr;

	pr = tgetstr("cm", NULL);
	tputs(tgoto(pr, 0, bar.pos), 0, putchar);
	write(STDOUT, BAR_CLR, LEN_CLR);
	write(STDOUT, bar.buf, bar.i);
	write_spaces(bar.len - bar.i);
	write(STDOUT, CLEAR_CLR, LEN_CLR);
}
