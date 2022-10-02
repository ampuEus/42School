/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 06:46:11 by daampuru          #+#    #+#             */
/*   Updated: 2022/10/02 23:14:25 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "src/libftprintf.h"
#include <stdio.h>

/* Functions to get the tags of each family */
unsigned int	getSpecifier(const char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i++])
	{
		if (ft_strchr(SPECIFIERS, str[i]))
			break;	
		if (str[i] != '.' \
		&& !ft_isdigit(str[i]) \
		&& !ft_strchr(FLAGS, str[i]))
			return (0);
	}
	return (i);
}

stTags	getPrecision(stTags tag, const char *str)
{
	unsigned int	i;
	
	i = 0;
	while (tag.specifier != str[++i])
	{
		if (tag.precision_dot && !ft_isdigit(str[i]))
			tag.no_comb = 1;
		if (tag.precision_dot && !tag.precision_size)
			tag.precision_size = ft_atoi(str + i);
		if (str[i] == '.')
			tag.precision_dot = 1;
	}
	return (tag);
}

stTags	getWidth(stTags tag, const char *str)
{
	unsigned int	i;
	
	i = 0;
	while (tag.specifier != str[++i] && str[i] != '.')
	{
		if (ft_isdigit(str[i]) && !tag.width_number)
			tag.width_number = ft_atoi(str + i);
		if (!ft_isdigit(str[i]) && tag.width_number)
			tag.no_comb = 1;
	}
	return (tag);
}

stTags	getFlags(stTags tag, const char *str)
{
	unsigned int	i;

	i = 0;
	while (tag.specifier != str[++i] && str[i] != '.')
	{	
		if (str[i] == '-')
			tag.flag_minus = 1;
		if (str[i] == '+')
			tag.flag_plus = 1;
		if (str[i] == ' ')
			tag.flag_space = 1;
		if (str[i] == '#')
			tag.flag_hashtag = 1;
		if (str[i] == '0' && !ft_isdigit(str[i - 1]))
			tag.flag_zero = 1;
		if (tag.flag_plus && tag.flag_space)
			tag.no_comb = 1;
	}
	return (tag);
}

char	imposible_combination(stTags tag)
{
	if (((tag.specifier == 'c' || tag.specifier == 'p') \
		&& (tag.flag_plus || tag.flag_space || tag.flag_hashtag \
		|| tag.flag_zero || tag.precision_dot)) \
	|| (tag.specifier == 's' && (tag.flag_plus || tag.flag_space \
		|| tag.flag_hashtag || tag.flag_zero)) \
	|| ((tag.specifier == 'd' || tag.specifier == 'i') && tag.flag_hashtag) \
	|| (tag.specifier == 'u' \
		&& (tag.flag_plus || tag.flag_space || tag.flag_hashtag))
	|| ((tag.specifier == 'x' || tag.specifier == 'X') \
		&& (tag.flag_plus || tag.flag_space)) \
	|| (tag.specifier == '%' && (tag.flag_minus || tag.flag_plus \
		|| tag.flag_space || tag.flag_hashtag|| tag.flag_zero \
		|| tag.precision_dot || tag.width_number)))
		return (1);
	return (0);
}

stTags	find_tags(stTags tag, const char *str)
{
	unsigned int	tags_len;

	tags_len = getSpecifier(str);
	if (!tags_len)
		return (tag);
	tag.len = tags_len;
	tag.specifier = str[tags_len];
	tag = getPrecision(tag, str);
	tag = getWidth(tag, str);
	tag = getFlags(tag, str);
	if (!tag.no_comb)
		tag.err = imposible_combination(tag); 
	return (tag);
}

/* Print input parameter depending on flags */
size_t	ft_print_c(stTags tag, va_list args)
{
	size_t	count;

	if (tag.specifier == '%')
		return ((size_t)write(1, "%", 1));
		count = 0;
	if (!tag.flag_minus && tag.width_number > 1)
			count = ft_putnchar_fd(' ', 1, tag.width_number - 1);
	count += ft_putchar(va_arg(args, int));
	if (tag.flag_minus && tag.width_number > 1)
		count += ft_putnchar_fd(' ', 1, tag.width_number - 1);
	return (count);
}

