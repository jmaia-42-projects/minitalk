NAME		=	minitalk

SRCS_COMMON	=
SRCS_CLIENT	=	$(SRCS_COMMON) $(addprefix client/, )
SRCS_SERVER	=	$(SRCS_COMMON) $(addprefix server/, print_pid.c \
													main.c \
													handle_messages.c)

OBJS_CLIENT	=	$(addprefix build/, ${SRCS_CLIENT:.c=.o})
OBJS_SERVER	=	$(addprefix build/, ${SRCS_SERVER:.c=.o})

CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra -fcommon
INCLUDE		=	-I includes/ -I libs/libdynamic_buffer/includes/ \
				-I libs/ft_printf/includes/ -I includes/server/
LIBS_COMMON	=	$(addprefix libs/, )
LIBS_CLIENT	=	$(LIBS_COMMON) $(addprefix libs/, )
LIBS_SERVER	=	$(LIBS_COMMON) $(addprefix libs/, 	libdynamic_buffer/libdynamic_buffer.a \
													ft_printf/libftprintf.a)

export BUILD	?=	$(PWD)/build/

all		:	$(NAME)

build/%.o	:	srcs/%.c
	@if [ ! -d $(dir $@) ]; then\
		mkdir -p $(dir $@);\
	fi
	cc ${CFLAGS} ${INCLUDE} -c $< -o $@

$(NAME)	:	client server

client	:	$(OBJS_CLIENT)
	$(CC) $(CFLAGS) $(OBJS_CLIENT) -o client

server	:	$(OBJS_SERVER) $(LIBS_SERVER)
	$(CC) $(CFLAGS) $(OBJS_SERVER) $(LIBS_SERVER) -o server

libs/ft_printf/libftprintf.a	:
	make -C libs/ft_printf

libs/libdynamic_buffer/libdynamic_buffer.a	:
	make -C libs/libdynamic_buffer

clean	:	
	rm -Rf build/

fclean	:	clean
	rm -f ${NAME}

re		:	fclean ${NAME}

.PHONY	:	all clean fclean re client server
