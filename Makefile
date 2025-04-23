NAME = cub3d

SRC = collision.c \
	decals_parse.c \
	draw_utils.c\
	get_next_line_utils.c \
	get_next_line.c \
	hook.c \
	main.c \
	map_parse.c \
	parse.c\
	rotations.c \
	struct.c\
	wasd.c \
	  

OBJ_DIR = objs
LIBFT_DIR = includes/libft
MLX_DIR = includes/mlx

OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -Iincludes -I$(LIBFT_DIR) -I$(MLX_DIR)

LIBS = -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR)
	@$(MAKE) -C $(MLX_DIR)
	@$(CC) $(OBJ) $(CFLAGS) $(LIBS) -o $(NAME)
	@echo "Compilation terminée."

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(MAKE) clean -C $(LIBFT_DIR)
	@$(MAKE) clean -C $(MLX_DIR)
	@rm -f $(OBJ)
	@rm -rf $(OBJ_DIR)
	@echo "Fichiers objets supprimés."

fclean: clean
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@rm -f $(NAME)
	@echo "Exécutable supprimé."

re: fclean all

.PHONY: all clean fclean re
