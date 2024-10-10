/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migupere <migupere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:24:04 by migupere          #+#    #+#             */
/*   Updated: 2024/10/10 14:23:14 by migupere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

t_vector	create_vector(float x, float y)
{
	t_vector	vector;

	vector.x = x;
	vector.y = y;
	return (vector);
}

t_vector	rotate_vector(t_vector v, float angle)
{
	t_vector	vector;
	float		radians;

	radians = angle * PI / 180.0;
	vector.x = v.x * cos(radians) - v.y * sin(radians);
	vector.y = v.x * sin(radians) + v.y * cos(radians);
	return (vector);
}

t_vector	add_vector(t_vector v1, t_vector v2)
{
	t_vector	vector;

	vector.x = v1.x + v2.x;
	vector.y = v1.y + v2.y;
	return (vector);
}

t_vector	x_vector(t_vector v, float scalar)
{
	t_vector	vector;

	vector.x = v.x * scalar;
	vector.y = v.y * scalar;
	return (vector);
}
