#include "ft_printf.h"

t_print	init_print_struct(void)
{
	t_print	print;

	print.len = 0;
	return (print);
}

int	is_type(char c)
{
	return ((c == 'c') || (c == 's') || (c == 'p') || (c == 'd') || (c == 'i')
		|| (c == 'u') || (c == 'x') || (c == 'X') || (c == '%'));
}

const char	*find_type(const char *fmt)
{
	if (fmt)
	{
		while (*fmt)
		{
			if (is_type(*fmt))
				break ;
			fmt++;
		}
	}
	return (fmt);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	t_print	print;
	char	*pos;

	print = init_print_struct();
	if (fmt)
	{
		va_start(args, fmt);
		while (*fmt)
		{
			pos = ft_strchr(fmt, '%');
			if (pos)
				print = arg_len(fmt, pos, args, print);
			else
			{
				print.len += ft_strlen(fmt);
				write(1, fmt, ft_strlen(fmt));
				break ;
			}
			fmt = find_type(pos + 1) + 1;
		}
		va_end(args);
	}
	return (print.len);
}
