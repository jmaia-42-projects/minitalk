NAME		=	minitalk

SRCS_COMMON	=
SRCS_CLIENT	=	$(SRCS_COMMON) $(addprefix client/, main.c)
SRCS_SERVER	=	$(SRCS_COMMON) $(addprefix server/, )

OBJS_CLIENT	=	$(addprefix build/, ${SRCS_CLIENT:.c=.o})
OBJS_SERVER	=	$(addprefix build/, ${SRCS_SERVER:.c=.o})

CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra
INCLUDE		=	-I includes/ -I libs/ft_printf/includes/
LIBS_COMMON	=	$(addprefix libs/, )
LIBS_CLIENT	=	$(LIBS_COMMON) $(addprefix libs/, )
LIBS_SERVER	=	$(LIBS_COMMON) $(addprefix libs/, ft_printf/libftprintf.a)

all		:	$(NAME)

build/%.o	:	srcs/%.c
	@if [ ! -d $(dir $@) ]; then\
		mkdir -p $(dir $@);\
	fi
	cc ${CFLAGS} ${INCLUDE} -c $< -o $@

$(NAME)	:	client server

client	:	$(OBJS_CLIENT)
	$(CC) $(CFLAGS) $(OBJS_CLIENT) -o client

server	:	$(OBJS_SERVER)
	$(CC) $(CFLAGS) $(OBJS_SERVER) -o server

clean	:	
	rm -Rf build/

fclean	:	clean
	rm -f ${NAME}

re		:	fclean ${NAME}

.PHONY	:	all clean fclean re client server
