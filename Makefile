NAME = fractol 
CC = clang
LIB = libft/libft.a
FLAGS = -g -Wall -Werror -Wextra -Ofast 
LIBGRPH = -L./minilibx_macos -lmlx -framework OpenGL -framework AppKit -D_REENTRANT -lpthread
INCLUDES = -I includes -I libft/includes -I minilibx_macos
OBJS = main.o parsing.o line.o init.o fractals.o handler.o
.PHONY: all clean fclean re

VPATH = sources/:minilibx_macos

all: $(NAME)

$(NAME): $(LIB) $(OBJS) 
	$(CC) $(FLAGS) $(INCLUDES) $(OBJS) $(LIB) -o $(NAME) $(LIBGRPH)

$(LIB):
	make -C libft/
	make -C minilibx_macos

%.c : %.h

%.o : %.c 
	$(CC) -c $(FLAGS) $(INCLUDES) $< -o $@ 

clean:
	rm -f $(OBJS)

fclean: clean
	make fclean -C libft/
	make clean -C minilibx_macos
	rm -f $(NAME)
	rm -rf $(NAME).dsym

re: fclean all
