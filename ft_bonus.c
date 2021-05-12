#include "libft/libft.h"
#include "ft_printf.h"

void	plus_space(t_struct *params)
{
	if (params->plus || params->space)
	{
		if (params->precision > 0 && params->nb >= 0)
			params->len++;
		if (params->nb >= 0 && params->plus)
			ft_putchar_fd('+', 1);
		else if (params->nb >= 0 && params->space)
			ft_putchar_fd(' ', 1);
		if (params->nb >= 0)
			params->ret++;
	}
}
