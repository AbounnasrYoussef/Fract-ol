CC = cc
CFLAGS = -Wall -Wextra -Werror
FRAMEWORKS = -framework OpenGL -framework AppKit
MLX = -lmlx

SRC = drawe.c events.c fractol.c init.c math.c utile.c
OBJ = $(SRC:.c=.o)
HEADER = fractol.h

NAME = fractol

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(FRAMEWORKS) $(MLX) $^ -o $@

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean : 
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all