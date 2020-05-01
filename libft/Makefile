# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvaldes <mvaldes@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/12 11:18:52 by mvaldes           #+#    #+#              #
#    Updated: 2020/05/01 12:18:44 by mvaldes          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_atoi.c\
			ft_bzero.c\
			ft_digit_len.c\
			ft_find_index.c\
			ft_get_index.c\
			ft_is_on_set.c\
			ft_is_printf_prms.c\
			ft_itoa.c\
			ft_memset.c\
			ft_putchar.c\
			ft_putnbr_base.c\
			ft_putstr.c\
			ft_strdup.c\
			ft_strlen.c\
			ft_strremove.c\
			ft_strstr.c\
			ft_substr.c\

OBJS	= ${SRCS:.c=.o}

NAME	= libft.a

RM	= rm -f

.c.o: $(SRCS)
	gcc -Wall -Wextra -Werror -c $^ -o ${^:.c=.o}

$(NAME):    $(OBJS) libft.h
	ar rcs $(NAME) $(OBJS)

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY: all clean fclean re
