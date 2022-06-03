# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aoustani <aoustani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/20 18:15:28 by aoustani          #+#    #+#              #
#    Updated: 2022/06/02 18:05:37 by aoustani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC =	ft_strlen.c		\
		ft_strchr.c		\
		ft_strlcpy.c	\
		ft_strstr.c		\
		ft_strlcat.c	\
		ft_strdup.c		\
		ft_strjoin.c	\
		ft_itoa.c		\
		ft_count_digit.c\
		get_next_line.c \
		get_next_line_utils.c \

OBJECTS = $(SRC:.c=.o)

INCLUDES = libft.h

all: $(NAME)

bonus: $(OBJECTS) $(OBJECTS_BONUS)
	ar rcs $(NAME) $(OBJECTS) $(OBJECTS_BONUS)

$(NAME): $(OBJECTS) $(INCLUDES) $(OBJECTS_BONUS)
	ar rcs $(NAME) $(OBJECTS) $(OBJECTS_BONUS)

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJECTS) $(OBJECTS_BONUS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
