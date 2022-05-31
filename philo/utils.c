/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanouze <mmanouze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 21:57:18 by mmanouze          #+#    #+#             */
/*   Updated: 2022/05/31 16:34:45 by mmanouze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print(t_philo *philo, char *str)
{
	if (!ft_memcmp(str, "death", ft_strlen("death")))
	{
		pthread_mutex_lock(&philo->data->write);
		printf("%ld ms %d died\n", current_time()
			- philo->data->start_time, philo->index);
		return ;
	}
	else if (philo->data->allow == 1)
	{
		pthread_mutex_lock(&philo->data->write);
		printf("%ld ms %d %s\n", current_time()
			- philo->data->start_time, philo->index, str);
		pthread_mutex_unlock(&philo->data->write);
	}
}

long int	current_time(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return (now.tv_sec * 1000 + now.tv_usec / 1000);
}

int	death_condition(t_philo *philo)
{
	if (current_time() - philo->last_meal >= philo->data->time_to_die)
	{
		philo->data->allow = 0;
		return (1);
	}
	return (0);
}

int	creat_philos(t_thread *data)
{
	int	i;

	i = 0;
	while (i < data->philo_num)
	{
		data->philo[i].last_meal = current_time();
		if (pthread_create(&data->philo[i].th,
				NULL, &nothing, &data->philo[i]) != 0)
			return (1);
		i++;
		usleep(100);
	}
	return (0);
}

int	check_errors(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] < 48 || av[i][j] > 57)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
