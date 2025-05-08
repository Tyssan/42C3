/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrunier <tbrunier@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 16:30:07 by tbrunier          #+#    #+#             */
/*   Updated: 2025/05/08 15:37:15 by tbrunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
/*printf, ...*/
# include <unistd.h>
/*write, ...*/
# include <stdlib.h>
/*malloc, free, ...*/
# include <pthread.h>
/*pthread, mutex*/
# include <sys/time.h>
/*gettimeofday*/
# include <limits.h>
/*INT_MIN, INT_MAX*/
# include <stdbool.h>
/*bool variable*/

typedef struct s_data	t_data;//Permet d'avoir "s_data" comme alias

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				meal_count;
	long			last_meal;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_data			*data;
}					t_philo;

typedef struct s_clean
{
	bool	clean_mutex_forks;
	bool	clean_mutex_philos;
	bool	clean_mutex_print;
	bool	clean_mutex_stop;
	bool	clean_malloc_forks;
	bool	clean_malloc_philos;
	bool	clean_threads;
	bool	clean_monitor_thread;
	int		forks_made;
	int		threads_made;
}			t_clean;

typedef struct s_data
{
	int				nb_philos;
	int				ttdie;
	int				tteat;
	int				ttsleep;
	int				food_goal;
	int				simulation_stop;
	long			start_time;
	t_clean			clean;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	mutex_print;
	pthread_mutex_t	mutex_stop;
	pthread_t		monitor_thread;
}					t_data;

/*init.c*/
void			ft_default_init(t_data *data);
bool			ft_malloc_init(t_data *data);
bool			ft_mutex_init(t_data *data);
void			ft_philos_init(t_data *data);

/*monitor.c*/
bool			ft_monitor_famine(int i, t_data *data);
bool			ft_monitor_goal(t_data *data);
void			*ft_monitor(void *arg);

/*philo.c*/
void			ft_cantina(t_philo *philo, t_data *data);
void			*ft_routine(void *arg);
void			ft_philosophers(t_data *data);
void			ft_pov_dev(t_data *data);

/*stop.c*/
void			ft_error_exit(char *error, bool usage);
void			ft_thread_clean(t_data *data);
void			ft_mutex_clean(t_data *data);
void			ft_malloc_clean(t_data *data);

/*utils.c*/
bool			ft_args_check(char *arg);
long			ft_atol(char *n);
long			ft_timestamp(long start);
void			ft_usleep(long duration, t_data *data);
void			ft_philoprint(t_philo *philo, char *str);

#endif
