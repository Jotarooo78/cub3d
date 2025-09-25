/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 14:11:56 by armosnie          #+#    #+#             */
/*   Updated: 2025/09/25 13:56:28 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_features_init_check(t_data *data)
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
	return (1);
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

int	check_dup(t_data *data, int ret)
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

int   init_color(t_text *text, char *path, int ret)
{
	char **split_path;

    split_path = ft_split(path, ',');
	if (!split_path)
		return (1);
	if (ret == 5)
	{
		text->fl->r = ft_atoi(split_path[0]);
		text->fl->g = ft_atoi(split_path[1]);
		text->fl->b = ft_atoi(split_path[2]);
		text->fl->rgb = text->fl->r + text->fl->g + text->fl->b;
	}
	else
	{
		text->ce->r = ft_atoi(split_path[0]);
		text->ce->g = ft_atoi(split_path[1]);
		text->ce->b = ft_atoi(split_path[2]);
		text->ce->rgb = text->ce->r + text->ce->g + text->ce->b;
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
	if (check_dup(data, ret) == 1)
		return (1);
	return (0);
}
