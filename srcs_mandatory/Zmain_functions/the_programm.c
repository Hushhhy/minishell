/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_programm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:51:23 by pgrellie          #+#    #+#             */
/*   Updated: 2024/10/04 16:06:26 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*prompt(t_ms *ms)
{
	char	*input;

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
		printf("Error: couldn't allocate memory\n");
		exit(1);
	}
	ms->prompt = NULL;
	ms->env = NULL;
	ms->tokens = NULL;
	ms->v_return = 0;
	ms->t_count = 0;
	return (ms);
}

t_ms	*init_program(char **env)
{
	t_ms	*ms;
	int		sig_val;

	sig_val = SIGINT;
	ft_sigint_setup();
	ft_sigquit_setup();
	ms = init_ms();
	ms->env = init_env(env);
	if (ms->env == NULL)
	{
		printf("Error: couldn't allocate memory\n");
		exit(1);
	}
	return (ms);
}

void	the_program(t_ms *ms)
{
	rl_outstream = stderr;
	while (true)
	{
		ms->prompt = prompt(ms);
		if (!ms->prompt)
		{
			printf("exit\n");
			break ;
		}
		if (full_check(ms->prompt) == true)
		{
			ms->tokens = lexer(ms->prompt);
			builtins(ms, ms->tokens);
			// expander(ms);
		}
		handle_here_doc(ms->tokens);
		// executor(ms);
		free_tokens(&ms->tokens);
		free(ms->prompt);
	}
	free(ms->prompt);
}

// Ici -> tokenisation hear >>> parsing >>> exec (lexer)