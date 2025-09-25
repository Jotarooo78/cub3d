/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_text_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 16:27:44 by armosnie          #+#    #+#             */
/*   Updated: 2025/09/25 14:39:34 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	detect_features(char **map)
{
	int	i;
	int	count;
	char *trimmed;

	i = 0;
	count = 0;
	while (map[i])
	{
		trimmed = ft_strtrim(map[i], " \t\n");
		if (!trimmed)
			return (-1);
		if (trimmed[0] == 'N' || trimmed[0] == 'S' || trimmed[0] == 'W'
				|| trimmed[0] == 'E' || trimmed[0] == 'F' || trimmed[0] == 'C')
			count++;
		free(trimmed);
		i++;
		if (count == 6)
			return (i);
	}
	return (-1);
}

char	**transform_array(char *line)
{
	char	*formate_line;
	char	**split;

	formate_line = ft_strtrim(line, " \n\t");
	if (!formate_line)
		return (NULL);
	split = ft_split(formate_line, ' ');
	if (!split || !split[0] || !split[1] || split[2])
		return (free(formate_line), NULL);
	free(formate_line);
	return (split);
}

int	manage_features(t_data *data)
{
	int		i;
	char	**split;
	int		ret;
	int		len;

	i = 0;
	len = detect_features(data->map);
	if (len == -1)
		return (1);
	while (i < len)
	{
		split = transform_array(data->map[i]);
		if (!split)
			return (1);
		ret = check_features(split[0]);
		if (ret != 0)
			if (init_features_data(data, split, ret) != 0)
				return (free_array(split), 1);
		free_array(split);
		i++;
	}
	return (0);
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
	close(fd);
	return (tmp);
}

int	parse(t_data *data, char *file)
{
	int		fd;
	char	*str;
	char	*join;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (error(data, "fd error"), 1);
	str = get_next_line(fd);
	join = join_map(str, fd);
	if (join == NULL)
		return (error(data, "invalid map format\n"), 1);
	data->map = ft_split(join, '\n');
	free(join);
	if (!data->map)
		return (error(data, "map doesn't exist\n"), 1);
	if (manage_features(data))
		return (1);
	if (prep_flood_fill(data))
		return (1); // pas oublier de free data->map
	return (0);
}

// faire les bons messages erreurs
// s'occuper des leaks
