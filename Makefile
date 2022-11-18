NAME = get_next_line.a

AR = ar -crs

FLAGS = -Wall -Wextra -Werror

CC = cc

SRC = 		   get_next_line.c\
				get_next_line_utils.c

BNS =		   get_next_line_bonus.c\
				get_next_line_utils_bonus.c

OBJ = ${SRC:.c=.o}

BOBJ = ${BNS:.c=.o}

all: ${NAME}

${NAME}: ${OBJ}
	${AR} ${NAME} ${OBJ}

bonus: all ${BOBJ}
	${AR} ${NAME} ${BOBJ}

%.o: %.c get_next_line.h get_next_line_bonus.h
	${CC} ${FLAGS} -c $<

clean:
	rm -f ${OBJ} ${BOBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all re fclean clean
