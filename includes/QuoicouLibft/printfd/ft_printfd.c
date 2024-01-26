/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:16:18 by cviegas           #+#    #+#             */
/*   Updated: 2024/01/13 19:12:58 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/first_libft.h"
#include "ft_printfd.h"
#include "limits.h"
#include <stdarg.h>

static int	case_percent(const char *s, int i, va_list ap, int fd)
{
	i++;
	if (s[i] == '%')
		return (ft_putchar_fd('%', fd), 1);
	else if (s[i] == 'c')
		return (ft_putchar_fd(va_arg(ap, int), fd), 1);
	else if (s[i] == 's')
		return (ft_putstr_fd(va_arg(ap, char *), fd));
	else if (s[i] == 'p')
		return (ft_putaddr_fd(va_arg(ap, void *), fd));
	else if (s[i] == 'i' || s[i] == 'd')
		return (ft_putnbr_fd(va_arg(ap, int), fd));
	else if (s[i] == 'u')
		return (ft_putunsigned_fd(va_arg(ap, unsigned int), fd));
	else if (s[i] == 'x')
		return (ft_puthexa_min_fd(va_arg(ap, unsigned int), fd));
	else if (s[i] == 'X')
		return (ft_puthexa_max_fd(va_arg(ap, unsigned int), fd));
	return (0);
}

int	ft_printfd(int fd, const char *s, ...)
{
	va_list	ap;
	int		i;
	int		nb_printed;

	if (!s)
		return (-1);
	va_start(ap, s);
	nb_printed = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
			nb_printed += case_percent(s, i++, ap, fd);
		else
		{
			ft_putchar_fd(s[i], fd);
			nb_printed++;
		}
		i++;
	}
	va_end(ap);
	return (nb_printed);
}

void	v_printfd(int fd, const char *s, ...)
{
	va_list	ap;
	int		i;

	if (!s)
		return ;
	va_start(ap, s);
	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
			case_percent(s, i++, ap, fd);
		else
			ft_putchar_fd(s[i], fd);
		i++;
	}
	va_end(ap);
}

// #include <stdio.h>
// #include <stdlib.h>

// int	main(int ac, char **av)
// {
// 	char *null_str = NULL;

// 	// Everything
// 	printf("EVERYTHING\n\n");
// 	ft_printf("10%%squid %s game %u %c %c\n", "abon", 99999999, '!', 'a');
// 	printf("10%%squid %s game %u %c %c\n", "abon", 99999999, '!', 'a');

// 	printf("\nHEXA\n\n");
// 	ft_printf(" nombre de char %d\n", ft_printf(" %x\n", 1234567));
// 	printf(" nombre de char %d\n", printf(" %x\n", 1234567));

// 	ft_printf(" nombre de char %d\n", ft_printf(" %x\n", 1234567));
// 	printf(" nombre de char %d\n", printf(" %x\n", 1234567));

// 	// NULL
// 	printf("\nNULL\n\n");

// 	printf("%d\n", printf("%s\n", null_str));
// 	ft_printf("%d\n", ft_printf("%s\n", null_str));

// 	printf(" %d", printf("%p\n", null_str));
// 	ft_printf(" %d", ft_printf("%p\n", null_str));
// 	(void) ac;
// 	(void) av;
// 	// 0

// 	printf("\n\nZERO\n\n");
// 	printf("%d\n", printf(0));
// 	ft_printf("%d\n", ft_printf(0));
// }
