/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 17:02:05 by armosnie          #+#    #+#             */
/*   Updated: 2025/10/02 14:02:22 by armosnie         ###   ########.fr       */
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
	new_map = malloc(sizeof(char *) * (longest_line(data->map) + 1));
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
    int len;

	i = 0;
    len = count_map(map);
	while (map[i] && i < len)
	{
		j = 1;
		while (skip_whitespace(map[i][j]))
			j++;
		while (map[i][j])
		{
			if (is_different_content(map, i, j))
                return (1);
            j++;
		}
        i++;
	}
	return (0);
}

void	transform_space_into_1(t_data *data)
{
	int i;
	int j;
	int len;

	len = longest_line(data->map);
	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (j < len)
		{
			if (data->map[i][j] == ' ' || data->map[i][j] == '\0')
				data->map[i][j] = '1';
			j++;
		}
		i++;
	}
}

int	parse_map(t_data *data)
{
	data->map = dup_only_map(data);
	if (!data->map)
		return (error_2(data, "dup error\n"), 1);
	if (is_valid_char_in_map(data->map))
		return (error_2(data, "invalid character in map\n"), 1);
	if (player_position(data))
		return (error_2(data, "0 or more than 1 player\n"), 1);
	if (check_wall(data->map))
		return (error_2(data, "invalid map format\n"), 1);
	transform_space_into_1(data);
	get_map_x_y(data);
	// printf("map y : %d - map x : %d - player y : %d - player x : %d - player side : %c\n", data->map_y, data->map_x, data->p_y, data->p_x, data->player);
	// printf("NO : %s ; SO : %s ; WE : %s ; EA : %s\n", data->text->no, data->text->so, data->text->we, data->text->ea);
	// printf("fl-> r : %d - g : %d - b : %d\nce-> r : %d - g : %d - b : %d\n", data->text->fl->r, data->text->fl->g, data->text->fl->b, data->text->ce->r, data->text->ce->g, data->text->ce->b);
	print_array(data->map);
	return (0);
}

// ligne vide a la fin, probleme ?