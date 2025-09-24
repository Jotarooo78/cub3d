/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 16:19:11 by armosnie          #+#    #+#             */
/*   Updated: 2025/09/24 14:45:23 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int check_ext(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (len < 4)
		return (1);
	if (ft_strncmp(&file[len - 4], ".cub", 4) == 0)
		return (0);
	return (1);
}

void	print_array(char **array)
{
	int i;
	
	i = 0;
	while (array[i])
	{
		printf("%s\n", array[i]);
		i++;
	}
	printf("\n");
}
