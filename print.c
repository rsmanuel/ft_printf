#include "libft/libft.h"
#include "ft_printf.h"

void	print(va_list ap, t_struct *params)
{
	if (params->conversion == 'c' || params->conversion == '%')
		print_c(ap, params);
	else if (params->conversion == 's')
		print_s(ap, params);
	else if (params->conversion == 'd' || params->conversion == 'i')
		print_d(ap, params);
	else if (params->conversion == 'x' || params->conversion == 'X')
		print_x(ap, params);
	else if (params->conversion == 'p')
		print_p(ap, params);
	else if (params->conversion == 'u')
		print_u(ap, params);
}
