/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 14:58:53 by armosnie          #+#    #+#             */
/*   Updated: 2025/09/26 14:32:10 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
	free(array);
}

void	free_struct_data(t_data *data)
{
    if (!data)
        return ;
    if (data->text->no)
        free(data->text->no);
    if (data->text->so)
        free(data->text->so);
    if (data->text->we)
        free(data->text->we);
    if (data->text->ea)
        free(data->text->ea);
    if (data->text->fl)
        free(data->text->fl);
    if (data->text->ce)
        free(data->text->ce);
    if (data->map)
        free_array(data->map);
}

void error(t_data *data, char *str)
{
	perror(str);
	free_struct_data(data);
    free(data->text);
    free(data);
}