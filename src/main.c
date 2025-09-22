/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 15:28:12 by armosnie          #+#    #+#             */
/*   Updated: 2025/09/22 14:23:25 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_data *init_data(void)
{
    t_data *data;

    data = malloc(sizeof(t_data));
    if (!data)
        return (NULL);
    data->map = NULL;
    return (data);
}

int main(int argc, char **argv)
{
    t_data *data;
    
    if (argv[1] == NULL || (argc == 2 && !check_ext(argv[1])))
    {
        data = init_data();
        if (!data)
            return (1);
        parse(data, argv);
    }
    return (0);
}