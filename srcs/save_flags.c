#include "ft_printf.h"

t_flags	flag_precision(va_list args, const char *fmt, t_flags var)
{
	if (*(fmt + 1) == '*')
		var.prec = va_arg(args, int);
	else
		var.prec = ft_atoi(fmt + 1);
	if (var.prec >= 0)
		var.f_prec = 1;
	else
		var.prec = 0;
	return (var);
}

t_flags	flag_zero(va_list args, const char *fmt, t_flags var)
{
	var.f_zero = 1;
	if (*(fmt + 1) == '*')
		var.zero = va_arg(args, int);
	else
		var.zero = ft_atoi(fmt + 1);
	return (var);
}

t_flags	flag_width(va_list args, const char *fmt, t_flags var)
{
	var.f_width = 1;
	if (*fmt == '*')
		var.width = va_arg(args, int);
	else
		var.width = ft_atoi(fmt);
	if (var.width < 0)
	{
		var.width *= -1;
		var.f_hyp = 1;
	}
	return (var);
}

t_flags	flag_space(const char *fmt, t_flags var)
{
	var.f_sp = 1;
	if ((*(fmt + 1) != '0') && ft_isdigit(*(fmt + 1)))
		var.sp = ft_atoi(fmt + 1);
	return (var);
}

int	find_next_flag(const char *fmt)
{
	int	n;

	n = 1;
	if ((*fmt == '0') || (*fmt == '.'))
	{
		if (ft_isdigit(*(fmt + 1)))
		{
			while (ft_isdigit(*(++fmt)))
				n++;
		}
		else if (*(fmt + 1) == '*')
			n++;
	}
	else if (ft_isdigit(*fmt))
		while (ft_isdigit(*(++fmt)))
			n++;
	else if ((*fmt == ' ') && (*(fmt + 1) != '0'))
		while (ft_isdigit(*(++fmt)))
			n++;
	return (n);
}
