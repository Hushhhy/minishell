/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expands_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <pgrellie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 15:44:04 by pgrellie          #+#    #+#             */
/*   Updated: 2024/10/28 15:22:41 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*tracker(char *s, int *x)
{
	int		j;
	char	*tmp;

	if (!s || !x)
		return (NULL);
	tmp = NULL;
	if (s[*x] == '$')
	{
		(*x)++;
		j = *x;
		while (s[*x] && (ft_isalnum(s[*x]) || s[*x] == '_'))
			(*x)++;
		tmp = ft_substr(s, j, *x - j);
		if (!tmp)
			return (NULL);
	}
	return (tmp);
}

void	init_var(t_var *v)
{
	v->x = 0;
	v->y = 0;
}

void	init_exp(t_exp *e)
{
	e->x = 0;
	e->in_single_quote = false;
	e->in_double_quote = false;
}

bool	expandable(const char *str, size_t pos)
{
	t_exp	e;

	init_exp(&e);
	while (str[e.x])
	{
		if (str[e.x] == '\"' && !e.in_single_quote)
			e.in_double_quote = !e.in_double_quote;
		else if (str[e.x] == '\'' && !e.in_double_quote)
			e.in_single_quote = !e.in_single_quote;
		if (e.x == pos)
		{
			if (e.in_single_quote == true)
				return (false);
			else if (e.in_double_quote == true && (ft_isalnum(str[e.x + 1])
					|| str[e.x + 1] == '_' || str[e.x + 1] == '?'))
				return (true);
			else if (str[e.x] == '$' && !e.in_single_quote && !e.in_double_quote
				&& (ft_isalnum(str[e.x + 1]) || str[e.x + 1] == '_'
					|| str[e.x + 1] == '?'))
				return (true);
		}
		e.x++;
	}
	return (false);
}

t_env	*find_node(char *s, t_env *env)
{
	t_env	*current;

	if (!s || !env)
		return (NULL);
	current = env;
	while (current)
	{
		if (ft_strncmp(s, current->name, ft_strlen(s)) == 0
			&& ft_strncmp(s, current->name, ft_strlen(current->name)) == 0)
		{
			return (current);
		}
		current = current->next;
	}
	return (NULL);
}

/*char	*get_env_value(t_env *env, char *name)
{
	while (env)
	{
		if (strcmp(env->name, name) == 0)
			return (env->value);
		env = env->next;
	}
	return ("");
}

void	int_to_str(int num, char *str)
{
	int	i;
	int	temp_num;
	int	len;

	temp_num = num;
	len = 0;
	if (num == 0)
	{
		len = 1;
	}
	else
	{
		while (temp_num)
		{
			len++;
			temp_num /= 10;
		}
	}
	str[len] = '\0';
	i = len - 1;
	while (i >= 0)
	{
		str[i--] = (num % 10) + '0';
		num /= 10;
	}
}


char	*replace_substring(const char *str, const char *old, const char *new)
{
	char	*result;
	int		i;
	int		count;
	int		new_len;
	int		old_len;

	count = 0;
	new_len = strlen(new);
	old_len = strlen(old);
	for (i = 0; str[i] != '\0'; i++)
	{
		if (strstr(&str[i], old) == &str[i])
		{
			count++;
			i += old_len - 1;
		}
	}
	result = (char *)malloc(i + count * (new_len - old_len) + 1);
	if (!result)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	return (result);
}

char	*replace_substring_wrapper(const char *str,
			const char *old, const char *new)
{
	char	*result;

	result = replace_substring(str, old, new);
	replace_substring_content(result, str, old, new);
	return (result);
}

void	replace_substring_content(char *result, const char *str,
			const char *old, const char *new)
{
	int	i;
	int	new_len;
	int	old_len;

	i = 0;
	new_len = strlen(new);
	old_len = strlen(old);
	while (*str)
	{
		if (strstr(str, old) == str)
		{
			strcpy(&result[i], new);
			i += new_len;
			str += old_len;
		}
		else
			result[i++] = *str++;
	}
	result[i] = '\0';
}*/