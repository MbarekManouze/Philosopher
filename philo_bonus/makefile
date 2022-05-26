# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmanouze <mmanouze@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/26 12:27:18 by mmanouze          #+#    #+#              #
#    Updated: 2022/05/26 12:28:31 by mmanouze         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS_BONUS = main.c nothing.c utils.c initializing.c libft_utils.c \

OBJ_BONUS = $(SRCS_BONUS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) -o $(NAME) -fsanitize=address

clean :
	rm -f $(OBJ_BONUS)

fclean : clean
	rm -f $(NAME)
re : fclean all

.PHONY : clean all fclean re bonus