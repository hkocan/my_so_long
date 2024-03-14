NAME = so_long

CC   = cc
RM   = rm -rf
CFLAGS = -Wall -Wextra -Werror
NORMINETTE  = norminette

LIBFT_PATH	=	./inc/libft
LIBFT		=	$(LIBFT_PATH)/libft.a

OBJ_PATH = ./obj
SRC_PATH = ./src

SRC = $(SRC_PATH)/main.c					\
	  $(SRC_PATH)/exit_helper.c				\
	  $(SRC_PATH)/solong_utils.c 			\
	  $(SRC_PATH)/checker/check.c 			\
	  $(SRC_PATH)/checker/check_utils.c		\
	  $(SRC_PATH)/render/render_helper.c	\
	  $(SRC_PATH)/render/render.c

OBJ = $(SRC:$(SRC_PATH)%.c=$(OBJ_PATH)/%.o)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@ mkdir -p $(@D)
	@ $(CC) $(CFLAGS) -Imlx -O3 -c $< -o $@

$(NAME): $(OBJ) $(LIBFT)
	@ $(MAKE) -C ./inc/mlx
	@ $(CC) $(OBJ) -L./inc/mlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(LIBFT)
	@ echo "\nSo_long is compiled\n"

$(LIBFT):
	@ $(MAKE) -C $(LIBFT_PATH) all
	 
all: $(NAME)

clean:
	$(MAKE) -C $(LIBFT_PATH) clean
	$(RM) $(OBJ_PATH)

fclean: clean
	$(MAKE) -C $(LIBFT_PATH) fclean
	$(MAKE) -C ./inc/mlx clean
	$(RM) $(NAME)

re: fclean all

norm:
	@ $(NORMINETTE) $(SRC) ./inc/solong.h ./inc/libft

.PHONY: all clean fclean re norm