size_t ft_print_s(stTags tag, va_list args)
{
	char	*str;
	size_t	count;
	int	str_len;
	int	len_tot;

	str = ft_strdup(va_arg(args, char *));
	str_len = (int)ft_strlen(str);
	len_tot = tag.width_number - str_len;
	if (tag.precision_dot && tag.precision_size < str_len)
	{
		str[tag.precision_size] = '\0';
		len_tot += str_len - tag.precision_size;
	}
	count = 0;
	if (!tag.flag_minus && len_tot > 0)
		count = ft_putnchar_fd(' ', 1, len_tot);
	count += ft_puts(str);
	free(str);
	if (tag.flag_minus && len_tot > 0)
		count += ft_putnchar_fd(' ', 1, len_tot);
	return (count);
}

size_t	ft_print_nbr(stTags tag, va_list args)
{
	size_t	count;
	int	nbr;
	int	nbr_len;
	int	len_tot;

	nbr = va_arg(args, int); // u -> unsigned int????
	nbr_len = (int)ft_nbrlen(nbr, 10);
	len_tot = tag.width_number - nbr_len - tag.flag_space - tag.flag_plus;
	if (tag.precision_dot && tag.precision_size > nbr_len)
		len_tot += nbr_len - tag.precision_size;
	count = 0;
	if (!tag.flag_minus && len_tot > 0)
		count = ft_putnchar_fd(' ', 1, len_tot);
	if (!(tag.specifier == 'u'))
	{
		if (nbr < 0)
		{
			count += ft_putchar('-');
			nbr *= -1;
			nbr_len--;
		}
		else if (tag.flag_plus && nbr >= 0)
			count += ft_putchar('+');
		else if (tag.flag_space)
			count += ft_putchar(' ');
	}
	if (tag.precision_dot && tag.precision_size > nbr_len)
		count += ft_putnchar_fd('0', 1, tag.precision_size - nbr_len);
	count += ft_putnbr_base(nbr, NUMBERS_10);
	if (tag.flag_minus && len_tot > 0)
		count += ft_putnchar_fd(' ', 1, len_tot);
	return (count);
}

size_t	ft_print_hex(stTags tag, va_list args)
{
	size_t	count;
	int	nbr;
	int	nbr_len;
	int	len_tot;

	nbr = va_arg(args, unsigned int);
	nbr_len = (int)ft_nbrlen(nbr, 16);
	len_tot = tag.width_number - nbr_len - tag.flag_space - tag.flag_plus;
	if (tag.precision_dot && tag.precision_size > nbr_len)
		len_tot += nbr_len - tag.precision_size;
	count = 0;
	if (!tag.flag_minus && len_tot > 0)
		count = ft_putnchar_fd(' ', 1, len_tot);
	if (tag.precision_dot && tag.precision_size > nbr_len)
		count += ft_putnchar_fd('0', 1, tag.precision_size - nbr_len);
	if (tag.specifier == 'X')
		count += ft_putnbr_base(nbr, NUMBERS_HEX);
	else
		count += ft_putnbr_base(nbr, NUMBERS_hex);
	if (tag.flag_minus && len_tot > 0)
		count += ft_putnchar_fd(' ', 1, len_tot);
	return (count);
}

size_t	ft_print_type(stTags tag, va_list args)
{
	size_t count;

	count = 0;
	if (tag.specifier == 'c' || tag.specifier == '%')
		count = ft_print_c(tag, args);
	else if (tag.specifier == 's')
		count = ft_print_s(tag, args);
	else if (tag.specifier == 'u' \
			|| tag.specifier == 'd' \
			|| tag.specifier == 'i')
		count = ft_print_nbr(tag, args);
	else if (tag.specifier == 'x' \
			|| tag.specifier == 'X')
		count = ft_print_hex(tag, args);
	return (count);
}

