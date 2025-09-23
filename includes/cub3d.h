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

typedef struct s_color
{
	int		r;
	int		g;
	int		b;
	int		rgb;

}			t_color;

typedef struct s_text
{
	char	*no;
	char	*so;
	char	*ea;
	char	*we;
	char	*fl;
	char	*ce;

}			t_text;

typedef struct s_data
{
	char	**map;
	t_color	*color;
	t_text	*text;

}			t_data;

// ---- FUNCTIONS ----

// check map

int			parse(t_data *data, char *file);

// error

void		free_array(char **array);
void		error(t_data *data, char *str);

// utils

int			check_ext(char *file);
void		print_array(char **array);

#endif