/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_how_many_c.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouisy- <alouisy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 21:32:53 by alouisy-          #+#    #+#             */
/*   Updated: 2017/03/16 21:34:06 by alouisy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_how_many_c(char *str, char c)
{
	int		i;
	int		cpt;

	i = 0;
	cpt = 0;
	while (str && str[i] != '\0')
	{
		if (str[i] == c)
			cpt++;
		i++;
	}
	return (cpt);
}
