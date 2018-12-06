/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouisy- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 16:08:51 by alouisy-          #+#    #+#             */
/*   Updated: 2016/11/04 16:08:52 by alouisy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*tmp;
	size_t	i;

	i = 0;
	tmp = (char*)s;
	if (n != 0)
	{
		while (i < n)
		{
			tmp[i] = 0;
			i++;
		}
		s = (void*)tmp;
	}
}
