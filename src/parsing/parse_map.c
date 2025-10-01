/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 17:02:05 by armosnie          #+#    #+#             */
/*   Updated: 2025/10/01 14:40:08 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	start_of_map(char **map)
{
	int		i;
	char	*trimmed;

	i = detect_features(map);
	while (map[i])
	{
		trimmed = ft_strtrim(map[i], " \t");
		if (!trimmed)
			return (-1);
		if (trimmed[0] == '1' && trimmed[1] == '1')
			return (free(trimmed), i);
		free(trimmed);
		i++;
	}
	return (-1);
}

char	**dup_only_map(t_data *data)
{
	int		start;
	int		i;
	char	**new_map;
	int		len;

	i = 0;
	len = 0;
	start = start_of_map(data->map);
	if (start == -1)
		return (NULL);
	while (data->map[start + len])
		len++;
	new_map = malloc(sizeof(char *) * (len + 1));
	if (!new_map)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new_map[i] = ft_strdup(data->map[start + i]);
		if (!new_map[i])
			return (free_array(new_map), NULL);
		i++;
	}
	new_map[len] = NULL;
	return (free_array(data->map), new_map);
}

int	player_position(t_data *data)
{
	int	i;
	int	j;
	int	has_a_player;

	i = -1;
	has_a_player = 0;
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
		{
			if (has_a_player == 1 && (data->map[i][j] == 'N'
					|| data->map[i][j] == 'S' || data->map[i][j] == 'W'
					|| data->map[i][j] == 'E'))
				return (1);
			if (has_a_player == 0 && (data->map[i][j] == 'N'
					|| data->map[i][j] == 'S' || data->map[i][j] == 'W'
					|| data->map[i][j] == 'E'))
			{
				data->p_x = j;
				has_a_player = 1;
			}
		}
		if (has_a_player == 1)
			data->p_y = i;
	}
	return (0);
}

int	is_different_content(char **map, int i, int j)
{
	if (map[i][j] == '0')
	{
		if (map[i + 1][j] != '1' && map[i + 1][j] != '0' && map[i + 1][j] != 'N'
			&& map[i + 1][j] != 'S' && map[i + 1][j] != 'W' && map[i
			+ 1][j] != 'E')
			return (1);
		if (map[i - 1][j] != '1' && map[i - 1][j] != '0' && map[i - 1][j] != 'N'
			&& map[i - 1][j] != 'S' && map[i - 1][j] != 'W' && map[i
			- 1][j] != 'E')
			return (1);
		if (map[i][j + 1] != '1' && map[i][j + 1] != '0' && map[i][j + 1] != 'N'
			&& map[i][j + 1] != 'S' && map[i][j + 1] != 'W' && map[i][j
			+ 1] != 'E')
			return (1);
		if (map[i][j - 1] != '1' && map[i][j - 1] != '0' && map[i][j - 1] != 'N'
			&& map[i][j - 1] != 'S' && map[i][j - 1] != 'W' && map[i][j
			- 1] != 'E')
			return (1);
	}
	return (0);
}

int	check_wall(char **map)
{
	int	i;
	int	j;

	i = 1;
	while (map[i])
	{
		j = 1;
        if (map[count_map(map)][j])
			i++;
		while (skip_whitespace(map[i][j]))
			j++;
		while (map[i][j] && map[i][j + 1])
		{
			if (is_different_content(map, i, j))
                return (1);
            j++;
		}
        i++;
	}
	return (0);
}

int	parse_map(t_data *data)
{
	data->map = dup_only_map(data);
	if (!data->map)
		return (1);
	if (is_valid_char_in_map(data->map))
		return (1);
	if (player_position(data))
		return (1);
	if (check_wall(data->map))
		return (printf("bad\n"), 1);
	printf("good\n");
	return (0);
}

// ligne vide a la fin, probleme ?