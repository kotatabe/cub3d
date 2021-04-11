NAME = cub3D
SRC =	./srcs/*.c\
		./libmlx.dylib
# OBJS = $(SRC:.c=.o)
CC = gcc
INCS = -O2 -I include/
FLAG =  -Werror -Wextra -Wall
RM		:= rm -rf

$(NAME):
		$(CC) $(FLAG) $(SRC) -framework OpenGL -framework AppKit $(INCS)

all:	$(NAME)

clean:
		$(RM) $(OBJS)

fclean:	clean
		$(RM) $(NAME)

re:		fclean all

.PHONY: all clean fclean re
