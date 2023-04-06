# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edfirmin <edfirmin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/28 11:52:12 by edfirmin          #+#    #+#              #
#    Updated: 2023/04/06 10:21:40 by edfirmin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
ft_memset.c ft_strlen.c ft_tolower.c ft_toupper.c ft_putchar_fd.c \
ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_bzero.c ft_strdup.c \
ft_strchr.c ft_strrchr.c ft_memcpy.c ft_strlcpy.c ft_strlcat.c ft_atoi.c \
ft_memchr.c ft_memcmp.c ft_strncmp.c ft_strnstr.c ft_calloc.c ft_memmove.c \
ft_strjoin.c ft_substr.c ft_itoa.c ft_strtrim.c ft_split.c

FLG = -Wall -Werror -Wextra

OBJ = $(SRC:.c=.o)

.c.o :
	gcc $(FLG) -c $< -o ${<:.c=.o}

all : $(NAME)

$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all