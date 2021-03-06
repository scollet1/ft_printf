/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 16:45:24 by scollet           #+#    #+#             */
/*   Updated: 2017/11/28 16:45:25 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putwchar_fd(wchar_t chr, int fd)
{
	if (chr <= 0x7F)
		ft_putchar_fd(chr, fd);
	else if (chr <= 0x7FF)
	{
		ft_putchar_fd((chr >> 6) + 0xC0, fd);
		ft_putchar_fd((chr & 0x3F) + 0x80, fd);
	}
	else if (chr <= 0xFFFF)
	{
		ft_putchar_fd((chr >> 12) + 0xE0, fd);
		ft_putchar_fd(((chr >> 6) & 0x3F) + 0x80, fd);
		ft_putchar_fd((chr & 0x3F) + 0x80, fd);
	}
	else if (chr <= 0x10FFFF)
	{
		ft_putchar_fd((chr >> 18) + 0xF0, fd);
		ft_putchar_fd(((chr >> 12) & 0x3F) + 0x80, fd);
		ft_putchar_fd(((chr >> 6) & 0x3F) + 0x80, fd);
		ft_putchar_fd((chr & 0x3F) + 0x80, fd);
	}
}

void	ft_putwchar(wchar_t chr)
{
	ft_putwchar_fd(chr, STDOUT_FILENO);
}

// void ft_putwchar(wchar_t chr)
// {
// 	if (chr <= 0x7F)
// 		ft_putchar(chr);
// 	else if (chr <= 0x7FF)
// 	{
// 		ft_putchar((chr >> 6) + 0xC0);
// 		ft_putchar((chr & 0x3F) + 0x80);
// 	}
// 	else if (chr <= 0xFFFF)
// 	{
// 		ft_putchar((chr >> 12) + 0xE0);
// 		ft_putchar(((chr >> 6) & 0x3F) + 0x80);
// 		ft_putchar((chr & 0x3F) + 0x80);
// 	}
// 	else if (chr <= 0x10FFFF)
// 	{
// 		ft_putchar((chr >> 18) + 0xF0);
// 		ft_putchar(((chr >> 12) & 0x3F) + 0x80);
// 		ft_putchar(((chr >> 6) & 0x3F) + 0x80);
// 		ft_putchar((chr & 0x3F) + 0x80);
// 	}
// }

ssize_t	ft_printf_handle_char(char **format, va_list *args, t_data *data)
{
	(void)format;
	if (data->length == 2)
		return (ft_printf_handle_wchar(format, args, data));
	else
	{
		if (data->got_width && !data->right_pad)
			ft_printf_width_pad(1, data->width, data->zero_pad ? '0' : ' ');
		ft_putchar(va_arg(*args, int));
		if (data->got_width && data->right_pad)
			ft_printf_width_pad(1, data->width, ' ');
		return (data->got_width ? ft_minmax(1, data->width, 1) : 1);
	}
}

ssize_t	ft_printf_handle_str(char **format, va_list *args, t_data *data)
{
	char	*str;
	size_t	strlen;

	if (data->length == 2)
		return (ft_printf_handle_wstr(format, args, data));
	else
	{
		str = va_arg(*args, char*);
		if (!str)
			str = "(null)";
		strlen = data->got_accuracy ? (size_t)(ft_minmax(0, ft_strlen(str),
					data->accuracy)) : ft_strlen(str);
		if (data->got_width && !data->right_pad)
			ft_printf_width_pad(strlen, data->width, data->zero_pad ?
					'0' : ' ');
		write(1, str, strlen);
		if (data->got_width && data->right_pad)
			ft_printf_width_pad(strlen, data->width, ' ');
		// if (data->got_width)
		return ((data->got_width) ? ft_minmax(1, strlen, data->width) :
			strlen);
			// return (strlen > data->width)? strlen: d
	}
	return (ft_strlen(str));
}
