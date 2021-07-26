#include "ft_printf.h"

int	is_flag(char c)
{
	return ((c == '-') || (c == '.') || (c == '*') || (c == 'd') || (c == '+')
		|| (c == ' ') || (c == '#') || ft_isdigit(c));
}

t_flags	init_variable(void)
{
	t_flags	var;

	var.f_hyp = 0;
	var.f_zero = 0;
	var.f_prec = 0;
	var.f_width = 0;
	var.f_sp = 0;
	var.f_plus = 0;
	var.f_sharp = 0;
	var.zero = 0;
	var.prec = 0;
	var.width = 0;
	var.sp = 0;
	var.sign = 0;
	var.n_null = 0;
	var.type = 0;
	var.val = 0;
	return (var);
}

t_flags	get_arg(va_list args, char c, t_flags var)
{
	if (c == 'c')
		return (get_char_argument(args, var));
	else if (c == 's')
		return (get_string_argument(args, var));
	else if (c == 'p')
		return (get_pointer_argument(args, var));
	else if ((c == 'd') || (c == 'i'))
		return (get_int_argument(args, var));
	else if (c == 'u')
		return (get_unsigned_argument(args, var));
	else if ((c == 'x') || (c == 'X'))
		return (get_hex_argument(args, var));
	else if (c == '%')
		var.val = ft_strdup("%");
	return (var);
}

t_flags	get_arg_str(va_list args, const char *fmt, t_flags var)
{
	while (is_flag(*fmt))
	{
		if (*fmt == '-')
			var.f_hyp = 1;
		else if ((*fmt == '.') && !var.f_prec)
			var = flag_precision(args, fmt, var);
		else if ((*fmt == '0') && !var.f_zero)
			var = flag_zero(args, fmt, var);
		else if (((*fmt == '*') || (ft_isdigit(*fmt) && (*fmt != '0')))
			&& !var.f_width)
			var = flag_width(args, fmt, var);
		else if (*fmt == '+')
			var.f_plus = 1;
		else if ((*fmt == ' ') && !var.f_sp)
			var = flag_space(fmt, var);
		else if (*fmt == '#')
			var.f_sharp = 1;
		else if (is_type(*fmt))
			break ;
		fmt = fmt + find_next_flag(fmt);
	}
	var.type = *fmt;
	var = get_arg(args, *fmt, var);
	return (evaluate_flags(var));
}

int	arg_len(const char *fmt, char *pos, va_list args, int len)
{
	t_flags	var;

	write(1, fmt, pos - fmt);
	len += pos - fmt;
	var = init_variable();
	var = get_arg_str(args, pos + 1, var);
	if (var.val)
	{
		if (var.n_null && var.f_hyp)
		{
			write(1, "\0", 1);
			write(1, var.val, ft_strlen(var.val));
		}
		else if (var.n_null && !var.f_hyp)
		{
				write(1, var.val, ft_strlen(var.val));
				write(1, "\0", 1);
		}
		else
			write(1, var.val, ft_strlen(var.val));
		len += ft_strlen(var.val) + var.n_null;
		free(var.val);
	}
	return (len);
}
