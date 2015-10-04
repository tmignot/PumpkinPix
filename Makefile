FLAGS		=	-Werror -Wextra -Wall -g
SRC			=	pp.c	\
				parquetry.c	\

OBJ			=	$(SRC:.c=.o)

all:	pp

pp:	$(OBJ)
	gcc $^ -o pp
%.o:	%.c
	gcc -c $^ -o $@
clean:
	rm -rf $(OBJ)
fclean:	clean
	rm -rf pp
