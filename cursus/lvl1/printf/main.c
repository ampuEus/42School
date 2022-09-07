/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daampuru <daampuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 06:46:11 by daampuru          #+#    #+#             */
/*   Updated: 2022/09/07 01:51:14 by daampuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "src/libftprintf.h"
#include <stdio.h>

/* Functions to detect which tags is */

char	isSpecifier(char c)
{
	if (c == 'c' || c == 's' || c == 'p' \
	|| c == 'd' || c == 'i' || c == 'u' \
	|| c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);			
}

char	isPrecision(char c)
{
	if (c == '.')
		return (1);
	return (0);			
}

char	isWidth(char c)
{
	if (c >= '0' || c < '9')
		return (1);
	return (0);			
}

char	isFlag(char c)
{
	if (c == '-' || c == '+' || c == ' ' \
	|| c == '#' || c == '0')
		return (1);
	return (0);			
}

/* Functions to get the tags of each family */

unsigned int	getSpecifier(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i++])
	{
		if (isSpecifier(str[i])) {
			break;	
		} else if (isPrecision(str[i]) \
				|| isWidth(str[i]) \
				|| isFlag(str[i])) {
			continue;
		} else {
			return (0);
		}	
	}
	return (i);
}

unsigned int	getPrecision(stTags *tag, char *str, size_t len)
{
	unsigned int	i;
	
	i = 0;
	while (str[i++])
	{
		if (isSpecifier(str[i])) {
			return (0);
		} else if (isPrecision(str[i])) {
			if (len - i > 1)
			{
				tag->width_number = ft_substr(str, i, 1);
			}
			break;
		} else if (isWidth(str[i]) || isFlag(str[i])) {
			continue;
		} else {
			return (0);
		}	
	}
	return (i);
}

signed int	getWidth(char *str)
{
	unsigned int	i;
	
	i = 0;
	while (str[i++])
	{
		if (isSpecifier(str[i]) || isPrecision(str[i])) {
			return (0);
		} else if (isWidth(str[i])) {
			break;
		} else if (isFlag(str[i])) {
			continue;
		} else {
			return (0);
		}	
	}
	return (i);
}


char	*find_tags(stTags *tag, char *str)
{
	unsigned int	i;
	char		*tags;

	// Encuentra el especificador
	i = getSpecifier(str);
	if (!i)
		return (0);
	else
		tags = ft_substr(str, i, 1);
	// Encuentra precision
	i = getPrecision(tag, str, i);
	if (!i)
		return (0);
	else
	{
		ft_strlcat(tags, (str + i - 1), 2);
		printf("presicion ");
		//tags = ft_strjoin(tags, str[i]);
	}

	// Encuentra ancho
	// Encuentra flas
	//while (str[i] && (str[i] == '-' || \))
	tag->width_number = ft_substr("prueba", 2, 1);
	return (tags);
		
}

int main(void)
{
	stTags	*tags;
	char	*tag;

	tags = ft_calloc(1,sizeof(stTags));
	tag = find_tags(tags, "%#00+0-020.sdfkjhs");
	printf("%s\n", tag);
	printf("%s\n", tags->width_number);
	free(tag);
	free(tags);
	return (0);
}
