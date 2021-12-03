SRCS		=	ft_printf.c parse.c flags.c format_utils.c parse_field.c

SRCS_BONUS	=

OBJS		=	${SRCS:.c=.o}

OBJS_BONUS	=	${SRCS_BONUS:.c=.o}

NAME		=	libftprintf.a

CFLAGS		=	-Wall -Werror -Wextra

INCLUDE		=	includes/

all		:	$(NAME)

build/%.o	:	srcs/%.c
	cc ${CFLAGS} -I ${INCLUDE} -c $< -o $@

libs	:
	make -C libs/libft
	make -C libs/libdynamic_buffer

build	:
	mkdir build

$(NAME)	:	build libs $(addprefix build/,${OBJS})
	ar rc ${NAME} ${OBJS}

clean	: cleanlibs
	rm -Rf build/

cleanlibs	:
	make -C libs/libft clean
	make -C libs/libdynamic_buffer clean

fclean	:	fcleanlibs clean
	rm -f ${NAME}

fcleanlibs	:
	make -C libs/libft fclean
	make -C libs/libdynamic_buffer fclean

re		:	fclean	${NAME}
	make -C libft/ re

bonus	:	$(NAME) $(OBJS_BONUS)
	ar r $(NAME) $(OBJS_BONUS)

.PHONY	:	all clean fclean re bonus libs
