/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 19:15:01 by daampuru          #+#    #+#             */
/*   Updated: 2022/03/06 22:45:20 by manugarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STR_H
# define FT_STR_H

int		is_char(char *str, char to_find);
char	*strcpy_from(char *dest, char *str, char from);
char	*numstrcpy(char *dest, char *src);
char	*strcpy_to(char *dest, char *str, char to);
char	*ft_strcpy(char *dest, char *str, int n);

#endif
