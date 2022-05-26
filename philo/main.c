/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanouze <mmanouze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 08:46:46 by mmanouze          #+#    #+#             */
/*   Updated: 2022/05/25 19:09:02 by mmanouze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*nothing(void *pass)
{
	t_philo	*philo;

	philo = (t_philo *)pass;
	while (philo->data->allow)
	{
		eating(philo);
		sleeping(philo);
		thinking(philo);
		usleep(100);
	}
	return (0);
}

int	must_eaten(t_thread *data)
{
	if (data->philo[0].eaten >= data->must_eat
		&& data->philo[data->philo_num - 1].eaten >= data->must_eat
		&& data->philo[data->philo_num - 2].eaten >= data->must_eat)
	{
		data->allow = 0;
		pthread_mutex_lock(&data->write);
		return (1);
	}
	return (0);
}

int	launching_philos(t_thread *data)
{
	int	i;

	data->start_time = current_time();
	creat_philos(data);
	while (1)
	{
		i = 0;
		while (i < data->philo_num)
		{
			if (must_eaten(data))
				return (0);
			else if (death_condition(&data->philo[i]))
			{
				ft_print(&data->philo[i], "death");
				return (0);
			}
			i++;
			usleep(100);
		}
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_thread	data;

	if ((ac != 5 && ac != 6) || check_errors(av))
	{
		printf("Error\n");
		return (0);
	}
	initializing(&data, av, ac);
	data.philo = malloc(sizeof(t_philo) * data.philo_num);
	parse(&data, ac);
	if (!launching_philos(&data))
		return (0);
	return (0);
}
