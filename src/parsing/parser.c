/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 16:27:44 by armosnie          #+#    #+#             */
/*   Updated: 2025/09/23 16:34:36 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_features_init(t_data *data)
{
	int	count;

	count = 0;
	if (data->text->no)
		count++;
	if (data->text->so)
		count++;
	if (data->text->we)
		count++;
	if (data->text->ea)
		count++;
	if (data->text->fl)
		count++;
	if (data->text->ce)
		count++;
	if (count == 6)
		return (0);
	printf("no : %s - so : %s - we : %s - ea : %s - fl : %s - ce : %s\n", data->text->no, data->text->so, data->text->we, data->text->ea, data->text->fl, data->text->ce);
	return (1);
}

int	check_features(char **split)
{
	if (ft_strcmp("NO", split[0]))
		return (1);
	if (ft_strcmp("SO", split[0]))
		return (2);
	if (ft_strcmp("WE", split[0]))
		return (3);
	if (ft_strcmp("EA", split[0]))
		return (4);
	if (ft_strcmp("F", split[0]))
		return (5);
	if (ft_strcmp("C", split[0]))
		return (6);
	return (printf("51 : ret 1\n"), 0);
}

int	init_features_data(t_data *data, char **split, int ret)
{
	// probleme ici
	char	*tmp;
	char	*new_tmp;
	int		i;

	i = 0;
	tmp = ft_strdup("");
	if (!tmp)
		return (1);
	while (i != 2)
	{
		new_tmp = ft_strjoin(tmp, split[i]);
		if (!new_tmp)
			return (free(tmp), 1);
		free(tmp);
		tmp = new_tmp;
		i++;
	}
	if (ret == 1)
		data->text->no = tmp;
	if (ret == 2)
		data->text->so = tmp;
	if (ret == 3)
		data->text->we = tmp;
	if (ret == 4)
		data->text->ea = tmp;
	if (ret == 5)
		data->text->fl = tmp;
	if (ret == 6)
		data->text->ce = tmp;
	return (free(tmp), 0);
}

int	detect_map(char **map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'W'
				|| map[i][j] == 'E' || map[i][j] == 'F' || map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
		if (count == 6)
			return (i);
	}
	return (-1);
}

int	manage_features(t_data *data)
{
	int		i;
	char	*formate_line;
	char	**split;
	int		ret;
	int		len;

	i = 0;
	len = detect_map(data->map);
	if (len == -1)
		return (1);
	while (i < len)
	{
		formate_line = ft_strtrim(data->map[i], " \n\t");
		if (!formate_line)
			return (1);
		split = ft_split(formate_line, ' ');
		if (!split || !split[0] || !split[1] || split[2])
			return (free(formate_line), 1);
		free(formate_line);
		ret = check_features(split);
		if (ret != 0)
			if (init_features_data(data, split, ret) != 0)
				return (free_array(split), printf("138 : ret 1\n"), 1);
		free_array(split);
		i++;
	}
	if (is_features_init(data) == 1)
		return (printf("143 : ret 1\n"), 1);
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
	print_array(data->map);
	if (!data->map)
		return (error(data, "map doesn't exist\n"), 1);
	if (manage_features(data))
		return (printf("189 : ret 1\n"), 1); // pas oublier de free data->map
	return (printf("good parcing\n"), 0);
}
