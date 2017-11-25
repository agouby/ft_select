/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <agouby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 03:02:46 by agouby            #+#    #+#             */
/*   Updated: 2017/11/25 12:16:10 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	print_args(t_al *args, t_al *sel, int longest)
{
	while (args)
	{
		if (args == sel)
			write(STDOUT, "\e[101m", 6);
		ft_printf("%-*s", longest + 1, args->name);
		write(STDOUT, "\e[0m", 5);
		args = args->next;
	}
}
