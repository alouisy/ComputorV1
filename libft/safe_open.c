/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_open.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouisy- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 21:00:59 by alouisy-          #+#    #+#             */
/*   Updated: 2017/03/15 21:01:01 by alouisy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		safe_open(char *filename)
{
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_error("Error While Trying To Open The File !", 1);
	return (fd);
}
