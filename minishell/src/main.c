/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrunier <tbrunier@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:58:46 by tbrunier          #+#    #+#             */
/*   Updated: 2024/12/05 18:18:53 by tbrunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_main_entry(t_data *data)
{
	ft_main_parsing(data);//WIP
	ft_execute_commands(data);//TODO
	ft_free_commands(data->cmd_list);//TODO
	data->cmd_list = NULL;
}

void	ft_main_loop(t_data *data)
{
	while (data->running)
	{
		data->input = readline("minishell$ ");
		if (data->input == NULL)
		{
			data->running = 0;
			break ;
		}
		add_history(data->input);
		ft_main_entry(data);
		free(data->input);
	}
}

void	ft_init(t_data *data, char **env)
{
	data->running = 1;
	data->env = env;
	data->input = NULL;
	data->cmd_list = NULL;
	data->exit_status = 0;
}

int	main(int argc, char **argv, char **env)
{
	t_data	data;

	(void)argc;
	(void)argv;
	ft_init(&data, env);
	ft_main_loop(&data);
	return (0);
}
