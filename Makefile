NAME		=	minitalk

SRCS_CLIENT	=	$(addprefix srcs/, )
SRCS_SERVER	=	$(addprefix srcs/, )

OBJS_CLIENT	=	$(addprefix build/,${SRCS_CLIENT:.c=.o})
OBJS_SERVER	=	$(addprefix build/,${SRCS_SERVER:.c=.o})

CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra
INCLUDE		=	includes/
LIBS_COMMON	=	$(addprefix libs/, )
LIBS_CLIENT	=	$(LIBS_COMMON) $(addprefix libs/, )
LIBS_SERVER	=	$(LIBS_COMMON) $(addprefix libs/, ft_printf/libftprintf.a)

all		:	$(NAME)

build/%.o	:	srcs/%.c
	@if [ ! -d $(dir $@) ]; then\
		mkdir -p $(dir $@);\
	fi
	cc ${CFLAGS} -I ${INCLUDE} -c $< -o $@

$(NAME)	:	client server

client	:	$(OBJS_CLIENT)
	$(CC) $(CFLAGS) $(OBJS_CLIENT) -o $(NAME)

server	:	$(OBJS_SERVER) $(LIBS_SERVER)
	$(CC) $(CFLAGS) $(OBJS_SERVER) $(LIBS_SERVER) -o $(NAME)

libs/ft_printf/libftprintf.a	:
	make -C libs/ft_printf

clean	:	
	rm -Rf build/

fclean	:	clean
	rm -f ${NAME}

re		:	fclean ${NAME}

.PHONY	:	all clean fclean re client server
