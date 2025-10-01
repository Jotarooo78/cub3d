/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 14:11:56 by armosnie          #+#    #+#             */
/*   Updated: 2025/09/30 16:10:03 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_features_init(t_data *data, int ret)
{
	if (ret == 1 && data->text->no)
		return (1);
	else if (ret == 2 && data->text->so)
		return (1);
	else if (ret == 3 && data->text->we)
		return (1);
	else if (ret == 4 && data->text->ea)
		return (1);
	else if (ret == 5 && data->text->fl->r && data->text->fl->g
		&& data->text->fl->b)
		return (1);
	else if (ret == 6 && data->text->ce->r && data->text->ce->g
		&& data->text->ce->b)
		return (1);
	return (0);
}

int	check_features(char *str)
{
	if (!ft_strcmp("NO", str))
		return (1);
	if (!ft_strcmp("SO", str))
		return (2);
	if (!ft_strcmp("WE", str))
		return (3);
	if (!ft_strcmp("EA", str))
		return (4);
	if (!ft_strcmp("F", str))
		return (5);
	if (!ft_strcmp("C", str))
		return (6);
	return (0);
}

int	is_dup_failed(t_data *data, int ret)
{
	if (ret == 1 && !data->text->no)
		return (1);
	if (ret == 2 && !data->text->so)
		return (1);
	if (ret == 3 && !data->text->we)
		return (1);
	if (ret == 4 && !data->text->ea)
		return (1);
	if (ret == 5 && !data->text->fl)
		return (1);
	if (ret == 6 && !data->text->ce)
		return (1);
	return (0);
}

int	init_color(t_text *text, char *path, int ret)
{
	char	**split_path;

	split_path = ft_split(path, ',');
	if (!split_path)
		return (1);
	if (ret == 5)
	{
		text->fl->r = ft_atoi(split_path[0]);
		text->fl->g = ft_atoi(split_path[1]);
		text->fl->b = ft_atoi(split_path[2]);
		if (text->fl->r > 255 || text->fl->g > 255 || text->fl->b > 255)
			return (printf("Error\nColor value must be between 0 and 255\n"),
				1);
	}
	else
	{
		text->ce->r = ft_atoi(split_path[0]);
		text->ce->g = ft_atoi(split_path[1]);
		text->ce->b = ft_atoi(split_path[2]);
		if (text->ce->r > 255 || text->ce->g > 255 || text->ce->b > 255)
			return (printf("Error\nColor value must be between 0 and 255\n"),
				1);
	}
	free_array(split_path);
	return (0);
}

int	init_features_data(t_data *data, char **split, int ret)
{
	if (ret == 1)
		data->text->no = ft_strdup(split[1]);
	if (ret == 2)
		data->text->so = ft_strdup(split[1]);
	if (ret == 3)
		data->text->we = ft_strdup(split[1]);
	if (ret == 4)
		data->text->ea = ft_strdup(split[1]);
	if (ret == 5)
		if (init_color(data->text, split[1], ret))
			return (1);
	if (ret == 6)
		if (init_color(data->text, split[1], ret))
			return (1);
	if (is_dup_failed(data, ret) == 1)
		return (1);
	return (0);
}
