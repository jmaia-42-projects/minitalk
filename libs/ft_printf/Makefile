OBJS_LIBDYNAMIC_BUFFER	=	buffer_convert.o dynamic_buffer.o

OBJS_LIBFT				=	ft_isalpha.o ft_isdigit.o ft_isalnum.o ft_isascii.o \
				ft_isprint.o ft_strlen.o ft_memset.o ft_bzero.o ft_memcpy.o \
				ft_memmove.o ft_strlcpy.o ft_strlcat.o ft_toupper.o \
				ft_tolower.o ft_strchr.o ft_strrchr.o ft_strncmp.o ft_memchr.o \
				ft_memcmp.o ft_strnstr.o ft_atoi.o ft_calloc.o ft_strdup.o \
				ft_substr.o ft_strjoin.o ft_strtrim.o ft_split.o ft_itoa.o \
				ft_strmapi.o ft_striteri.o ft_putchar_fd.o ft_putstr_fd.o \
				ft_putendl_fd.o ft_putnbr_fd.o ft_itoa_base.o ft_isspace.o \
				ft_put_bytes_fd.o ft_uitoa_base.o

SRCS		=	is_sign.c conv_c.c conv_d.c \
				conv_general.c conv_p.c conv_percent.c \
				conv_s.c conv_u.c conv_x.c conv_xx.c \
				conv_x_common.c flags.c annoying_0_flag.c format_utils.c parse_field.c \
				annoying_prec0val0.c parse.c ft_printf.c

SRCS_BONUS	=

OBJS		=	${SRCS:.c=.o}

OBJS_BONUS	=	${SRCS_BONUS:.c=.o}

NAME		=	libftprintf.a

CFLAGS		=	-Wall -Werror -Wextra

INCLUDE		=	includes/

export BUILD ?=	$(dir $(abspath $(lastword $(MAKEFILE_LIST))))/build

all		:	$(NAME)

build/%.o	:	srcs/%.c
	@if [ ! -d $(dir $@) ]; then\
		mkdir -p $(dir $@);\
	fi
	cc ${CFLAGS} -I ${INCLUDE} -c $< -o $@ -g3

libs/libft/libft.a	:
	make -C libs/libft

libs/libdynamic_buffer/libdynamic_buffer.a	:
	make -C libs/libdynamic_buffer

$(NAME)	:	libs/libft/libft.a libs/libdynamic_buffer/libdynamic_buffer.a $(addprefix build/,${OBJS})
	ar rc ${NAME} $(addprefix build/,${OBJS} ${OBJS_LIBFT} ${OBJS_LIBDYNAMIC_BUFFER})

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

bonus	:	$(NAME)

.PHONY	:	all clean fclean re bonus
