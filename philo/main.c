/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanouze <mmanouze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 08:46:46 by mmanouze          #+#    #+#             */
/*   Updated: 2022/05/31 16:33:18 by mmanouze         ###   ########.fr       */
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
	int	i;

	i = 0;
	while (i < data->philo_num)
	{
		if (data->philo[i].eaten != data->must_eat)
			return (0);
		i++;
	}
	if (i == data->philo_num)
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
	if (creat_philos(data))
	{
		write(2, "Creating philos failed\n", 24);
		return (0);
	}
	while (1)
	{
		i = 0;
		while (i < data->philo_num)
		{
			if (must_eaten(data) == 1)
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
