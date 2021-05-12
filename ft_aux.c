#include "libft/libft.h"
#include "ft_printf.h"

void	ft_width(t_struct *params, int len)
{
	int	i;

	i = len;
	while (i-- > 0)
	{
		ft_putchar_fd(' ', 1);
		params->ret++;
	}
}

void	ft_zero(t_struct *params, int len)
{
	int	i;

	i = len;
	while (i-- > 0)
	{
		ft_putchar_fd('0', 1);
		params->ret++;
	}
}

void	ft_precision(t_struct *params)
{
	int	len;
	int	i;

	len = ft_strlen(params->str);
	i = len;
	if (params->precision > len)
	{
		while (i < params->precision)
		{
			ft_putchar_fd('0', 1);
			i++;
			params->len++;
			params->ret++;
		}
	}
}

void	treat_precision(t_struct *params)
{
	if (params->nb < 0)
	{
		params->len--;
		params->width--;
	}
	if (params->width > params->precision && !params->minus)
	{
		if (params->precision < params->len)
			ft_width(params, (params->width - params->len));
		else
			ft_width(params, (params->width - params->precision));
	}
	if (params->nb < 0 && params->nb != INT_MIN)
		ft_putchar_fd('-', 1);
	if (params->conversion == 'p')
		ft_putstr_fd("0x", 1);
	plus_space(params);
	ft_precision(params);
	if (!(!params->precision && params->str[0] == '0'))
		ft_putstr_fd(params->str, 1);
	if (params->width > params->precision && params->minus)
		ft_width(params, (params->width - params->len));
}
