/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expands_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <pgrellie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 15:44:04 by pgrellie          #+#    #+#             */
/*   Updated: 2024/09/27 20:10:52 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void	*new_ptr;

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	new_ptr = malloc(new_size);
	if (!new_ptr)
		return (NULL);
	if (ptr)
	{
		if (old_size < new_size)
			ft_memcpy(new_ptr, ptr, old_size);
		else
			ft_memcpy(new_ptr, ptr, new_size);
		free(ptr);
	}
	return (new_ptr);
}

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
		while (s[*x] && ft_isalnum(s[*x]) && s[*x] != '$')
			(*x)++;
		tmp = ft_substr(s, j, *x - j);
		if (!tmp)
			return (NULL);
	}
	return (tmp);
}

bool	expandable(const char *str, size_t pos)
{
	size_t	x;
	bool	in_single_quote;
	bool	in_double_quote;

	x = 0;
	in_single_quote = false;
	in_double_quote = false;
	if (!str)
		return (false);
	while (str[x])
	{
		if (str[x] == '$' && !in_single_quote && !in_double_quote)
			return (true);
		if (str[x] == '\"' && !in_single_quote)
			in_double_quote = !in_double_quote;
		else if (str[x] == '\'' && !in_double_quote)
			in_single_quote = !in_single_quote;
		if (x == pos)
			return (!in_single_quote && (in_double_quote
					|| (!ft_isalnum(str[x + 1]) || str[x + 1] == '_')));
		x++;
	}
	return (false);
}

t_env	*find_node(char *s, t_env *env)
{
	while (env)
	{
		if (ft_strncmp(s, env->name, ft_strlen(s)) == 0
			&& ft_strncmp(s, env->name, ft_strlen(env->name)) == 0)
		{
			return (env);
		}
		env = env->next;
	}
	return (NULL);
}

/**************************************************************************************************************************************/

// char	*get_env_value(t_env *env, char *name)
// {
// 	while (env)
// 	{
// 		if (strcmp(env->name, name) == 0)
// 			return (env->value);
// 		env = env->next;
// 	}
// 	return ("");
// }

// void	int_to_str(int num, char *str)
// {
// 	int	i;
// 	int	temp_num;
// 	int	len;

// 	temp_num = num;
// 	len = 0;
// 	if (num == 0)
// 	{
// 		len = 1;
// 	}
// 	else
// 	{
// 		while (temp_num)
// 		{
// 			len++;
// 			temp_num /= 10;
// 		}
// 	}
// 	str[len] = '\0';
// 	i = len - 1;
// 	while (i >= 0)
// 	{
// 		str[i--] = (num % 10) + '0';
// 		num /= 10;
// 	}
// }


// char	*replace_substring(const char *str, const char *old, const char *new)
// {
// 	char	*result;
// 	int		i;
// 	int		count;
// 	int		new_len;
// 	int		old_len;

// 	count = 0;
// 	new_len = strlen(new);
// 	old_len = strlen(old);
// 	for (i = 0; str[i] != '\0'; i++)
// 	{
// 		if (strstr(&str[i], old) == &str[i])
// 		{
// 			count++;
// 			i += old_len - 1;
// 		}
// 	}
// 	result = (char *)malloc(i + count * (new_len - old_len) + 1);
// 	if (!result)
// 	{
// 		perror("malloc");
// 		exit(EXIT_FAILURE);
// 	}
// 	return (result);
// }

// char	*replace_substring_wrapper(const char *str,
// 			const char *old, const char *new)
// {
// 	char	*result;

// 	result = replace_substring(str, old, new);
// 	replace_substring_content(result, str, old, new);
// 	return (result);
// }

// void	replace_substring_content(char *result, const char *str,
// 			const char *old, const char *new)
// {
// 	int	i;
// 	int	new_len;
// 	int	old_len;

// 	i = 0;
// 	new_len = strlen(new);
// 	old_len = strlen(old);
// 	while (*str)
// 	{
// 		if (strstr(str, old) == str)
// 		{
// 			strcpy(&result[i], new);
// 			i += new_len;
// 			str += old_len;
// 		}
// 		else
// 			result[i++] = *str++;
// 	}
// 	result[i] = '\0';
// }

/**************************************************************************************************************************************/

