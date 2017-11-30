/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 16:45:01 by scollet           #+#    #+#             */
/*   Updated: 2017/11/28 16:45:03 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//void	ft_putnbrbase(int n, int base)
//{
//	ft_putstr(ft_itoa_base(n, base));
	// if (n == -2147483648)
	// {
	// 	ft_putstr("-2147483648");
	// 	return ;
	// }
	// if (n < 0)
	// {
	// 	ft_putchar('-');
	// 	n = -n;
	// }
	// if (n >= base)
	// {
	// 	ft_putnbr(n / 10);
	// 	ft_putnbr(n % base);
	// }
	// else
	// 	ft_putchar(n + '0');
//}

static void	ft_putnbrbase_inner(uintmax_t nbr, char *base, t_data *data,
		unsigned int len)
{
	if (data->got_accuracy)
		ft_printf_width_pad(len, data->accuracy, base[0]);
	if (nbr != 0 || !data->got_accuracy || data->accuracy != 0)
		ft_putnbrbase(nbr, base);
}

ssize_t		ft_printfu(uintmax_t nbr, t_data *data, char *base, char *prefix)
{
	unsigned int			len;
	unsigned int			strlen;

	if (data->got_accuracy)
		data->zero_pad = 0;
	len = ft_printf_nbrlen(nbr, base);
	if (data->got_width && !data->right_pad && data->zero_pad)
	{
		data->accuracy = ft_minmax(1, data->width, data->got_accuracy ?
			data->accuracy : len);
		data->got_accuracy = 1;
		data->got_width = 0;
	}
	strlen = ft_printf_maxstrlen(nbr, base, prefix, data);
	if (data->got_width && !data->right_pad)
		ft_printf_width_pad(strlen, data->width, ' ');
	if (data->prefix && prefix && nbr)
		ft_putstr(prefix);
	ft_putnbrbase_inner(nbr, base, data, len);
	if (data->got_width && data->right_pad)
		ft_printf_width_pad(strlen, data->width, ' ');
	return (data->got_width ? (ft_minmax(1, strlen, data->width)) : strlen);
}
