
#include "ft_printf.h"

static void	ft_putnbrbase_inter(uintmax_t nbr, char *base, t_data *data,
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
		data->accuracy = ft_max(data->width, data->got_accuracy ?
				data->accuracy : len);
		data->got_accuracy = 1;
		data->got_width = 0;
	}
	strlen = ft_printf_maxstrlen(nbr, base, prefix, data);
	if (data->got_width && !data->right_pad)
		ft_printf_width_pad(strlen, data->width, ' ');
	if (data->prefix && prefix && nbr)
		ft_putstr(prefix);
	ft_putnbrbase_inter(nbr, base, data, len);
	if (data->got_width && data->right_pad)
		ft_printf_width_pad(strlen, data->width, ' ');
	return (data->got_width ? (ft_max(strlen, data->width)) : strlen);
}
