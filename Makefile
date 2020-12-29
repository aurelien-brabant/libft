# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/30 15:22:25 by abrabant          #+#    #+#              #
#    Updated: 2020/12/29 00:28:09 by abrabant         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ~~~~~~~~~~ COMPILATION ~~~~~~~~~~

CC						= clang 

CFLAGS					= -Wall -Wextra -Werror

INCLUDE_PATH			= ./include/

# ~~~~~~~~~~   PROJECT   ~~~~~~~~~~
NAME					= libft.a

# ~~~~~~~~~~   SOURCES   ~~~~~~~~~~

VPATH					= ./src/string:./src/ctype:./src/io:./src/io/gnl:	\
						./src/io/printf:									\
						./src/strconv:./src/intconv ./src/unicode			\
						./src/core ./src/dvector

CORE				 	= ft_calloc.c ft_realloc.c

STRING					= ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strdup.c	\
						ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strnstr.c	\
						ft_strnstr.c ft_memset.c ft_memcpy.c ft_memccpy.c	\
						ft_memmove.c ft_memcmp.c ft_memchr.c ft_substr.c	\
						ft_split.c ft_strjoin.c ft_strtrim.c ft_strmapi.c	\
						ft_strrev.c ft_strlwr.c ft_strupr.c ft_strinsrt.c	\
						ft_strcasestr.c ft_strchri.c ft_strhsprfx.c			\
						ft_strhssfx.c ft_strndup.c

CTYPE					= ft_isascii.c ft_isdigit.c ft_isalnum.c			\
						ft_isalpha.c ft_isprint.c ft_tolower.c ft_toupper.c	\
						ft_isspace.c

# Special project files for IO

GNL_CORE				= ft_gnl_utils.c

PRINTF_CORE				= parse.c conv_int.c utils.c field_width.c			\
						init_conv.c conv_str.c lenspec.c conv_cur_written.c	\
						buf.c conv_char.c conv_pct.c 						

IO						= ft_putnbr_fd.c ft_putstr_fd.c ft_putchar_fd.c		\
						$(GNL_CORE) ft_gnl.c $(PRINTF_CORE)					\
						ft_printf.c	ft_snprintf.c ft_sprintf.c ft_dprintf.c	\
						ft_vprintf.c ft_vsprintf.c ft_vsnprintf.c

STRCONV					= ft_atoi.c

INTCONV					= ft_itoa.c ft_lltob.c ft_ulltob.c ft_ulllenb.c

UNICODE					= ft_runelen.c ft_buf_utf8.c ft_encode_utf8.c

DVECTOR					= ft_dvec_make.c ft_dvec_add.c ft_dvec_get.c			\
						  ft_dvec_destroy.c ft_dvec_del.c

SRCS					= $(CORE) $(STRING) $(CTYPE) $(IO) $(STRCONV)		\
						$(INTCONV) $(UNICODE) $(DVECTOR) 

# ~~~~~~~~~~   OBJECTS   ~~~~~~~~~~

OBJ_DIR					= ./.obj
OBJS					= $(SRCS:%.c=$(OBJ_DIR)/%.o)

# ~~~~~~~~~~   RULES    ~~~~~~~~~~


all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	@printf "****** \033[1;35mBuilding \033[0;32m$(NAME)\033[0m ******\n"
	@printf "ar rcs \033[1;35m$(NAME) \033[0;36m$(OBJS) \033[0m\n"
	@ar rcs $(NAME) $(OBJS)
	@printf "****** \033[1;35mBuild \033[0mof \033[0;32m$(NAME)\033[0m should have succeeded ******\n"

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus

# Compilation rule for each C file.
$(OBJ_DIR)/%.o:%.c
	@printf "\033[1;34mCompiling \033[0;36m$<\033[0m\n" 
	@$(CC) $(CFLAGS) -I$(INCLUDE_PATH) -g -c $< -o $@

$(OBJ_DIR):
	mkdir $(OBJ_DIR)
