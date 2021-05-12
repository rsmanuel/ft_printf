#include "libft/libft.h"
#include "ft_printf.h"

int	len_itox_p(unsigned long long nb)
{
	int	len;

	len = 1;
	while (nb >= 16)
	{
		len++;
		nb = nb / 16;
	}
	return (len);
}

char	*ft_itox_p(unsigned long long nb, t_struct *params)
{
	int		len;
	char	*base;
	char	*str;

	len = len_itox_p(nb);
	if (params->conversion == 'X')
		base = "0123456789ABCDEF";
	else if (params->conversion == 'x' || params->conversion == 'p')
		base = "0123456789abcdef";
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len > 0)
	{
		str[len - 1] = base[nb % 16];
		nb /= 16;
		len--;
	}
	return (str);
}

void	print_p(va_list ap, t_struct *params)
{
	unsigned long long	nb;
	char				*str;

	nb = (unsigned long long)va_arg(ap, void *);
	str = ft_itox_p(nb, params);
	params->str = str;
	params->len = ft_strlen(params->str);
	params->len += 2;
	params->ret += 2;
	print_x_aux(params);
	free(str);
}
