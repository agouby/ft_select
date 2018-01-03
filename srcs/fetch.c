/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fetch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <agouby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 19:46:08 by agouby            #+#    #+#             */
/*   Updated: 2018/01/03 19:46:36 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		*fetch_env(void *data)
{
	static void	*sgt_env = NULL;

	if (data)
		sgt_env = data;
	return (sgt_env);
}

void		*fetch_tmios(void *data)
{
	static void	*sgt_tmios = NULL;

	if (data)
		sgt_tmios = data;
	return (sgt_tmios);
}
