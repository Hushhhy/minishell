/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expands_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <pgrellie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 15:44:04 by pgrellie          #+#    #+#             */
/*   Updated: 2024/09/23 13:05:26 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	d_quote_count(char *s)
{
	int	x;
	int	count;

	x = 0;
	count = 1;
	while (s[x])
	{
		if (s[x] == '\"')
			count++;
		x++;
	}
	return (count);
}

int	s_quote_count(char *s)
{
	int	x;
	int	count;

	x = 0;
	count = 1;
	while (s[x])
	{
		if (s[x] == '\'')
			count++;
		x++;
	}
	return (count);
}

int	quote_counter(char *s)
{
	int		x;
	int		count;

	x = 0;
	while (s[x])
	{
		if (s[x] == '\"')
		{
			count = d_quote_count(s);
			return (count);
		}
		else if (s[x] == '\'')
		{
			count = s_quote_count(s);
			return (count);
		}
		x++;
	}
}

int	malloc_calculator(t_token *tok, t_env *env)
{
	int	x;

	x = ft_strlen(tok->value) + ft_strlen(env->value)
		- ft_strlen(tracker(tok->value)) - quote_counter(tok->value);
	return (x);
}

char	*ft_copy(char *str)
{
	int		i;
	int		len;
	char	*ret;

	i = 0;
	len = ft_strlen(str);
	ret = malloc(sizeof(char) * len + 1);
	if (!ret)
		return (NULL);
	while (str[i])
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
