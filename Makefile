# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alouisy- <alouisy-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/23 13:56:12 by alouisy-          #+#    #+#              #
#    Updated: 2017/03/23 13:56:14 by alouisy-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = computor

SRCS = computorv1.c

OBJS = $(SRCS:.c=.o)

LIBS = -L libft/ -lft

INCLUDES = -I. -I libft/includes/.

CFLAGS = -Werror -Wall -Wextra

all: $(NAME)

$(NAME):
	@make -C libft/
	@gcc $(CFLAGS) -c $(SRCS) $(INCLUDES)
	@gcc $(CFLAGS) -o $(NAME) $(OBJS) $(INCLUDES) $(LIBS)
	@echo "\"computor\" has been succefully created !"

clean:
	@make -C libft/ clean
	@/bin/rm -rf $(OBJS)
	@echo "COMPUTOR Object files deleted."

fclean: clean
	@make -C libft/ fclean
	@/bin/rm -rf $(NAME)
	@echo "COMPUTOR Executable deleted."

re: fclean all

.PHONY: clean
