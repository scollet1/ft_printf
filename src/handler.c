/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 16:45:37 by scollet           #+#    #+#             */
/*   Updated: 2017/11/28 16:45:38 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

static void		init_handlers(t_handler *handler)
{
	handler['%'] = &ft_printf_handle_percent;
	handler['s'] = &ft_printf_handle_str;
	handler['S'] = &ft_printf_handle_wstr;
	handler['d'] = &ft_printf_handle_int;
	handler['D'] = &ft_printf_handle_long;
	handler['i'] = &ft_printf_handle_int;
	handler['o'] = &ft_printf_handle_octal;
	handler['O'] = &ft_printf_handle_long;
	handler['u'] = &ft_printf_handle_long_bis;
	handler['U'] = &ft_printf_handle_long;
	handler['x'] = &ft_printf_handle_hexa;
	handler['X'] = &ft_printf_handle_hexa;
	handler['p'] = &ft_printf_handle_ptr;
	handler['c'] = &ft_printf_handle_char;
	handler['C'] = &ft_printf_handle_wchar;
}

t_handler		ft_printf_get_handler(char c)
{
	static t_handler	*handlers = NULL;

	if (!handlers)
	{
		handlers = (t_handler*)ft_memalloc(sizeof(t_handler) * 256);
		if (handlers)
			init_handlers(handlers);
	}
	return (handlers[(int)c]);
}
