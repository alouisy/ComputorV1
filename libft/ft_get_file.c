/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouisy- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 21:15:41 by alouisy-          #+#    #+#             */
/*   Updated: 2017/03/12 21:38:27 by alouisy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_get_file(const int fd)
{
	char	*line;
	char	*text;
	char	*tmp;

	text = NULL;
	while (get_next_line(fd, &line) == 1)
		if (text == NULL)
		{
			text = ft_strdup(line);
			free(line);
		}
		else
		{
			tmp = text;
			text = ft_strjoin(text, "\n");
			free(tmp);
			tmp = text;
			text = ft_strjoin(text, line);
			free(tmp);
			free(line);
		}
	return (text);
}
