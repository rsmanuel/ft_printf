#include "libft/libft.h"
#include "ft_printf.h"

void	ft_printf_aux(int i, const char *fmt, va_list ap, t_struct *params)
{
	while (fmt[i])
	{
		if (fmt[i] == '%' && fmt[i + 1] != '%')
			i += parse_str(&fmt[i + 1], ap, params);
		else if (fmt[i] == '%' && fmt[i + 1] == '%')
		{
			ft_putchar_fd('%', 1);
			i++;
			params->ret++;
		}
		else
		{
			ft_putchar_fd(fmt[i], 1),
			params->ret++;
		}
		i++;
	}
}

int	ft_printf(const char *fmt, ...)
{
	int			i;
	va_list		ap;
	t_struct	*params;
	int			ret;

	i = 0;
	va_start(ap, fmt);
	params = (t_struct *)malloc(sizeof(t_struct));
	if (!params)
		return (0);
	reset_struct(params);
	params->ret = 0;
	params->nb = 0;
	ft_printf_aux(i, fmt, ap, params);
	ret = params->ret;
	va_end(ap);
	free(params);
	return (ret);
}
