
#include "../includes/ft_printf.h"

void	ft_display(PF *argument)
{
	argument->ret += write(FD, &g_buff, g_i);
	ft_init_buff();
}

void	ft_buf(char c, PF *argument)
{
	g_buff[g_i] = c;
	g_i++;
	if (g_i == BUFF_MAX)
		ft_display(argument);
}

void	*ft_buff(char *str, PF *argument)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		ft_buf(str[i++], argument);
	return (NULL);
}
