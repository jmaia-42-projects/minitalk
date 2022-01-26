NAME		=	minitalk

SRCS_COMMON	=
SRCS_CLIENT	=	$(SRCS_COMMON) $(addprefix client/, main.c send_message.c)
SRCS_SERVER	=	$(SRCS_COMMON) $(addprefix server/, print_pid.c \
													main.c \
													handle_messages.c)

OBJS_CLIENT	=	$(addprefix build/, ${SRCS_CLIENT:.c=.o})
OBJS_SERVER	=	$(addprefix build/, ${SRCS_SERVER:.c=.o})

CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra
LIBS_COMMON	=	$(addprefix libs/, ft_printf_fd/libftprintf.a)
LIBS_CLIENT	=	$(addprefix libs/, libft/libft.a) $(LIBS_COMMON)
LIBS_SERVER	=	$(LIBS_COMMON) $(addprefix libs/, 	libdynamic_buffer/libdynamic_buffer.a)
INCLUDE		=	-I includes/  -I libs/libft/ -I libs/libdynamic_buffer/includes/ \
				-I libs/ft_printf_fd/includes/ -I includes/server/

export BUILD	?=	$(PWD)/build

all		:	$(NAME)

build/%.o	:	srcs/%.c
	@if [ ! -d $(dir $@) ]; then\
		mkdir -p $(dir $@);\
	fi
	cc ${CFLAGS} ${INCLUDE} -c $< -o $@

$(NAME)	:	client server

libs/ft_printf_fd/libftprintf.a	:
	make -C libs/ft_printf_fd

libs/libft/libft.a	:
	make -C libs/libft/

client	:	$(LIBS_CLIENT) $(OBJS_CLIENT)
	$(CC) $(CFLAGS) $(OBJS_CLIENT) $(LIBS_CLIENT) -o client

server	:	$(OBJS_SERVER) $(LIBS_SERVER)
	$(CC) $(CFLAGS) $(OBJS_SERVER) $(LIBS_SERVER) -o server

libs/libdynamic_buffer/libdynamic_buffer.a	:
	make -C libs/libdynamic_buffer

clean	:	
	rm -Rf build/

fclean	:	clean
	rm -f ${NAME}

re		:	fclean ${NAME}

relibs	:
	make -C libs/ft_printf_fd re
	make -C libs/libft re

reall	:	relibs re

.PHONY	:	all clean fclean re reall
