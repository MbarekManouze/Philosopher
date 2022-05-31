/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanouze <mmanouze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 12:16:21 by mmanouze          #+#    #+#             */
/*   Updated: 2022/05/31 16:42:33 by mmanouze         ###   ########.fr       */
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
	int				index;
	int				lf;
	int				rf;
	long			last_meal;
	long			last_nap;
	int				eaten;
	pthread_t		th;
	struct threads	*data;
}	t_philo;

typedef struct threads
{
	int				check_death;
	int				philo_num;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	long			start_time;
	int				allow;
	int				must_eat;
	pthread_mutex_t	write;
	pthread_mutex_t	*fork;
	t_philo			*philo;
}	t_thread;

int			ft_atoi(const	char	*str);
int			ft_memcmp(const void	*s1, const void	*s2, size_t n);
size_t		ft_strlen(char *str);
long int	current_time(void);
void		ft_print(t_philo *philo, char *str);
int			death_condition(t_philo *philo);
void		initializing(t_thread *data, char **av, int ac);
void		parse(t_thread *data, int ac);
void		eating(t_philo *philo);
void		sleeping(t_philo *philo);
void		thinking(t_philo *philo);
int			creat_philos(t_thread *data);
void		*nothing(void *pass);
int			check_errors(char **av);

#endif
