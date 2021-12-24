NAME 	= philo

RM		=	rm -f
FLAGS 	= -Wall -Werror -Wextra

PATH 	= srcs

SRC		=	main.c \
			init.c \
			live_philo.c \
			get_time.c

SRCS 	= $(addprefix $(PATH)/, $(SRC))

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) philo.h
		gcc $(FLAGS) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY:		all clean fclean re
