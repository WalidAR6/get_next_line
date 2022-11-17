NAME = get_next_line.a

AR = ar -crs

FLAGS = -Wall -Wextra -Werror

CC = cc

SRC = 		   get_next_line.c\
				get_next_line_utils.c

OBJ = ${SRC:.c=.o}

all: ${NAME}

${NAME}: ${OBJ}
	${AR} ${NAME} ${OBJ}

%.o: %.c get_next_line.h
	${CC} ${FLAGS} -c $<

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all re fclean clean
