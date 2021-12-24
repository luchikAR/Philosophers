/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvenonat <gvenonat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 22:15:03 by gvenonat          #+#    #+#             */
/*   Updated: 2021/08/01 13:38:49 by gvenonat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_error(int i)
{
	if (i == 0)
		write(2, "Invalid number of arguments\n", 28);
	else if (i == 1)
		write(2, "Invalid arguments\n", 18);
	else
		write(2, "Error\n", 6);
	return (-1);
}

void	ft_free_main(t_philo **philo, t_param *param, int num_philo)
{
	int	i;

	i = 0;
	free(param);
	free(philo[0]->printf);
	free(philo[0]->forks);
	while (i < num_philo)
	{
		free(philo[i]);
		i++;
	}
	free(philo);
}

int	main(int argc, char *argv[])
{
	int		status;
	t_param	*param;
	t_philo	**philo;

	status = ft_check_param(argc, argv);
	if (status == -1)
		return (ft_error(0));
	if (init_param(argv, &param, status) == -1)
	{
		free(param);
		return (ft_error(1));
	}
	if (init_philo(&philo, param) == -1)
	{
		ft_free_main(philo, param, param->num_philos);
		return (ft_error(-1));
	}
	ft_work(philo);
	ft_free_main(philo, param, param->num_philos);
	return (0);
}
