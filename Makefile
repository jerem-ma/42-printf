SRCS		=	convs/is_sign.c convs/conv_c.c convs/conv_d.c \
				convs/conv_general.c convs/conv_p.c convs/conv_percent.c \
				convs/conv_s.c convs/conv_u.c convs/conv_x.c convs/conv_xx.c \
				convs/conv_x_common.c flags.c convs/annoying_0_flag.c format_utils.c parse_field.c \
				convs/annoying_prec0val0.c parse.c ft_printf.c

SRCS_BONUS	=

OBJS		=	${SRCS:.c=.o}

OBJS_BONUS	=	${SRCS_BONUS:.c=.o}

NAME		=	libftprintf.a

CFLAGS		=	-Wall -Werror -Wextra

INCLUDE		=	includes/

all		:	$(NAME)

build/%.o	:	srcs/%.c
	@if [ ! -d $(dir $@) ]; then\
		mkdir -p $(dir $@);\
	fi
	cc ${CFLAGS} -I ${INCLUDE} -c $< -o $@ -g3

libs	:
	make -C libs/libft
	make -C libs/libdynamic_buffer

$(NAME)	:	libs $(addprefix build/,${OBJS})
	ar rc ${NAME} $(addprefix build/,${OBJS})

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

relibs	:
	make -C libs/libft/ re
	make -C libs/libdynamic_buffer re

re		:	relibs fclean ${NAME}

bonus	:	$(NAME) $(OBJS_BONUS)
	ar r $(NAME) $(OBJS_BONUS)

.PHONY	:	all clean fclean re bonus libs
