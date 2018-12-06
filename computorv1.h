/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computorv1.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouisy- <alouisy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 13:51:40 by alouisy-          #+#    #+#             */
/*   Updated: 2017/03/23 13:52:06 by alouisy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPUTORV1_H
# define COMPUTORV1_H

# include "libft/includes/libft.h"

typedef struct		s_nbr
{
	double			nbr;
	int				exp;
	struct s_nbr	*next;
}					t_nbr;

void				solution_degree_2(double delta, double a, double b);
double				ft_delta(double a, double b, double c);
int					get_degree(t_nbr *f_nbr);
t_nbr				*parse(char *line);
void				parse2(char *line, t_nbr *f_nbr);
t_nbr				*new_nbr(char *str);
t_nbr				*new_nbr2(char *str);
void				print_list(t_nbr *f_nbr);
int					f_reduce(t_nbr *f_nbr);
double				get_value(int exp, t_nbr *f_nbr);
void				ft_solution(int degree, t_nbr *f_nbr);
int					ft_valid(char *str);
int					list_size(t_nbr *f_nbr);

#endif
