/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrunier <tbrunier@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:07:41 by tbrunier          #+#    #+#             */
/*   Updated: 2024/12/05 18:23:58 by tbrunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../src/libft/include/libft.h"
# include <stdio.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <sys/fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef enum e_token_type
{
	TOKEN_WORD,
	TOKEN_PIPE,
	TOKEN_REDIR_IN,
	TOKEN_REDIR_OUT,
	TOKEN_D_REDIR_IN,
	TOKEN_D_REDIR_OUT,
	TOKEN_EOF
}						t_token_type;

typedef struct s_token
{
	char				*value;
	t_token_type		type;
	struct s_token		*next;
	struct s_token		*prev;
}						t_token;

typedef struct s_commands
{
	char				**args;
	int					args_size;
	int					args_count;
	char				*cmd_path;
	int					pipe_in;
	int					pipe_out;
	int					pipe_in_fd;
	int					pipe_out_fd;
	int					redir_in;
	int					redir_out;
	struct s_commands	*next;
	struct s_commands	*prev;
}						t_commands;

typedef struct s_data
{
	int					running;
	char				**env;
	char				*input;
	t_commands			*cmd_list;
	int					exit_status;
}						t_data;

// free.c
void					ft_free_commands(t_commands *cmd_list);

// lexer.c
t_token					*ft_lexer(const char *input);

// main.c
void					ft_init(t_data *data, char **env);
void					ft_main_loop(t_data *data);
void					ft_main_entry(t_data *data);

// parsing.c
void					ft_main_parsing(t_data *data);

/* utils.c
void					ft_free_split(char **split);
char					*ft_strjoin_free(char *s1, char *s2);
*/

#endif
