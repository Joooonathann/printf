#include <unistd.h>
#include <stdarg.h>

static int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

static int	ft_printstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

static void	ft_flags(const char *str, va_list args, int *count)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == 'c')
				*count += ft_printchar(va_arg(args, int));
			if (str[i] == 's')
				*count += ft_printstr(va_arg(args, char *));	
		}
		else
			*count += ft_printchar(str[i]);
		i++;
	}
}

int	ft_printf(const char *str, ...)
{
	int	count;
 	va_list	args;

	count = 0;	
    	va_start(args, str);
	ft_flags(str, args, &count);
	va_end(args);
	return (count);
}

int main(void)
{
	char	*str = "Petit test %c pour voir %c fddffddf %s\n";
	char *test = "test";
	ft_printf(str, 'p', 'D', test);
	return (0);
}
