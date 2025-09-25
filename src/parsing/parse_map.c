/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 17:02:05 by armosnie          #+#    #+#             */
/*   Updated: 2025/09/25 12:13:55 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int is_invalid_map(char **map)
{
    int i;
    int j;
    
	i = detect_features(map) + 1;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == '1' && map[i][j + 1] == '1')
                break ;
            j++;
        }
        while (map[i][j] && map[i][j] == '1')
            j++;
        if (map[i][j] == '\n' && map[i + 1][0] == '\n')
            return (printf("false\n"), 1);
        i++;
    }
    return (printf("end\n"), 0);
}

int	start_of_map(char **map)
{
	int	i;
    char *trimmed;

    i = detect_features(map) + 1;
    if (is_invalid_map(map) == 1)
        return (-1);
    while (map[i])
    {
        trimmed = ft_strtrim(map[i], " \t\n");
        if (!trimmed)
            return (-1);
        if (trimmed[0] == '1' && trimmed[1] == '1')
            return (free(trimmed), i);
        free(trimmed);
        i++;
    }
	return (-1);
}

char    **dup_map(t_data *data)
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
    free_array(data->map);
    return (new_map);
}

int	pos_depart(t_data *data)
{
	int i;
	int j;
	int stop;

	i = detect_features(data->map);
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
	// printf("vertical : %d, horizontal : %d, char de depart : %c\n", i, j, data->map[i][j]);
    return (0);
}

int prep_flood_fill(t_data *data)
{
    // char *fill_map;
    
    data->map = dup_map(data);
    // fill_map = ft_strdup(data->map);
    // if (!fill_map)
    //     return (1);
    print_array(data->map);
    return (0);
}

// ligne vide a la fin, probleme ?