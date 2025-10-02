/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 12:17:13 by armosnie          #+#    #+#             */
/*   Updated: 2025/10/02 12:33:30 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	count_words(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

char	*dup_word(t_data *data, const char *s, char c)
{
	int		i;
	char	*dup;

	i = longest_line(data->map);
	dup = malloc(sizeof(char) * (i + 1));
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	**split_with_longest_line(t_data *data, const char *s, char c)
{
	char	**split;
	int		j;
	int		i;

	i = 0;
	j = 0;
	split = malloc(sizeof(char *) * (count_words((char *)s, c) + 1));
	if (split == NULL || s == NULL)
		return (NULL);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			split[j] = dup_word(data, &s[i], c);
			if (split[j++] == NULL)
				return (free_array(split), NULL);
			while (s[i] && s[i] != c)
				i++;
		}
		else
			break ;
	}
	return (split[j] = NULL, split);
}
