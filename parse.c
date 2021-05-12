#include "libft/libft.h"
#include "ft_printf.h"

void	parse_flags(const char *str, t_struct *params)
{
	while (ft_strchr("-+ 0#", *str))
	{
		if (*str == '-')
			params->minus = 1;
		else if (*str == '+')
			params->plus = 1;
		else if (*str == ' ')
			params->space = 1;
		else if (*str == '0')
			params->zero = 1;
		else if (*str == '#')
			params->hash = 1;
		str++;
	}
}

void	parse_precision(const char *str, va_list ap, t_struct *params)
{
	int		i;
	int		start;
	char	*sub;

	i = 0;
	params->precision = -1;
	while (ft_strchr("-+ 0#", str[i]) || ft_strchr("*0123456789", str[i]))
		i++;
	if (str[i] != '.')
		return ;
	start = i + 1;
	if (str[start] == '*')
	{
		params->precision = va_arg(ap, int);
		return ;
	}
	while (ft_strchr("0123456789", str[i]))
		i++;
	sub = ft_substr(str, start, i - start);
	params->precision = ft_atoi(sub);
	free(sub);
}

void	parse_width(const char *str, va_list ap, t_struct *params)
{
	int		i;
	int		start;
	char	*sub;

	i = 0;
	start = 0;
	while (ft_strchr("-+ 0#", str[i]))
		i++;
	start = i;
	if (str[i] == '*')
	{
		params->width = va_arg(ap, int);
		if (params->width < 0)
		{
			params->minus = 1;
			params->width = -(params->width);
		}
		return ;
	}
	while (ft_strchr("0123456789", str[i]))
		i++;
	sub = ft_substr(str, start, i - start);
	params->width = ft_atoi(sub);
	free(sub);
}

void	parse_modifiers(const char *str, va_list ap, t_struct *params)
{
	reset_struct(params);
	parse_flags(str, params);
	parse_width(str, ap, params);
	parse_precision(str, ap, params);
}

int	parse_str(const char *str, va_list ap, t_struct *params)
{
	int		len;
	char	*conversion;

	len = 0;
	conversion = NULL;
	parse_modifiers(str, ap, params);
	while (ft_strchr("-. 0*#+cspdiuxXnfge123456789%", *str))
	{
		len++;
		conversion = ft_strchr("cspdiufxX%", *str);
		if (conversion)
			break ;
		str++;
	}
	if (!conversion)
		return (0);
	params->conversion = *conversion;
	if (!params->width)
		params->zero = 0;
	print(ap, params);
	return (len);
}
