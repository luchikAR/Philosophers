/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvenonat <gvenonat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 22:29:39 by gvenonat          #+#    #+#             */
/*   Updated: 2021/07/31 22:31:33 by gvenonat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdio.h>

# define TRUE 1
# define FORK	"%lld %d has taken a fork\n"
# define EAT	"%lld %d is eating\n"
# define SLEEP	"%lld %d is sleeping\n"
# define THINK	"%lld %d is thinking\n"

typedef struct s_param
{
	int	num_philos;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	num_of_times_eat;
}				t_param;

typedef struct s_philo
{
	int				id;
	int				fork_left;
	int				fork_right;
	int				finish;
	uint64_t		time_to_start;
	uint64_t		time_last_eat;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*printf;
	t_param			*param;

}				t_philo;

int			ft_atoi(const char *str);
int			ft_check_param(int ac, char **av);
int			init_param(char **argv, t_param **param, int status);
int			init_philo(t_philo ***philo, t_param *param);
void		live_philo(t_philo *philo);
void		ft_work(t_philo **philo);
void		fix_usleep(uint64_t msec);
uint64_t	get_time(void);

#endif
