#include "libft/libft.h"
#include "ft_printf.h"

void	print_d_aux(t_struct *params)
{
	if (params->precision > 0)
		treat_precision(params);
	else
	{
		if ((params->plus || params->space) && params->precision != 0
			&& params->nb >= 0)
			params->len++;
		if (!params->minus && params->width && !params->zero)
			ft_width(params, (params->width - params->len));
		else if (!params->minus && params->width && !params->precision)
			ft_width(params, (params->width - params->len));
		if (params->nb < 0 && params->nb != INT_MIN)
			ft_putchar_fd('-', 1);
		plus_space(params);
		if (params->zero && !params->minus && params->precision)
			ft_zero(params, (params->width - params->len));
		if (!(!params->precision && params->str[0] == '0'))
			ft_putstr_fd(params->str, 1);
		if (params->minus)
			ft_width(params, (params->width - params->len));
	}
	if (!(!params->precision && params->str[0] == '0'))
		params->ret += ft_strlen(params->str);
}

void	print_d(va_list ap, t_struct *params)
{
	int		nb;
	char	*str;

	nb = va_arg(ap, int);
	params->nb = nb;
	str = ft_itoa(nb);
	if (nb < 0)
	{
		free(str);
		str = ft_itoa(-nb);
		if (nb != INT_MIN)
			params->ret++;
	}
	params->len = ft_strlen(str);
	if ((nb < 0 && nb != INT_MIN))
		params->len++;
	if (!params->precision && str[0] == '0'
		&& !params->plus && !params->space)
		params->len = 0;
	params->str = str;
	print_d_aux(params);
	free(str);
}
