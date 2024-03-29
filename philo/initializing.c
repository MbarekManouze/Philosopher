/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanouze <mmanouze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 22:00:45 by mmanouze          #+#    #+#             */
/*   Updated: 2022/05/31 16:23:50 by mmanouze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	initializing(t_thread *data, char **av, int ac)
{
	data->philo_num = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	data->must_eat = -1;
	if (ac == 6)
		data->must_eat = ft_atoi(av[5]);
	data->check_death = 1;
	data->allow = 1;
}

void	parse(t_thread *data, int ac)
{
	int	i;

	i = 0;
	while (i < data->philo_num)
	{
		if (ac == 6)
			data->philo[i].eaten = 0;
		data->philo[i].index = i + 1;
		data->philo[i].data = data;
		data->philo[i].lf = i;
		data->philo[i].rf = (i + 1) % data->philo_num;
		i++;
	}
	data->fork = malloc(sizeof(pthread_mutex_t) * data->philo_num);
	i = 0;
	while (i < data->philo_num)
	{
		pthread_mutex_init(&data->fork[i], NULL);
		i++;
	}
	pthread_mutex_init(&data->write, NULL);
}
