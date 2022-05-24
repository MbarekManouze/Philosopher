/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanouze <mmanouze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 21:57:18 by mmanouze          #+#    #+#             */
/*   Updated: 2022/05/24 15:05:42 by mmanouze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    ft_print(t_philo *philo, char *str)
{
    if (!ft_memcmp(str, "death", ft_strlen("death")))
    {
        pthread_mutex_lock(&philo->data->write);
        printf("%ld ms %d died\n", current_time() - philo->data->start_time, philo->index);
        return ;
    }
    else if(philo->data->allow == 1)
    {
        pthread_mutex_lock(&philo->data->write);
        printf("%ld ms %d %s\n", current_time() - philo->data->start_time, philo->index, str);
        pthread_mutex_unlock(&philo->data->write);
    }
}

long int current_time()
{
    struct timeval now;

    gettimeofday(&now, NULL);
    return (now.tv_sec * 1000 + now.tv_usec / 1000);
}

int death_condition(t_philo *philo)
{
    if (current_time() - philo->last_meal >= philo->data->time_to_die)
    {
        philo->data->allow = 0;
        return (1);
    }
    return (0);
}
