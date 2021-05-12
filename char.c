#include "libft/libft.h"
#include "ft_printf.h"

void	print_c_aux(t_struct *params, char c)
{
	if (!params->minus && params->width >= 0 && !params->zero)
		ft_width(params, (params->width - 1));
	if (params->zero && params->width && !params->minus
		&& params->precision == -1)
		ft_zero(params, (params->width - 1));
	ft_putchar_fd(c, 1);
	if (params->minus || params->width < 0)
		ft_width(params, (params->width - 1));
	params->ret++;
}

void	print_c(va_list ap, t_struct *params)
{
	char	c;

	c = va_arg(ap, int);
	if (params->conversion == '%')
		c = '%';
	print_c_aux(params, c);
}
