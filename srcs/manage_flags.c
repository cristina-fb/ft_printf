#include "ft_printf.h"

char	*add_sharp(t_flags var)
{
	char	*aux;

	aux = 0;
	if (var.f_sharp)
	{
		if ((var.type == 'x') || (var.type == 'p'))
			aux = ft_strjoin("0x", var.val);
		else if (var.type == 'X')
			aux = ft_strjoin("0X", var.val);
		if (aux)
		{
			free(var.val);
			var.val = aux;
		}
	}
	return (var.val);
}

char	*add_char(t_flags var, int len, char c, int dir)
{
	char	*aux1;
	char	*aux2;

	aux1 = ft_calloc(len + 1, 1);
	if (aux1)
	{
		while (len > 0)
			aux1[--len] = c;
		if (dir)
			aux2 = ft_strjoin(var.val, aux1);
		else
			aux2 = ft_strjoin(aux1, var.val);
		if (aux2)
		{
			free(var.val);
			free(aux1);
			var.val = aux2;
		}
	}
	return (var.val);
}

char	*add_precision(t_flags var)
{
	char	*aux;

	if (!var.prec && ((var.type == 's') || ((var.type != 's')
				&& (var.val[0] == '0'))))
	{
		free(var.val);
		return (ft_strdup(""));
	}
	if (var.type == 's')
	{
		if ((var.prec < (int)ft_strlen(var.val)) && var.prec > 0)
		{
			aux = ft_substr(var.val, 0, var.prec);
			free(var.val);
			return (aux);
		}
	}
	else
	{
		if (var.prec > (int)ft_strlen(var.val))
			var.val = add_char(var, var.prec - ft_strlen(var.val), '0', 0);
	}
	return (var.val);
}

t_flags	evaluate_flags(t_flags var)
{
	if (!is_type(var.type))
		return(var);
	if (var.type != 'p' && var.type != 'c' && var.f_prec)
		var.val = add_precision(var);
	if (var.f_zero && !var.f_prec && var.zero > ((int)ft_strlen(var.val) + var.n_null + (var.f_plus || var.f_sp)) && !var.f_hyp)
	{
		if (var.f_sharp)
			var.zero -= 2;
		var.val = add_char(var, var.zero - ft_strlen(var.val) - var.n_null - (var.f_plus || var.f_sp), '0', 0);
	}
	else if (var.f_zero && !var.f_prec && var.zero > ((int)ft_strlen(var.val) + var.n_null + var.f_plus) && var.f_hyp)
		var.val = add_char(var, var.zero - ft_strlen(var.val) - var.n_null - var.f_plus, ' ', 1);
	var.val = add_sharp(var);
	var.val = write_sign(var);
	if (var.f_sp)
	{
		if (var.sp > (int)ft_strlen(var.val))
			var.val = add_char(var, var.sp - ft_strlen(var.val), ' ', 0);
		else if (var.type != 's' && !var.f_plus)
			var.val = add_char(var, 1, ' ', 0);
	}
	if (var.f_zero && (var.zero * -1) > ((int)ft_strlen(var.val) + var.n_null))
		var.val = add_char(var, (var.zero * -1) - ft_strlen(var.val) - var.n_null, ' ', 1);
	else if (var.f_zero && var.f_prec && var.zero > ((int)ft_strlen(var.val) + var.n_null))
		var.val = add_char(var, var.zero - ft_strlen(var.val) - var.n_null, ' ', var.f_hyp);
	if (var.f_width && var.width > ((int)ft_strlen(var.val) + var.n_null))
		var.val = add_char(var, var.width - ft_strlen(var.val) - var.n_null, ' ', var.f_hyp);
	return (var);
}