NAME = philo

CC = cc
CFLAGS = -Wall -Wextra -Werror  #-g3 -fsanitize=thread  #-fsanitize=address
RM = rm -rf

SRCS = ft_init.c\
	ft_parsing.c\
	ft_utilis.c\
	main.c\
	monitor.c\
	routine.c\

OBJS = ${SRCS:.c=.o}

all : $(NAME)

$(NAME): $(OBJS)
	${CC}	${CFLAGS}	${OBJS}	-o	${NAME}

clean :
	${RM} ${OBJS}

fclean : clean
	${RM} ${NAME}

re : fclean all

.PHONY: all clean fclean re