int ft_printf(const char *format, ...)
{
	struct stTags	tags;
	int		count;
	va_list args;

	va_start(args, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
		ft_memset(&tags, '\0', sizeof(struct stTags));
		tags = find_tags(tags, format);
		if (!tags.err && !tags.no_comb)
			count += ft_print_type(tags, args);
		format += tags.len;
/*		printf("\n");
		printf("specifier: %c\n", tags.specifier);
		printf("len: %i\n", tags.len);
		printf("minus: %i\n", tags.flag_minus);
		printf("plus: %i\n", tags.flag_plus);
		printf("space: %i\n", tags.flag_space);
		printf("hashtag: %i\n", tags.flag_hashtag);
		printf("zero: %i\n", tags.flag_zero);
		printf("precision: %d\n", tags.precision_dot);
		printf("precision size: %d\n", tags.precision_size);
		printf("width: %d\n", tags.width_number);
		printf("no combination: %d\n", tags.no_comb);
		printf("error: %d\n", tags.err);
		printf("\n");*/
		}
		else
			count += ft_putchar(*format);
		format++;
	}
	va_end(args);
	printf("Total: %i\n", count);
	return (count);
}

int main(void)
{
	//char *ptr = 0;
	char str[100] = "(%06.3x)\n";

	ft_printf(str, 15, 10);

/*
	// Testing which tag can go with which specifier 
	printf("c + '-': %-c\n", 'h');
	printf("s + '-': %-s\n", "hola");
	printf("p + '-': %-p\n", ptr);
	printf("d + '-': %-d\n", 20);
	printf("i + '-': %-i\n", 20);
	printf("u + '-': %-u\n", 20);
	printf("x + '-': %-x\n", 20);
	printf("X + '-': %-X\n", 20);
	//printf("%-%\n");

	//printf("%+c\n", 'h');
	//printf("%+s\n", "hola");
	//printf("%+p\n", ptr);
	printf("d + '+': %+d\n", 20);
	printf("i + '+': %+i\n", 20);
	//printf("%+u\n", 20);
	//printf("%+x\n", 20);
	//printf("%+X\n", 20);
	//printf("%+%\n", 'h');
	
	//printf("c + ' ' : % c\n", 'h');
	//printf("s + ' ': % s\n", "hola");
	//printf("p + ' ': % p\n", ptr);
	printf("d + ' ': % d\n", 20);
	printf("i + ' ': % i\n", 20);
	//printf("u + ' ': % u\n", 20);
	//printf("x + ' ': % x\n", 20);
	//printf("X + ' ': % X\n", 20);
	//printf("% % \n");

	//printf("c + '#': %#c\n", 'h');
	//printf("s + '#': %#s\n", "hola");
	//printf("p + '#': %#p\n", ptr);
	//printf("d + '#': %#d\n", 20);
	//printf("i + '#': %#i\n", 20);
	//printf("u + '#': %#u\n", 20);
	printf("x + '#': %#x\n", 20);
	printf("X + '#': %#X\n", 20);
	//printf("%#% \n");

	//printf("c + '0': %0c\n", 'h');
	//printf("s + '0': %0s\n", "hola");
	//printf("p + '0': %0p\n", ptr);
	printf("d + '0': %0d\n", 20);
	printf("i + '0': %0i\n", 20);
	printf("u + '0': %0u\n", 20);
	printf("x + '0': %0x\n", 20);
	printf("X + '0': %0X\n", 20);
	//printf("%0% \n");

	//printf("c + '.': %.c\n", 'h');
	printf("s + '.': %.s\n", "hola");
	//printf("p + '.': %.p\n", ptr);
	printf("d + '.': %.d\n", 20);
	printf("i + '.': %.i\n", 20);
	printf("u + '.': %.u\n", 20);
	printf("x + '.': %.x\n", 20);
	printf("X + '.': %.X\n", 20);
	//printf("%.% \n");

	//printf("c + '.3': %.3c\n", 'h');
	printf("s + '.3': %.3s\n", "hola");
	//printf("p + '.3': %.3p\n", ptr);
	printf("d + '.3': %.3d\n", 20);
	printf("i + '.3': %.3i\n", 20);
	printf("u + '.3': %.3u\n", 20);
	printf("x + '.3': %.3x\n", 20);
	printf("X + '.3': %.3X\n", 20);
	//printf("%.3% \n");
*/	
	printf("Total: %i", printf("(%06.3x)\n", 15));
	printf("\n");
	return (0);
}
