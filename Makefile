NAME = cub3D
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
LDFLAGS = -L./libx -L./libft
LDLIBS = -lmlx -lm -lft
RM = rm -f

SRCS = \
	src/main.c \
	src/parsing/parse_text_color.c \
	src/parsing/parse_map.c \
	src/parsing/utils.c \
	src/parsing/error.c \
	src/parsing/check.c \

OBJ_DIR = obj
DEP_DIR = $(OBJ_DIR)
OBJS = $(SRCS:src/%.c=$(OBJ_DIR)/%.o)
DEPS = $(OBJS:.o=.d)

LIBFT = libft/libft.a
LIBX = libx/libmlx.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(LIBX)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) $(LDLIBS) -o $(NAME)


$(LIBFT):
	make -C libft

$(LIBX):
	make -C libx

$(OBJ_DIR)/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I./libft -I./libx -I./includes -c $< -o $@

-include $(DEPS)

clean:
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)
	make fclean -C libft
	make clean -C libx

re: fclean all

.PHONY: all clean fclean re