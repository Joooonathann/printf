#include <unistd.h>
#include <stdarg.h>

int	*ft_printf(char *str, ...)
{
 	va_list args;
    va_start(args, str);

	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%' && str[i + 1] == 'r')
		{
			write (1, va_arg(args, int), 1);
			i++;
		}
		else
			write (1, &str[i], 1);
		i++;
	}
	va_end(args);
	return 0;
}

int main(void)
{
	char	*str = "Petit test pour voir %r";
	ft_printf(str, 'p');
}
