
#include "ft_printf.h"

int             handle_args(char **format, va_list *args, t_data *data)
{
        int                     ret;
        t_handler       f;

        if (!(*(++*format)))
                return (0);
        if (!(ft_printf_parse_flags(format, data)) ||
                        !(ft_printf_parse_width(format, args, data)) ||
                        !(ft_printf_parse_accuracy(format, args, data)) ||
                        !(ft_printf_parse_length(format, data)))
                return (-1);
        if (!**format)
                return (0);
        if (!(f = ft_printf_get_handler(**format)))
                f = &ft_printf_handle_null;
        ret = f(format, args, data);
        (*format)++;
        return (ret);
}

int             go_printf(const char *format, va_list *args, int length)
{
        char	*next;
        t_data	this_data;
        int             len;

        len = 0;
        next = ft_strchr(format, '%');
        if (!*format)
                return (length);
        if (!next)
                return (length + write(1, format, ft_strlen(format)));
        else if (next > format)
                return (go_printf(next, args, length + write(1, format,
                                                next - format)));
        else
        {
                ft_bzero(&this_data, sizeof(this_data));
                if ((len = handle_args((char**)&format, args, &this_data)) == -1)
                        return (-1);
                return (go_printf(format, args, length + len));
	}
	return (-1);
}

int			ft_printf(const char *format, ...)
{
	va_list		args;
	int		result;

	va_start(args, format);
	result = go_printf(format, &args, 0);
	va_end(args);
	return (result);
}
