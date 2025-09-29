/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 16:09:29 by armosnie          #+#    #+#             */
/*   Updated: 2025/09/29 16:10:45 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// int	is_valid_map(char **map)
// {
// 	int i;
// 	int j;
// 	int count;
	
// 	i = 0;
// 	count = 0;
// 	while (map[i])
// 	{
// 		j = 0;
// 		while (map[i][j])
// 		{
// 			if (!ft_strncmp("NO", &map[i][j], 2))
// 				count += 1;
// 			else if (!ft_strncmp("SO", &map[i][j], 2))
// 				count += 2;
// 			else if (!ft_strncmp("WE", &map[i][j], 2))
// 				count += 3;
// 			else if (!ft_strncmp("EA", &map[i][j], 2))
// 				count += 4;
// 			else if (!ft_strncmp("F", &map[i][j], 2))
// 				count += 5;
// 			else if (!ft_strncmp("C", &map[i][j], 2))
// 				count += 6;
// 			j++;
// 		}
// 		i++;
// 		if (count == 21)
// 			return ();
// 	}
// 	return (0);
// }