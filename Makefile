NAME = cub3D
CC = cc
CFLAGS = -Wall -Wextra -Werror -MMD -g3
LDFLAGS = -L./minilibx -L./libft
LDLIBS = -lmlx -lm -lft
RM = rm -f

# Détection de l'OS pour MinilibX
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	LDLIBS += -lXext -lX11
endif
ifeq ($(UNAME_S),Darwin)
	LDLIBS += -framework OpenGL -framework AppKit
endif

SRCS = \
	src/main.c \
	src/parsing/utils.c \
	src/parsing/check_map.c \

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