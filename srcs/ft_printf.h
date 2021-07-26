#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft/libft.h"
# include <limits.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_flags
{
	int		f_hyp;
	int		f_zero;
	int		f_prec;
	int		f_width;
	int		f_sp;
	int		f_plus;
	int		f_sharp;
	int		zero;
	int		prec;
	int		width;
	int		sp;
	int		sign;
	int		n_null;
	char	type;
	char	*val;
}	t_flags;

typedef struct s_print
{
	int	len;
}	t_print;

int			ft_printf(const char *fmt, ...);
int			find_next_flag(const char *fmt);
int			is_type(char c);
int			arg_len(const char *fmt, char *pos, va_list args, int len);
const char	*find_type(const char *fmt);
t_flags		get_arg_str(va_list args, const char *fmt, t_flags var);
t_flags		get_arg(va_list args, char c, t_flags var);
t_flags		init_variable(void);
t_flags		flag_space(const char *fmt, t_flags var);
t_flags		flag_width(va_list args, const char *fmt, t_flags var);
t_flags		flag_zero(va_list args, const char *fmt, t_flags var);
t_flags		flag_precision(va_list args, const char *fmt, t_flags var);
t_flags		get_hex_argument(va_list args, t_flags var);
t_flags		get_unsigned_argument(va_list args, t_flags var);
t_flags		get_int_argument(va_list args, t_flags var);
t_flags		get_pointer_argument(va_list args, t_flags var);
t_flags		get_string_argument(va_list args, t_flags var);
t_flags		get_char_argument(va_list args, t_flags var);
t_flags		evaluate_flags(t_flags var);
char		*add_precision(t_flags var);
char		*add_char(t_flags var, int len, char c, int dir);
char		*add_sharp(t_flags var);
char		*write_sign(t_flags var);
#endif
