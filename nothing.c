/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nothing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanouze <mmanouze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 22:02:03 by mmanouze          #+#    #+#             */
/*   Updated: 2022/05/22 22:08:24 by mmanouze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    eating(t_philo *philo)
{
    pthread_mutex_lock(&philo->data->fork[philo->lf]);
    ft_print(philo,"has taken left fork");
    pthread_mutex_lock(&philo->data->fork[philo->rf]);
    ft_print(philo, "has taken right fork");
    ft_print(philo, "is eating");
    philo->last_meal = current_time();
    while (current_time() - philo->last_meal < philo->data->time_to_eat)
        usleep(100);
    pthread_mutex_unlock(&philo->data->fork[philo->lf]);
    pthread_mutex_unlock(&philo->data->fork[philo->rf]);
}

void    sleeping(t_philo *philo)
{
    philo->last_nap = current_time();
    ft_print(philo, "is sleeping");
    while (current_time() - philo->last_nap < philo->data->time_to_eat )
        usleep(300);
}

void    thinking(t_philo *philo)
{
    ft_print(philo, "is thinking");
}
