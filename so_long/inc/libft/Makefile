NAME = libft.a

RM = rm -rf
CC = cc
CFLAGS = -Wall -Wextra -Werror

OBJ_DIR = ./obj

NORMINETTE  = norminette


SRC =	ft_split.c		\
		ft_strchr.c		\
		ft_strdup.c		\
		ft_strjoin.c	\
		ft_strlcpy.c	\
		ft_strlen.c		\
		ft_strncmp.c	\
		ft_strrchr.c	\
		ft_strtrim.c	\
		ft_substr.c		\
		ft_printf.c		\
		ft_calloc.c		\
		get_next_line.c

OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ ar rc $(NAME) $(OBJ)
	@ echo "\nLibft is compiled\n"

$(OBJ_DIR)/%.o: %.c
	@ mkdir -p $(OBJ_DIR)
	@ $(CC) $(CFLAGS) -c $< -o $@

clean:
	@ $(RM) $(OBJ_DIR)

fclean: clean
	@ $(RM) $(NAME)

norm:
	$(NORMINETTE)

re: fclean all

.PHONY: all clean fclean re norm
