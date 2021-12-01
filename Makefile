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

libft	:
	make -C libft/

build	:
	mkdir build

$(NAME)	:	build libft $(addprefix build/,${OBJS})
	ar rcl libft/libft.a ${NAME} ${OBJS}

clean	:
	rm -Rf build/
	make -C libft/ clean

fclean	:	clean
	rm -f ${NAME}
	make -C libft/ fclean

re		:	fclean	${NAME}
	make -C libft/ re

bonus	:	$(NAME) $(OBJS_BONUS)
	ar r $(NAME) $(OBJS_BONUS)

.PHONY	:	all clean fclean re bonus libft
