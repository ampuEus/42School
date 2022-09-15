/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 06:46:11 by daampuru          #+#    #+#             */
/*   Updated: 2022/09/14 14:59:08 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "src/libftprintf.h"
#include <stdio.h>

/* Functions to get the tags of each family */
unsigned int	getSpecifier(char *str)
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

stTags	getPrecision(stTags tag, char *str)
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

stTags	getWidth(stTags tag, char *str)
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

stTags	getFlags(stTags tag, char *str)
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

/* Modify input parameter depending on flags */



stTags	find_tags(stTags tag, char *str)
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
	return (tag);
}


/* Inicialize tags structure */
stTags	start_tags()
{
	stTags	newTags;

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

int main(void)
{
	stTags	tags;
	char *ptr = 0;

	tags = start_tags(tags);	
	tags = find_tags(tags, "%#004444+skhkgjhs");
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
	printf("error: %d\n", tags.no_comb);


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
	return (0);
}
