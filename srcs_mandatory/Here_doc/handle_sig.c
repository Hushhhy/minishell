#include "minishell.h"

void	handle_here_doc_signals(void)
{
	signal(SIGINT, sigint_here_doc);
	signal(SIGQUIT, SIG_IGN);
}

void	sigint_here_doc(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}
