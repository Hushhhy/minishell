/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:33:44 by pgrellie          #+#    #+#             */
/*   Updated: 2024/11/04 15:26:37 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pedro_lib.h"

static int	word_count(char const *s, char c)
{
	int	x;
	int	count;

	x = 0;
	count = 0;
	while (s && s[x])
	{
		if (s[x] != c)
		{
			count++;
			while (s[x] != c && s[x])
				x++;
		}
		else
			x++;
	}
	return (count);
}

static int	word_len(char const *str, char c)
{
	int	x;

	x = 0;
	while (str[x] && str[x] != c)
		x++;
	return (x);
}

void	*ft_free_tab(char **strs)
{
	int	x;

	x = 0;
	if (strs == NULL)
		return (NULL);
	while (strs[x])
	{
		free(strs[x]);
		strs[x] = NULL;
		x++;
	}
	free(strs);
	strs = NULL;
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		y;
	int		wlen;
	char	**tab;

	tab = malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (!tab || !s)
		return (NULL);
	y = 0;
	while (*s)
	{
		wlen = 0;
		while (*s && *s == c)
			s++;
		wlen = word_len(s, c);
		if (wlen)
		{
			tab[y] = ft_substr(s, 0, wlen);
			if (!tab[y])
				return (ft_free_tab(tab), NULL);
			y++;
		}
		s += wlen;
	}
	tab[y] = 0;
	return (tab);
}
