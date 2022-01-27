SRCS				=	buffer_convert.c dynamic_buffer.c adjust.c

OBJS				=	${SRCS:.c=.o}

NAME				=	libdynamic_buffer.a

CFLAGS				=	-Wall -Werror -Wextra -g3

INCLUDE				=	includes/

export BUILD		?=	${PWD}/build

export LIB_FOLDER	?=	${PWD}/lib

all				:	$(NAME)

${BUILD}/%.o	:	srcs/%.c
	cc ${CFLAGS} -I ${INCLUDE} -c $< -o $@

${BUILD}		:
	mkdir ${BUILD}

$(NAME)			:	${BUILD} $(addprefix ${BUILD}/,${OBJS})
	ar rc ${NAME} $(addprefix ${BUILD}/, ${OBJS})

clean			:
	rm -Rf build/

fclean			:	clean
	rm -f ${NAME}

re				:	fclean	${NAME}

.PHONY			:	all clean fclean re
