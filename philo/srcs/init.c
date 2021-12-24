/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvenonat <gvenonat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 22:09:29 by gvenonat          #+#    #+#             */
/*   Updated: 2021/07/31 23:18:25 by gvenonat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_atoi(const char *str)
{
	size_t	i;
	long	out;

	i = 0;
	out = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			return (-1);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		out = out * 10 + str[i] - '0';
		i++;
	}
	return ((int)out);
}

int	ft_check_param(int ac, char **av)
{
	if (ac == 5)
		return (4);
	else if (ac == 6)
		return (5);
	else
		return (-1);
}

int	init_param(char **argv, t_param **param, int status)
{
	(*param) = malloc(sizeof(t_param));
	(*param)->num_philos = ft_atoi(argv[1]);
	(*param)->time_to_die = ft_atoi(argv[2]);
	(*param)->time_to_eat = ft_atoi(argv[3]);
	(*param)->time_to_sleep = ft_atoi(argv[4]);
	if (status == 5)
	{
		(*param)->num_of_times_eat = ft_atoi(argv[5]);
		if ((*param)->num_of_times_eat == -1)
			return (-1);
	}
	else
		(*param)->num_of_times_eat = 0;
	if ((*param)->num_philos == -1 || (*param)->time_to_die == -1 \
			|| (*param)->time_to_eat == -1 || (*param)->time_to_sleep == -1)
		return (-1);
	return (0);
}

void	ft_init_help(t_philo ***philo, t_param *param, \
	pthread_mutex_t *forks, pthread_mutex_t *printf)
{
	int	i;

	i = 0;
	while (i < param->num_philos)
	{
		(*philo)[i] = malloc(sizeof(t_philo));
		(*philo)[i]->id = i + 1;
		(*philo)[i]->fork_left = i;
		(*philo)[i]->fork_right = i + 1;
		if ((*philo)[i]->id == param->num_philos)
			(*philo)[i]->fork_right = 0;
		(*philo)[i]->param = param;
		(*philo)[i]->forks = forks;
		(*philo)[i]->printf = printf;
		(*philo)[i]->finish = 0;
		i++;
	}
}

int	init_philo(t_philo ***philo, t_param *param)
{
	pthread_mutex_t	*forks;
	pthread_mutex_t	*printf;

	printf = malloc(sizeof(pthread_mutex_t));
	forks = malloc(sizeof(pthread_mutex_t) * param->num_philos);
	(*philo) = (t_philo **)malloc(sizeof(t_philo *) * param->num_philos);
	if (!(*philo) || !forks || !printf)
		return (-1);
	pthread_mutex_init(forks, NULL);
	pthread_mutex_init(printf, NULL);
	ft_init_help(philo, param, forks, printf);
	return (0);
}
