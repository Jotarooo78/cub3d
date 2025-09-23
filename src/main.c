/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 15:28:12 by armosnie          #+#    #+#             */
/*   Updated: 2025/09/23 15:50:45 by armosnie         ###   ########.fr       */
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
    data->color = malloc(sizeof(t_color));
    if (!data->color)
        return (NULL);
    data->text = malloc(sizeof(t_text));
    if (!data->text)
        return (NULL);
    data->text->no = NULL;
    data->text->so = NULL;
    data->text->we = NULL;
    data->text->ea = NULL;
    data->text->fl = NULL;
    data->text->ce = NULL;
    return (data);
}

// pas oublier de proteger la minilibx si c'est lancer avec -i un truc du genre

int main(int argc, char **argv)
{
    t_data *data;
    
    if (argv[1] == NULL || (argc == 2 && !check_ext(argv[1])))
    {
        data = init_data();
        if (!data)
            return (1);
        if (parse(data, argv[1]) != 0)
            return (1);
    }
    return (0);
}