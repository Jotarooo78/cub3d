/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 12:22:36 by armosnie          #+#    #+#             */
/*   Updated: 2025/10/02 12:28:13 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int    longest_line(char **map)
{
    int i;
    int j;
    int max;
    
    i = 0;
    max = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
            j++;
        if (j > max)
            max = j;
        i++;
    }
    return (max);
}