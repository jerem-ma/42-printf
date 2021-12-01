SRCS		=	ft_printf.c

SRCS_BONUS	=

OBJS		=	${SRCS:.c=.o}

OBJS_BONUS	=	${SRCS_BONUS:.c=.o}

NAME		=	libftprintf.a

CFLAGS		=	-Wall -Werror -Wextra

INCLUDE		=	includes/

all		:	$(NAME)

build/%.o	:	srcs/%.c
	cc ${CFLAGS} -I ${INCLUDE} -c $< -o $@

build	:
	mkdir build

$(NAME)	:	build $(addprefix build/,${OBJS})
	ar rc ${NAME} ${OBJS}

clean	:
	rm -Rf build/

fclean	:	clean
	rm -f ${NAME}

re		:	fclean	${NAME}

bonus	:	$(NAME) $(OBJS_BONUS)
	ar r $(NAME) $(OBJS_BONUS)

.PHONY	:	all clean fclean re bonus
