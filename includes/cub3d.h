#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../libx/mlx.h"
# include "../libx/mlx_int.h"
# include <stdbool.h>
# include <unistd.h>

# define W 119
# define A 97
# define S 115
# define D 100
# define ESC 65307
# define CROIX 17

// ---- STRUCTS ----

typedef struct s_data
{
	char	**map;

}			t_data;

// ---- FUNCTIONS ----

// check map

void		parse(t_data *data, char **argv);

// utils

int			check_ext(char *file);

#endif