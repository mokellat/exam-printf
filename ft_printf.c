/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokellat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 20:27:37 by mokellat          #+#    #+#             */
/*   Updated: 2020/02/27 21:35:04 by mokellat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>


int 	pre;
int		width;
int		p;
int		i;
char	conv;
int		ret;

int		ft_strlen(char *s)
{
	int i = 0;
	while (s[i])
		i++;
	return i;
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
	ret++;
}

void	ft_putstr(char *s)
{
	while (*s)
	{
		ft_putchar(*s);
		s++;
	}
}

char	*ft_strdup(char *s)
{
	int len;
	len = ft_strlen(s);
	char *str;
	str = (char *)malloc(sizeof(char) * len + 1);
	for (int i = 0; i < len; i++)
	{
		str[i] = s[i];
	}
	str[i] = '\0';
	return str;
}

char	*ft_itoa(long n, int base)
{
	long		x;
	int		i;
	char 	*s;
	x = n;
	i = 1;
	while (x / base != 0)
	{
		x /= base;
		i++;
	}
	s = (char *)malloc(sizeof(char) * i + 1);
	s[i] = '\0';
	for (int j = i - 1; j >= 0; j--)
	{
		if (base == 10)
		{
			s[j] = n % base + 48;
			n /= base;
		}
		else if (base == 16)
		{
			int res;
			res = n % base;
			if (res < 10)
			{
				s[j] = res + 48;
			}
			else
			{
				s[j] = res + 87;
			}
			n /= 16;
		}
	}
	return (s);
}

void	ft_conv(va_list ap)
{
	if (conv == 'd')
	{
		char *s;
		int sign;
		int nb;
		nb = va_arg(ap, int);
		sign = (nb < 0) ? 1 : 0;
		nb *= (sign) ? -1 : 1;
		s = ft_itoa(nb, 10);
		int len;
		len = (sign) ? ft_strlen(s) + 1: ft_strlen(s);
		(p == 1 && pre == 0 && nb == 0) ? len = 0: len;
		while (width > len && width > pre)
		{
			ft_putchar(' ');
			width--;
		}
		len = (sign) ? len - 1: len;
		(sign) ? ft_putchar('-') : 0;
		while (pre > len)
		{
			ft_putchar('0');
			pre--;
		}
		(len) ? ft_putstr(s) : 0;
	}
	if (conv == 's')
	{
		int len;
		char *s;
		s = va_arg(ap, char *);
		len = ft_strlen(s);
		(pre == 0 && p == 1) ? len = pre: len;
		(pre != 0 && pre < len) ? len = pre: len;
		while (width > len)
		{
			ft_putchar(' ');
			width--;
		}
		for (int i = 0; i < len; i++)
		{
			ft_putchar(s[i]);
		}
	}
	if (conv == 'x')
	{
		char *s;
		unsigned int nb;
		nb = va_arg(ap, unsigned int);
		s = ft_itoa(nb, 16);
		int len;
		len = ft_strlen(s);
		(p == 1 && pre == 0 && nb == 0) ? len = 0: len;
		while (width > len && width > pre)
		{
			ft_putchar(' ');
			width--;
		}
		while (pre > len)
		{
			ft_putchar('0');
			pre--;
		}
		(len) ? ft_putstr(s) : 0;
	}
}

void	ft_print(va_list ap, const char *s)
{
	width = 0;
	pre = 0;
	if (s[i] == '%')
	{
		ft_putchar('%');
		i++;
		return ;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		width = width * 10 + s[i] - 48;
		i++;
	}
	if (s[i] == '.')
	{
		i++;
		p = 1;
		while (s[i] >= '0' && s[i] <= '9')
		{
			pre = pre * 10 + s[i] - 48;
			i++;
		}
	}
	conv = s[i++];
	ft_conv(ap);
}

int		ft_printf(const char *s, ...)
{
	i = 0;
	ret = 0;
	va_list arg;
	va_start(arg, s);

	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			ft_print(arg, s);
		}
		else 
		{
			ft_putchar(s[i]);
			i++;
		}
	}
	va_end(arg);
	return (ret);
}

int main()
{
	int i;
	i = ft_printf("%10.5x", 10);
	ft_printf("\n%d", i);
	return (0);
}
