NAME = cub3D
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
LDFLAGS = -L./minilibx -L./libft
LDLIBS = -lmlx -lm -lft
RM = rm -f

SRCS = \
	src/main.c \
	src/parsing/parser.c \
	src/parsing/map_parser.c \
	src/parsing/texture_parser.c \
	src/parsing/color_parser.c \
	src/parsing/map_validator.c \
	src/parsing/file_reader.c \
	src/parsing/parser_utils.c \
	src/raycasting/raycaster.c \
	src/raycasting/ray_utils.c \
	src/raycasting/dda_algorithm.c \
	src/raycasting/wall_calculation.c \
	src/raycasting/texture_calculation.c \
	src/graphics/window_manager.c \
	src/graphics/image_manager.c \
	src/graphics/texture_loader.c \
	src/graphics/renderer.c \
	src/graphics/pixel_operations.c \
	src/player/player_init.c \
	src/player/player_movement.c \
	src/player/player_rotation.c \
	src/events/key_handler.c \
	src/events/mouse_handler.c \
	src/events/window_events.c \
	src/utils/error_handler.c \
	src/utils/memory_manager.c \
	src/utils/math_utils.c \
	src/utils/string_utils.c \
	src/utils/cleanup.c \

OBJ_DIR = obj
DEP_DIR = $(OBJ_DIR)
OBJS = $(SRCS:src/%.c=$(OBJ_DIR)/%.o)
DEPS = $(OBJS:.o=.d)

LIBFT = libft/libft.a
MINILIBX = minilibx/libmlx.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MINILIBX)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) $(LDLIBS) -o $(NAME)


$(LIBFT):
	make -C libft

$(MINILIBX):
	make -C minilibx

$(OBJ_DIR)/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I./libft -I./minilibx -I./includes -c $< -o $@

-include $(DEPS)

clean:
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)
	make fclean -C libft
	make clean -C minilibx

re: fclean all

.PHONY: all clean fclean re