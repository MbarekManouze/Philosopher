/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanouze <mmanouze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 08:46:46 by mmanouze          #+#    #+#             */
/*   Updated: 2022/05/24 16:48:18 by mmanouze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    *nothing(void   *pass)
{
    t_philo *philo;

    philo = (t_philo*)pass;
    while (philo->data->allow)
    {
        eating(philo);
        sleeping(philo);
        thinking(philo);
        usleep(100);
    }
    return (0);
}

int launching_philos(t_thread *data)
{
    int i;

    i = 0;
    data->start_time = current_time();
    while (i < data->philo_num)
    {
        data->philo[i].last_meal = current_time();
        pthread_create(&data->philo[i].th, NULL, &nothing, &data->philo[i]);
        i++;
        usleep(100);
    }
    while (1)
    {
        i = 0;
        while (i < data->philo_num)
        {
            if (death_condition(&data->philo[i]))
            {
                ft_print(&data->philo[i], "death");
                return (0);
            }
            i++;
            //usleep(100);
        }
    }
    return (0);
} 

int main(int ac, char **av)
{
    t_thread data;

    if (ac != 5 && ac != 6)
    {
        printf("Error\n");
        return (0);
    }
    initializing(&data, av);
    data.philo = malloc(sizeof(t_philo) * data.philo_num);
    parse(&data);
    if (!launching_philos(&data))
        return (0);
    return (0);
}