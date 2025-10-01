/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 18:06:28 by armosnie          #+#    #+#             */
/*   Updated: 2025/10/01 18:20:14 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_valid_map(char **map)
{
	int i;
	int in_map;
	char *trimmed;
	
	in_map = 0;
	i = detect_features(map);
	if (i == -1)
		return (1);
	while (map[i])
	{
		trimmed = ft_strtrim(map[i], " \t");
		if (!trimmed)
			return (1);
		if (in_map == 0 && trimmed[0] == '1' && trimmed[1] == '1')
			in_map = 1;
		if (in_map == 1 && trimmed[0] == '\n')
			return (free(trimmed), 1);
		free(trimmed);
		i++;
	}
	return (0);
}

int	which_side(t_data *data, char c, int has_a_player)
{
	if (has_a_player == 1 && (c == 'N' || c == 'S' || c == 'W' || c == 'E'))
        return (1);
	else if (has_a_player == 0)
    {
        if (c == 'N')
            data->player = 'N';
        if (c == 'S')
            data->player = 'S';
        if (c == 'W')
            data->player = 'W';
        if (c == 'E')
            data->player = 'E';
        return (2);
    }
    return (0);
}

int	player_position(t_data *data)
{
	int i;
	int j;
	int has_a_player;

	i = -1;
	has_a_player = 0;
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
		{
			if (which_side(data, data->map[i][j], has_a_player) == 1)
				return (1);
			if (which_side(data, data->map[i][j], has_a_player) == 2)
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
