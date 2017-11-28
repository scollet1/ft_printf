
#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <inttypes.h>
# include <wchar.h>

typedef struct		s_data
{
	int				prefix;
	int				zero_pad;
	int				right_pad;
	int				force_sign;
	int				no_sign;
	int				got_width;
	int				got_accuracy;
	unsigned int	width;
	unsigned int	accuracy;
	unsigned int	length;
}					t_data;

typedef ssize_t	(*t_handler)(char**, va_list*, t_data*);
char				*ft_printf_parse_flags(char **format, t_data *data);
char				*ft_printf_parse_width(char **format, va_list *list,
		t_data *data);
char				*ft_printf_parse_accuracy(char **format, va_list *list,
		t_data *data);
char				*ft_printf_parse_length(char **format, t_data *data);
int					ft_printf(const char *format, ...);
int					go_printf(const char *format, va_list *args,
		int length);
intmax_t			ft_printf_get_signed_from_length(va_list *args,
		t_data *data);
ssize_t				ft_printf_handle_wchar(char **format, va_list *args,
		t_data *data);
ssize_t				ft_printf_handle_char(char **format, va_list *args,
		t_data *data);
ssize_t				ft_printf_handle_str(char **format, va_list *args,
		t_data *data);
ssize_t				ft_printf_handle_wstr(char **format, va_list *args,
		t_data *data);
ssize_t				ft_printf_handle_long(char **format, va_list *args,
		t_data *data);
ssize_t				ft_printf_handle_long_bis(char **format, va_list *args,
		t_data *data);
ssize_t				ft_printf_handle_int(char **format, va_list *args,
		t_data *data);
ssize_t				ft_printf_handle_octal(char **format, va_list *args,
		t_data *data);
ssize_t				ft_printf_handle_hexa(char **format, va_list *args,
		t_data *data);
ssize_t				ft_printf_handle_ptr(char **format, va_list *args,
		t_data *data);
ssize_t				ft_printf_handle_percent(char **format, va_list *args,
		t_data *data);
ssize_t				ft_printf_handle_null(char **format, va_list *args,
		t_data *data);
ssize_t				ft_printf_nbrforceprefix(uintmax_t nbr, char *base,
		t_data *data, char *prefix);
ssize_t				ft_printfu(uintmax_t nbr, t_data *data, char *base,
		char *prefix);
typedef ssize_t		(*t_handler)(char**, va_list*, t_data*);
t_handler			ft_printf_get_handler(char c);
uintmax_t			ft_printf_get_unsigned_from_length(va_list *datas,
		t_data *data);
unsigned int		ft_printf_maxstrlen(uintmax_t nbr, char *base, char *p,
		t_data *data);
unsigned int		ft_printf_nbrlen(uintmax_t nbr, char *base);
void				ft_printf_width_pad(int nbrstrlen, int width,
		char padwith);
#endif
