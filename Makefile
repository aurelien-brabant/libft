# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/30 15:22:25 by abrabant          #+#    #+#              #
#    Updated: 2020/11/06 16:11:22 by abrabant         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ~~~~~~~~~~ COMPILATION ~~~~~~~~~~

CC						= clang 

CFLAGS					= -Wall -Wextra -Werror

INCLUDE_PATH			= includes/

# ~~~~~~~~~~   PROJECT   ~~~~~~~~~~

NAME					= libft.a

# ~~~~~~~~~~   SOURCES   ~~~~~~~~~~

SRCS					= ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strdup.c \
						ft_atoi.c ft_strchr.c ft_strrchr.c ft_strncmp.c		\
						ft_strnstr.c ft_isascii.c ft_bzero.c ft_memset.c	\
						ft_memcpy.c ft_memccpy.c ft_calloc.c ft_memmove.c	\
						ft_memcmp.c ft_isprint.c ft_isalnum.c ft_isdigit.c	\
						ft_isalpha.c ft_toupper.c ft_tolower.c ft_memchr.c	\
						ft_strmapi.c ft_substr.c ft_strjoin.c ft_strtrim.c	\
						ft_split.c ft_itoa.c ft_putchar_fd.c 				\
						ft_putnbr_fd.c ft_putstr_fd.c ft_putendl_fd.c

BONUS_SRCS				= ft_lstnew.c ft_lstsize.c ft_lstadd_front.c		\
						ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c		\
						ft_lstclear.c ft_lstiter.c ft_lstmap.c


# ~~~~~~~~~~   OBJECTS   ~~~~~~~~~~

# Objects required by the mandatory part
OBJS					= $(SRCS:.c=.o) 

BONUS_OBJS				= $(BONUS_SRCS:.c=.o)

# ~~~~~~~~~~   RULES    ~~~~~~~~~~


all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

bonus: $(OBJS) $(BONUS_OBJS)
	ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus

# Compilation rule for each C file
.c.o:
	$(CC) $(CFLAGS) -I$(INCLUDE_PATH) -g -c $< -o $(<:.c=.o)
