/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 06:46:11 by daampuru          #+#    #+#             */
/*   Updated: 2022/09/27 18:51:46 by daampuru         ###   ########.fr       */
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
		if (str[i] == '0')
			tag.flag_zero = 1;
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
	else
		tag.specifier = str[tags_len];
	tag = getPrecision(tag, str);
	tag = getWidth(tag, str);
	tag = getFlags(tag, str);
	if (!tag.no_comb)
		tag.err = imposible_combination(tag); 
	return (tag);
}

/* Print input parameter depending on flags */


/* Inicialize tags structure */
stTags	start_tags()
{
	stTags	newTags;

	newTags.err = 0;
	newTags.no_comb = 0;
	newTags.specifier = 0;
	newTags.flag_minus = 0;
	newTags.flag_plus = 0;
	newTags.flag_space = 0;
	newTags.flag_hashtag = 0;
	newTags.flag_zero = 0;
	newTags.width_number = 0;
	newTags.precision_dot = 0;
	newTags.precision_size = 0;
	return (newTags);
}

int ft_printf(const char *format, ...)
{
	stTags	tags;
	int		count

	tags = start_tags();
	tags = find_tags(tags, format);
	count = ft_print_value();



	printf("specifier: %c\n", tags.specifier);
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
	printf("\n");
	return (0);
}

int main(void)
{
	char *ptr = 0;
	char str[100] = "%4.csdlkfsfn\n";

	ft_printf(str, "hola");

	/* Testing which tag can go with which specifier */
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
	printf("\n");
	return (0);
}
