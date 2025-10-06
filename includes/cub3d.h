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

}			t_color;

/**
 * @brief Holding data for directions.
 * @param no North
 * @param s
 */
typedef struct s_text
{
	char	*no;
	char	*so;
	char	*ea;
	char	*we;
	t_color	*fl;
	t_color	*ce;

}			t_text;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	char	**map;
	int		map_y;
	int		map_x;
	int		p_x;
	int		p_y;
	char	player;
	t_text	*text;

}			t_data;

// ---- FUNCTIONS ----

// main

int			parse(t_data *data, char *file);

// parse map

int			parse_map(t_data *data);
int			start_of_map(char **map);
int			is_valid_map(char **map);
int			player_position(t_data *data);

// parse text color

int			detect_features(char **map);

// check

int			is_features_init(t_data *data, int ret);
int			check_features(char *str);
int			check_dup(t_data *data, int ret);
int			init_features_data(t_data *data, char **split, int ret);

// error

void		free_array(char **array);
void		error(t_data *data, char *str);
void		error_2(t_data *data, char *str);
void		free_everything(t_data *data);

// utils : split with delimiter

char		**split_with_delimiter(const char *s, char c);

// utils

int			check_ext(char *file, char *ext);
void		print_array(char **array);
int			skip_whitespace(char c);
int			is_valid_char_in_map(char **map);
int			count_map(char **map);
int			longest_line(char **map);
void		get_map_x_y(t_data *data);
char		*strdup_with_longest_line(t_data *data, char *s1);

#endif