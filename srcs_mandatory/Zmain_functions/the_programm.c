/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_programm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 13:16:36 by acarpent          #+#    #+#             */
/*   Updated: 2024/11/06 15:21:21 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_var = 0;

int	handle_ctrld(t_ms *ms)
{
	if (!ms->prompt)
	{
		printf("exit\n");
		return (1);
	}
	return (0);
}

char	*prompt(t_ms *ms)
{
	char	*input;

	if (ms->hd == true)
		signal(SIGINT, handle_sigint_hd);
	input = readline(PROMPT_LINE);
	if (input == NULL)
		return (NULL);
	if (input[0] == '\0' || !ft_strcmp(input, ":")
		|| !ft_strcmp(input, "!") || !ft_strcmp(input, "#"))
	{
		if (!ft_strcmp(input, ":") || !ft_strcmp(input, "#"))
			ms->v_return = 0;
		if (!ft_strcmp(input, "!"))
			ms->v_return = 1;
		free(input);
		return (ft_strdup(""));
	}
	add_history(input);
	return (input);
}

t_ms	*init_ms(void)
{
	t_ms	*ms;

	ms = malloc(sizeof(t_ms));
	if (ms == NULL)
	{
		ft_putstr_fd("Error: couldn't allocate memory\n", 2);
		exit(1);
	}
	ms->prompt = NULL;
	ms->envi = NULL;
	ms->env = NULL;
	ms->tokens = NULL;
	ms->cmdlines = NULL;
	ms->v_return = 0;
	ms->c_count = 0;
	ms->pid = NULL;
	ms->previous_fd = -1;
	ms->pipefd[0] = -1;
	ms->pipefd[1] = -1;
	ms->hd = false;
	ms->here_doc_fd = -1;
	return (ms);
}

t_ms	*init_program(char **env)
{
	t_ms	*ms;

	ms = init_ms();
	ms->env = init_env(env);
	if (env_counter(ms->env) == 0)
		ms->env = create_env();
	return (ms);
}

void	the_program(t_ms *ms)
{
	while (true)
	{
		signal(SIGQUIT, SIG_IGN);
		signal(SIGINT, handle_sigint);
		ms->b = false;
		ms->prompt = prompt(ms);
		ms->hd = false;
		if (handle_ctrld(ms))
			break ;
		if (g_var != 0)
		{
			ms->v_return = g_var;
			g_var = 0;
		}
		if (full_check(ms) == false)
			continue ;
		handle_here_doc(ms, &ms->tokens);
		if (ms->tokens)
			ms->v_return = executor(ms);
		free(ms->prompt);
		free_tokens(&ms->tokens);
		delete_tmp_files();
	}
	free_env(&ms->env);
	free(ms->prompt);
}
