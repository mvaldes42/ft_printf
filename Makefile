# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvaldes <mvaldes@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/27 15:59:30 by mvaldes           #+#    #+#              #
#    Updated: 2020/03/06 11:18:40 by mvaldes          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

SRCS	=	ft_printf.c \
			ft_find_prms.c\
			ft_parse_prms.c\
			ft_cvt_prms.c\
			ft_make_lyt.c\
			ft_arg_out_str.c\
			ft_display.c\
			ft_display_dst.c\
			is_preci_zero.c\
			libft/ft_atoi.c\
			libft/ft_digit_len.c\
			libft/ft_find_index.c\
			libft/ft_get_index.c\
			libft/ft_is_on_set.c\
			libft/ft_is_printf_prms.c\
			libft/ft_itoa.c\
			libft/ft_memset.c\
			libft/ft_putchar.c\
			libft/ft_putnbr_base.c\
			libft/ft_putstr.c\
			libft/ft_strdup.c\
			libft/ft_strlen.c\
			libft/ft_strremove.c\
			libft/ft_strstr.c\
			libft/ft_substr.c\

OBJS := $(SRCS:.c=.o)

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -I.
RM		=	rm -f

all:		${NAME}
%.o:	%.c
	${CC} ${CFLAGS} -c $< -o $@ 
%.o:	libft/%.c
	${CC} ${CFLAGS} -c $< -o $@ 

${NAME}:	${OBJS}
			ar rcs ${NAME} libft/*.o ${OBJS}

debug:
	$(CC) $(CFLAGS) -g $(SRCS) libft/ft_*.c -I libft 

clean:
			${RM} ${OBJS}
fclean:		clean
	$(MAKE) -C libft fclean
	${RM} ${NAME} libft/*.o *.o

re:			fclean all
.PHONY:		all ${NAME} clean fclean re