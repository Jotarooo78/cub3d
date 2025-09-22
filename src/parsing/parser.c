/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 16:27:44 by armosnie          #+#    #+#             */
/*   Updated: 2025/09/22 17:27:43 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int formate_space(t_data *data, char **map)
{
    
}

int	check_textures(t_data *data, char **map)
{
	int	i;

	i = 0;
    if (formate_space(data, map))
        return (1);
	while (data->map[i])
	{
		if (ft_strcmp("NO", map[i]) == 0)
			init_map_features(data, map[i], "NO");
		if (ft_strcmp("SO", map[i]) == 0)
			init_map_features(data, map[i], "SO");
		if (ft_strcmp("WE", map[i]) == 0)
			init_map_features(data, map[i], "WE");
		if (ft_strcmp("EA", map[i]) == 0)
			init_map_features(data, map[i], "EA");
		i++;
	}
}

int	check_features(t_data *data)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (data->map[i])
	{
	}
}

char	*join_map(char *str, int fd)
{
	char	*new_tmp;
	char	*tmp;

	tmp = ft_strdup("");
	if (!tmp)
		return (NULL);
	while (str)
	{
		new_tmp = ft_strjoin(tmp, str);
		if (!new_tmp)
			return (free(str), free(tmp), close(fd), NULL);
		free(tmp);
		tmp = new_tmp;
		free(str);
		if (ft_strlen(tmp) > 10000)
			return (free(tmp), close(fd), NULL);
		str = get_next_line(fd);
	}
	if (double_backslash(tmp))
		return (free(tmp), close(fd), NULL);
	close(fd);
	return (tmp);
}

int	parse(t_data *data, char *file)
{
	int fd;
	char *str;
	char *join;

	fd = open("file", O_RDONLY);
	if (fd == -1)
		return (error("fd error\n"), 1);
	str = get_next_line(fd);
	join = join_map(str, fd);
	if (join == NULL)
		return (error("invalid map format\n"), 1);
	data->map = ft_split(join, '\n');
	free(join);
	if (!data->map)
		return (error("map doesn't exist\n"), 1);
	if (check_features(data))
		return (1); // pas oublier de free data->map
	return (0);
}
