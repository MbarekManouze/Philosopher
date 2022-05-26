/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nothing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanouze <mmanouze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 22:02:03 by mmanouze          #+#    #+#             */
/*   Updated: 2022/05/25 19:13:32 by mmanouze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->fork[philo->lf]);
	ft_print(philo, "has taken left fork");
	pthread_mutex_lock(&philo->data->fork[philo->rf]);
	ft_print(philo, "has taken right fork");
	ft_print(philo, "is eating");
	philo->last_meal = current_time();
	usleep(philo->data->time_to_eat * 300);
	philo->eaten++;
	while (current_time() - philo->last_meal < philo->data->time_to_eat)
		usleep(100);
	pthread_mutex_unlock(&philo->data->fork[philo->lf]);
	pthread_mutex_unlock(&philo->data->fork[philo->rf]);
}

void	sleeping(t_philo *philo)
{
	long	time;

	time = current_time();
	ft_print(philo, "is sleeping");
	usleep(philo->data->time_to_sleep * 300);
	while (current_time() - time < philo->data->time_to_sleep)
		usleep(100);
}

void	thinking(t_philo *philo)
{
	ft_print(philo, "is thinking");
}
