#include <stdio.h>
#include "srcs/ft_printf.h"
int	main()
{
	char	*prueba;
	int z = ft_printf("|% s|", "");
	//hi low\0don't print me lol\0
	//system("leaks a.out");
	printf("\n");
	int y = printf("|% s|", "");
	printf("\n");
	printf("%d %d", z, y);
}