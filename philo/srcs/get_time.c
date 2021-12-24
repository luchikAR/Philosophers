/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvenonat <gvenonat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 22:16:20 by gvenonat          #+#    #+#             */
/*   Updated: 2021/07/31 22:16:52 by gvenonat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

uint64_t	get_time(void)
{
	uint64_t				to_return;
	static struct timeval	time;

	if (gettimeofday(&time, 0) < 0)
		return (0);
	to_return = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (to_return);
}

void	fix_usleep(uint64_t msec)
{
	uint64_t	start;

	start = get_time();
	while (get_time() - start < msec)
		usleep(500);
}
