/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 16:44:45 by scollet           #+#    #+#             */
/*   Updated: 2017/11/28 16:44:47 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

unsigned int	ft_printf_nbrlen(uintmax_t nbr, char *base)
{
	size_t			base_nbr;
	unsigned int	i;

	base_nbr = ft_strlen(base);
	i = 0;
	if (!nbr)
		return (1);
	while (nbr && ++i)
		nbr /= base_nbr;
	return (i);
}
