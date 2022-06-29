/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_struct.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 23:08:20 by manugarc          #+#    #+#             */
/*   Updated: 2022/03/06 23:08:22 by manugarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICT_STRUCT_H
# define DICT_STRUCT_H

struct s_dict {
	char	*index;
	char	*message;
};

int		dict_to_dict_struct(char **dict, int n_lines,
			struct s_dict ***dict_struct);
void	free_dict_struct(struct s_dict **dict_struct, int n_lines);

#endif
