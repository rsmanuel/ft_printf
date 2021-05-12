#include "libft/libft.h"
#include "ft_printf.h"

static int	n_len(unsigned int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

static char	*int_min(unsigned int n)
{
	if (n == 0)
		return (ft_strdup("0"));
	return (0);
}

char	*ft_itoa_u(unsigned int n)
{
	int		len;
	char	*strn;

	len = n_len(n);
	if (n == 0)
	{
		strn = int_min(n);
		return (strn);
	}
	strn = (char *)malloc(sizeof(char) * (len + 1));
	if (!strn)
		return (0);
	strn[len] = '\0';
	while (n != 0)
	{
		len--;
		strn[len] = n % 10 + '0';
		n = n / 10;
	}
	return (strn);
}
