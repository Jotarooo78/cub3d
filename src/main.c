/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 15:28:12 by armosnie          #+#    #+#             */
/*   Updated: 2025/10/01 18:09:31 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// int	init_game_data(t_data *data)
// {
// 	int	win_height;
// 	int	win_width;

// 	win_height = data->map_y * 16;
// 	win_width = data->map_x * 16;
// 	data->mlx = mlx_init();
// 	if (data->mlx == NULL)
// 		return (ft_putstr_fd("Error\nFailed to init mlx", 2), false);
// 	data->win = mlx_new_window(data->mlx, win_width, win_height, "so_long");
// 	if (data->win == NULL)
// 	{
// 		mlx_destroy_display(data->mlx);
// 		free(data->mlx);
// 		return (ft_putstr_fd("Error\nFailed to init window", 2), false);
// 	}
// 	return (true);
// }

void    init_color_to_0(t_data *data)
{
    data->text->fl->r = 0;
    data->text->fl->g = 0;
    data->text->fl->b = 0;
    data->text->ce->r = 0;
    data->text->ce->g = 0;
    data->text->ce->r = 0;
}

t_data *init_data(void)
{
    t_data *data;

    data = malloc(sizeof(t_data));
    if (!data)
        return (NULL);
    data->map = NULL;
    data->text = malloc(sizeof(t_text));
    if (!data->text)
        return (NULL);
    data->text->fl = malloc(sizeof(t_color));
    data->text->ce = malloc(sizeof(t_color));
    if (!data->text->fl || !data->text->ce)
        return (NULL);
    init_color_to_0(data);
    data->text->no = NULL;
    data->text->so = NULL;
    data->text->we = NULL;
    data->text->ea = NULL;
    data->p_x = 0;
    data->p_y = 0;
    data->player = 'X';
    return (data);
}

// pas oublier de proteger la minilibx si c'est lancer avec -i un truc du genre

int main(int argc, char **argv)
{
    t_data *data;
    
    data = NULL;
    if (argv[1] == NULL || (argc == 2 && !check_ext(argv[1])))
    {
        data = init_data();
        if (!data)
            return (1);
        if (parse(data, argv[1]) != 0)
            return (1);
    }
    free_everything(data);
    return (0);
}
