/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computorv1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouisy- <alouisy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 13:51:30 by alouisy-          #+#    #+#             */
/*   Updated: 2017/03/23 13:51:33 by alouisy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computorv1.h"
#include <stdio.h>

void	ft_solution(int degree, t_nbr *f_nbr)
{
	double	delta;
	double	a;
	double	b;
	double	c;

	if (degree == 2)
	{
		a = get_value(2, f_nbr);
		b = get_value(1, f_nbr);
		c = get_value(0, f_nbr);
		delta = ft_delta(a, b, c);
		printf("Discriminant : %f\n", delta);
		solution_degree_2(delta, a, b);
	}
	else if (degree == 1)
	{
		a = get_value(1, f_nbr);
		b = -1 * get_value(0, f_nbr);
		c = b / a;
		printf("The solution of this equation is : %.2f\n", c);
	}
	else if (degree > 2)
		printf("The polynomial degree is stricly greater than 2, I can't solve.\n");
	else
		printf("Sorry I can't solve this. :(\n");
}

void	solution_degree_2(double delta, double a, double b)
{
	double	r;

	if (delta == 0)
		printf("Discriminant equal 0, the only solution is : %f\n", (((-1 * b) + ft_sqrt2(delta)) / (2 * a)));
	if (delta > 0)
		printf("Discriminant is strictly positive, the 2 solutions are :\nx1 = %f\nx2 = %f\n", (((-1 * b) - ft_sqrt2(delta)) / (2 * a)), (((-1 * b) + ft_sqrt2(delta)) / (2 * a)));
	if (delta < 0)
	{
		r = ft_sqrt2(-1 * delta);
		if (a >= 0)
			printf("Discriminant is strictly negative, the 2 solutions are :\nz1 = %f - i%f\nz2 = %f + i%f\n", ((-1 * b) / (2 * a)), (-1 * ((-1 * r) / (2 * a))), ((-1 * b) / (2 * a)), (r / (2 * a)));
		else
			printf("Discriminant is strictly negative, the 2 solutions are :\nz1 = %f + i%f\nz2 = %f - i%f\n", ((-1 * b) / (2 * a)), ((-1 * r) / (2 * a)), ((-1 * b) / (2 * a)), (-1 * (r / (2 * a))));
	}
}

double	ft_delta(double a, double b, double c)
{
	return ((b * b) - (4 * a * c));
}

int		get_degree(t_nbr *f_nbr)
{
	t_nbr	*list = f_nbr;
	int		i = list->exp;

	while (list != NULL)
	{
		if (i < list->exp)
			i = list->exp;
		list = list->next;
	}
	return (i);
}

t_nbr	*parse(char *line)
{
	t_nbr	*list = NULL;
	t_nbr	*f_nbr;
	int		i = 0;

	while (line && line[i] != '\0' && (list != NULL || i == 0))
	{
		if (list == NULL)
		{
			list = new_nbr(line + i);
			f_nbr = list;
		}
		else
		{
			list->next = new_nbr(line + i);
			list = list->next;
		}
		while(line[i] != '\0' && line[i] != '^')
			i++;
		if (line[i] != '\0')
			i++;
		while(line[i] != '\0' && ft_isdigit(line[i]))
			i++;
	}
	return (f_nbr);
}

void	parse2(char *line, t_nbr *f_nbr)
{
	t_nbr	*list = f_nbr;
	int		i = 0;

	while (list->next != NULL)
		list = list->next;
	while (line && line[i] != '\0' && list)
	{
		list->next = new_nbr2(line + i);
		list = list->next;
		while(line[i] != '\0' && line[i] != '^')
			i++;
		if (line[i] != '\0')
			i++;
		while(line[i] != '\0' && ft_isdigit(line[i]))
			i++;
	}
}

t_nbr	*new_nbr(char *str)
{
	char	*tmp = str;
	t_nbr	*nbr = NULL;

	while (tmp && *tmp != '\0' && *tmp != '^')
		tmp++;
	nbr = (t_nbr *)malloc(sizeof(t_nbr));
	if (nbr)
	{
		nbr->nbr = atof(str);
		nbr->exp = atoi(++tmp);
		nbr->next = NULL;
	}
	return (nbr);
}

t_nbr	*new_nbr2(char *str)
{
	char	*tmp = str;
	t_nbr	*nbr = NULL;

	while (tmp && *tmp != '\0' && *tmp != '^')
		tmp++;
	nbr = (t_nbr *)malloc(sizeof(t_nbr));
	if (nbr)
	{
		nbr->nbr = -1 * atof(str);
		nbr->exp = atoi(++tmp);
		nbr->next = NULL;
	}
	return (nbr);
}

void	print_list(t_nbr *f_nbr)
{
	t_nbr	*list = f_nbr;

	printf("Reduced form : ");
	while (list != NULL)
	{
		if (list == f_nbr)
		{	
			if (list->nbr > (double)(int)list->nbr || list->nbr < (double)(int)list->nbr)
				printf("%.1f * X^%d ", list->nbr, list->exp);
			else
				printf("%d * X^%d ", (int)list->nbr, list->exp);
		}
		else
		{
			if (list->nbr >= 0)
			{
				if (list->nbr > (double)(int)list->nbr)
					printf("+ %.1f * X^%d ", list->nbr, list->exp);
				else
					printf("+ %d * X^%d ", (int)list->nbr, list->exp);
			}
			else
			{
				if (list->nbr < (double)(int)list->nbr)
					printf("- %.1f * X^%d ", -1 * list->nbr, list->exp);
				else
					printf("- %d * X^%d ", (int)(-1 * list->nbr), list->exp);
			}
		}
		list = list->next;
	}
	printf("= 0\n");
}

int		ft_valid(char *str)
{
	int		dot;
	int		i = -1;
	double	nb;
	int		exp;

	if (!str)
		return (0);
	while (str && str[++i] != '\0')
	{
		if (!ft_isdigit(str[i]) && str[i] != '^' && str[i] != 'X' && str[i] != '+' && str[i] != '-' && str[i] != '*' && str[i] != '=' && str[i] != '.')
			return (0);
	}
	i = 0;
	while (str && str[i] != '\0')
	{
		nb = atof(str + i);
		if ((nb == 0.0 && str[i] != '0' && str[i] != '-' && str[i] != '+') || (nb == 0.0 && ((str[i] == '-' && str[i + 1] != '0') || (str[i] == '+' && str[i + 1] != '0'))))
			return (0);
		if (str[i] == '-' || str[i] == '+')
			i++;
		dot = 0;
		while (str[i] != '\0' && (ft_isdigit(str[i]) == 1 || str[i] == '.'))
		{
			if (str[i] == '.')
				dot++;
			i++;
		}
		if (dot > 1)
			return (0);
		if (str[i++] != '*')
			return (0);
		if (str[i++] != 'X')
			return (0);
		if (str[i++] != '^')
			return (0);
		if (str[i] == '\0')
			return (0);
		exp = atoi(str + i);
		if ((exp < 0) || (exp == 0 && str[i] != '0' && str[i] != '-' && str[i] != '+') || (exp == 0 && ((str[i] == '-' && str[i + 1] != '0') || (str[i] == '+' && str[i + 1] != '0'))))
			return (0);
		if (str[i] == '-' || str[i] == '+')
			i++;
		while (str[i] != '\0' && ft_isdigit(str[i]) == 1)
			i++;
	}
	return (1);
}

int		f_reduce(t_nbr *f_nbr)
{
	t_nbr	*list = f_nbr;
	t_nbr	*last = f_nbr;
	t_nbr	*prev;

	while (last->next != NULL)
	{
		prev = last;
		last = last->next;
	}
	while (list != last)
	{
		if (list->exp == last->exp)
		{
			list->nbr += last->nbr;
			free(last);
			prev->next = NULL;
			return (1);
		}
		list = list->next;
	}
	return(0);
}

double	get_value(int exp, t_nbr *f_nbr)
{
	t_nbr	*list = f_nbr;

	while (list != NULL)
	{
		if (list->exp == exp)
			return(list->nbr);
		list = list->next;
	}
	return (0);
}

int		list_size(t_nbr *f_nbr)
{
	int		i = 0;
	t_nbr	*list = f_nbr;

	if (list)
	{
		while (list)
		{
			i++;
			list = list->next;
		}
	}
	return (i);
}

int		main(int argc, char **argv)
{
	t_nbr	*f_nbr = NULL;
	char	*line;
	char	**tab;
	int		degree;
	int		lst_size;

	if (argc == 2)
	{
		line = ft_strcopy_wo_c(argv[1], ' ');
		if (line && ft_strlen(line) > 0)
		{
			tab = ft_strsplit(line, '=');
			if (ft_tablen(tab) == 2 && ft_valid(tab[0]) && ft_valid(tab[1]))
			{
				f_nbr = parse(tab[0]);
				parse2(tab[1], f_nbr);
				while(f_reduce(f_nbr))
					;
				print_list(f_nbr);
				lst_size = list_size(f_nbr);
				degree = get_degree(f_nbr);
				while (get_value(degree, f_nbr) == 0)
					degree--;
				printf("Polynomial degree : %d\n", degree);
				if (lst_size > 1)
					ft_solution(degree, f_nbr);
				else if (f_nbr->nbr == 0)
					printf("The solution of this equation is : R\n");
				else if (f_nbr->nbr != 0 && (f_nbr->exp == 1 || f_nbr->exp == 2))
					printf("The solution of this equation is : 0\n");
				else
					printf("Sorry I can't solve this. :(\n");
			}
			else
				ft_error("Bad input !", 1);
		}
		else
			ft_error("Bad input !", 1);
	}
	else
		printf("usage: ./computor equation\nex:    ./computor \"5 * X^0 + 4 * X^1 - 9.3 * X^2 = 1 * X^0\"\n       ./computor \"5 * X^0 + 4 * X^1 = 4 * X^0\"\n       ./computor \"8 * X^0 - 6 * X^1 + 0 * X^2 - 5.6 * X^3 = 3 * X^0\"\n");
	return 0;
}
