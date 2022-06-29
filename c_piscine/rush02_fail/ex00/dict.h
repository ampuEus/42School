/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 19:15:37 by manugarc          #+#    #+#             */
/*   Updated: 2022/03/06 17:09:46 by manugarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICT_H
# define DICT_H

struct s_dict {
	char	*index;
	char	*message;
};

int		dict_read(char *file, char ***dict, int *n_lines);
int		dict_to_dict_struct(char **dict, int n_lines,
			struct s_dict ***dict_struct);
void	free_dict_struct(struct s_dict **dict_struct, int n_lines);

#endif
