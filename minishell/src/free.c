/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrunier <tbrunier@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:39:48 by tbrunier          #+#    #+#             */
/*   Updated: 2024/12/03 15:43:04 by tbrunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

//free_tokens here ig

void	ft_free_commands(t_commands *cmd_list)
{
	t_commands		*tmp;
	unsigned int	i;

	while (cmd_list)
	{
		tmp = cmd_list;
		cmd_list = cmd_list->next;
		i = 0;
		while (tmp->args && tmp->args[i])
		{
			free(tmp->args[i]);
			i++;
		}
		free(tmp->args);
		if (tmp->cmd_path)
			free(tmp->cmd_path);
		if (tmp->redir_in != -1)
			close(tmp->redir_in);
		if (tmp->redir_out != -1)
			close(tmp->redir_out);
		free(tmp);
	}
}
