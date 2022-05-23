/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanouze <mmanouze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 08:45:03 by mmanouze          #+#    #+#             */
/*   Updated: 2022/05/22 22:10:08 by mmanouze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
    int index;
    int lf;
    int rf;
    long last_meal;
    long last_nap;
    pthread_t th;
    struct threads *data;
}       t_philo;

typedef struct threads 
{
    int philo_num;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    long start_time;
    pthread_mutex_t write;
    pthread_mutex_t *fork;
    t_philo *philo;
}   t_thread;

int	ft_atoi(const	char	*str);
int	ft_memcmp(const void	*s1, const void	*s2, size_t n);
size_t	ft_strlen(char *str);
long int current_time();
void    ft_print(t_philo *philo, char *str);
long int current_time();
int death_condition(t_philo *philo);
void    initializing(t_thread *data, char **av);
void    parse(t_thread *data);
void    eating(t_philo *philo);
void    sleeping(t_philo *philo);
void    thinking(t_philo *philo);

#endif