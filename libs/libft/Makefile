# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/22 12:50:34 by jmaia             #+#    #+#              #
#    Updated: 2022/01/12 17:19:27 by jmaia            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
				ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c \
				ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c \
				ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c \
				ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c \
				ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
				ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
				ft_putendl_fd.c ft_putnbr_fd.c ft_itoa_base.c ft_isspace.c \
				ft_put_bytes_fd.c ft_uitoa_base.c ft_isnbr.c ft_isint.c \
				ft_strcmp.c ft_lstprevious.c ft_lstnew.c ft_lstadd_front.c \
				ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
				ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_lstcpy.c ft_lstsort.c

OBJS		=	${SRCS:.c=.o}

OBJS_BONUS	=	${SRCS_BONUS:.c=.o}

NAME		=	libft.a

CFLAGS		=	-Wall -Werror -Wextra

export BUILD		?=	${PWD}/build

all		:	$(NAME)

${BUILD}/%.o	:	%.c
		cc ${CFLAGS} -c $< -o $@

${BUILD}	:
	mkdir ${BUILD}

$(NAME)	:	${BUILD} $(addprefix ${BUILD}/,${OBJS})
		ar rc ${NAME} $(addprefix ${BUILD}/,${OBJS})

clean	:
		rm -rf ${BUILD}

fclean	:	clean
		rm -f ${NAME}

re		:	fclean	${NAME}

.PHONY	:	all clean fclean re
