/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 17:23:23 by crocha-s          #+#    #+#             */
/*   Updated: 2024/10/12 18:04:41 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	getchr(const char *s, int c)
{
	while (*s)
	{
		if (*(unsigned char *)s == (unsigned char)c)
			return (*s);
		s++;
	}
	if (*(unsigned char *)s == (unsigned char)c)
		return (*s);
	return (0);
}
