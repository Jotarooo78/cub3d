/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 17:02:05 by armosnie          #+#    #+#             */
/*   Updated: 2025/09/29 18:00:54 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	start_of_map(char **map)
{
	int	i;
    char *trimmed;

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

char    **dup_only_map(t_data *data)
{
    int start;
    int i;
    char **new_map;
    int len;
    
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

int	pos_depart(t_data *data)
{
	int i;
	int j;
	int stop;

	i = start_of_map(data->map);
	stop = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (stop == 0 && (data->map[i][j] == 'N' || data->map[i][j] == 'S'
					|| data->map[i][j] == 'W' || data->map[i][j] == 'E'))
				stop = 1;
			if (stop == 1)
				break ;
			j++;
		}
        if (stop == 1)
            break ;
		i++;
	}
    return (0);
}

char	**duplicate_map(char **map)
{
	char	**dup_map;
	int		i;
    int len;

    len = 0;
    while (map[len])
    {
        len++;
    }
	dup_map = malloc(sizeof(char *) * (len + 1));
	if (dup_map == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup_map[i] = ft_strdup(map[i]);
		if (dup_map[i] == NULL)
			return (free_array(dup_map), NULL);
		i++;
	}
	dup_map[i] = NULL;
	return (dup_map);
}

int parse_map(t_data *data)
{
    char **map_dup;
    
    data->map = dup_only_map(data);
    if (!data->map)
        return (1);
    if (is_valid_char_in_map(data->map))
        return (1);
    map_dup = duplicate_map(data->map);
    if (!map_dup)
        return (1);
    flood_fill(map_dup, data);
	if (check_after_fill(data, map_dup) == false)
		return (free_array(map_dup), 1);
	free_array(map_dup);
    printf("\ngood\n");
    return (0);
}

// ligne vide a la fin, probleme ?