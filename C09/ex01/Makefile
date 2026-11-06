NAME =  libft.a
SRCS = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c
OBJS = ${SRCS:.c=.o}
CC = cc
CFLAG = -Wall -Wextra -Werror
HEAD = includes
AR = ar rcs
RM = rm -f

all: ${NAME}

%.o: %.c
	${CC} ${CFLAG} -I ${HEAD} -c $< -o $@

${NAME}: ${OBJS}
	${AR} ${NAME} ${OBJS}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all	

.PHONY: all clean fclean re
