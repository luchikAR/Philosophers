/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvenonat <gvenonat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 22:13:53 by gvenonat          #+#    #+#             */
/*   Updated: 2021/08/01 14:06:00 by gvenonat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_live_2(t_philo *philo)
{
	pthread_mutex_lock(&(philo->forks[philo->fork_left]));
	pthread_mutex_lock(philo->printf);
	printf(FORK, get_time() - philo->time_to_start, philo->id);
	pthread_mutex_unlock(philo->printf);
	pthread_mutex_lock(&(philo->forks[philo->fork_right]));
	pthread_mutex_lock(philo->printf);
	printf(FORK, get_time() - philo->time_to_start, philo->id);
	pthread_mutex_unlock(philo->printf);
	pthread_mutex_lock(philo->printf);
	printf(EAT, get_time() - philo->time_to_start, philo->id);
	pthread_mutex_unlock(philo->printf);
	fix_usleep(philo->param->time_to_eat);
	pthread_mutex_unlock(&(philo->forks[philo->fork_left]));
	pthread_mutex_unlock(&(philo->forks[philo->fork_right]));
	philo->time_last_eat = get_time();
	pthread_mutex_lock(philo->printf);
	printf(SLEEP, get_time() - philo->time_to_start, philo->id);
	pthread_mutex_unlock(philo->printf);
	fix_usleep(philo->param->time_to_sleep);
	pthread_mutex_lock(philo->printf);
	printf(THINK, get_time() - philo->time_to_start, philo->id);
	pthread_mutex_unlock(philo->printf);
}

void	live_philo(t_philo *philo)
{
	int	i;

	i = 0;
	if (philo->id % 2 == 0 && philo->id != 1)
		fix_usleep(philo->param->time_to_eat / 2);
	while (TRUE)
	{
		ft_live_2(philo);
		if (philo->param->num_of_times_eat != -1
			&& (int)philo->param->num_of_times_eat == ++i)
			break ;
	}
	philo->finish = 1;
	return ;
}

void	ft_check_dead(t_philo **philo)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (TRUE)
	{
		if (philo[i]->finish == 1)
			philo[i]->finish = ++count;
		if (count == philo[i]->param->num_philos \
				&& philo[i]->param->num_of_times_eat > 0)
			break ;
		if (!philo[i]->finish && (int)(get_time() - philo[i]->time_last_eat) > \
		philo[i]->param->time_to_die)
		{
			printf("%lld %d died\n", get_time() - \
				philo[i]->time_to_start, philo[i]->id);
			break ;
		}
		if (i == philo[0]->param->num_philos - 1)
			i = 0;
		else
			i++;
		usleep(500);
	}
}

void	ft_free_treads(pthread_t *threads, int num_philos)
{
	int	i;

	i = 0;
	while (i < num_philos)
		pthread_detach(threads[i++]);
	free(threads);
}

void	ft_work(t_philo **philo)
{
	pthread_t	*treads;
	uint64_t	time_to_start;
	int			i;

	i = 0;
	treads = malloc(sizeof(pthread_t) * philo[0]->param->num_philos);
	if (!treads)
		return ;
	time_to_start = get_time();
	while (i < philo[0]->param->num_philos)
	{
		philo[i]->time_to_start = time_to_start;
		philo[i]->time_last_eat = time_to_start;
		pthread_create(&treads[i], NULL, (void *)live_philo, philo[i]);
		i++;
	}
	ft_check_dead(philo);
	ft_free_treads(treads, philo[0]->param->num_philos);
}
