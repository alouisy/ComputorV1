/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcopy_wo_c.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouisy- <alouisy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 13:29:02 by alouisy-          #+#    #+#             */
/*   Updated: 2017/03/23 13:29:05 by alouisy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strcopy_wo_c(char *src, char c)
{
	char	*dst;
	int		cpt;
	int		i;
	int		j;

	i = 0;
	j = 0;
	cpt = ft_how_many_c(src, c);
	dst = (char *)malloc(sizeof(char) * (ft_strlen(src) - cpt + 1));
	if (dst)
	{
		while (src[i] != '\0')
		{
			if (src[i] != c)
			{
				dst[j] = src[i];
				j++;
			}
			i++;
		}
		dst[j] = '\0';
	}
	return (dst);
}
