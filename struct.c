#include "ft_printf.h"
#include "libft/libft.h"

void	reset_struct(t_struct *params)
{
	params->minus = 0;
	params->plus = 0;
	params->zero = 0;
	params->space = 0;
	params->hash = 0;
	params->width = 0;
	params->precision = 0;
}
