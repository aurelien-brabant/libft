# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/30 15:22:25 by abrabant          #+#    #+#              #
#    Updated: 2021/03/25 22:51:15 by abrabant         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ~~~~~~~~~~ COMPILATION ~~~~~~~~~~

CC						= clang

CFLAGS					= -Wall -Wextra -Werror

INCLUDE_PATH			= ./include/

# ~~~~~~~~~~   PROJECT   ~~~~~~~~~~
NAME					= libft.a

# ~~~~~~~~~~   SOURCES   ~~~~~~~~~~

VPATH					= ./src/cstring:./src/ctype:./src/io:./src/io/gnl:	\
						./src/io/printf:									\
						./src/strconv:./src/intconv:./src/unicode:			\
						./src/core:./src/vector:./src/cla:					\
						./src/array:./src/string

CORE				 	= ft_calloc.c ft_realloc.c ft_bsort.c				\
						ft_clamp.c

CSTRING					= ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strdup.c	\
						ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strnstr.c	\
						ft_strnstr.c ft_memset.c ft_memcpy.c ft_memccpy.c	\
						ft_memmove.c ft_memcmp.c ft_memchr.c ft_substr.c	\
						ft_split.c ft_strjoin.c ft_strtrim.c ft_strmapi.c	\
						ft_strrev.c ft_strlwr.c ft_strupr.c ft_strinsrt.c	\
						ft_strcasestr.c ft_strchri.c ft_strhsprfx.c			\
						ft_strhssfx.c ft_strndup.c ft_strcmp.c				\
						ft_strtrim_uniq.c ft_strtok.c ft_strcmpset.c

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

STRCONV					= ft_atoi.c ft_btoll.c

INTCONV					= ft_itoa.c ft_lltob.c ft_ulltob.c ft_ulllenb.c

UNICODE					= ft_runelen.c ft_buf_utf8.c ft_encode_utf8.c

VECTOR					= ft_vec_new.c ft_vec_cap.c ft_vec_len.c			\
						ft_vec_add.c ft_vec_foreach.c ft_vec_get.c			\
						ft_vec_destroy.c ft_vec_del.c ft_vec_cat.c			\
						ft_vec_set.c ft_vec_map.c ft_vec_set_len.c			\
						ft_vec_sort.c

ARRAY					= ft_array_new.c ft_array_append.c					\
						ft_array_foreach.c ft_array_destroy.c				\
						ft_array_insert.c ft_array_delete.c					\
						ft_array_linsearch.c ft_array_binsearch.c			\
						ft_array_get.c ft_array_set.c						\
						ft_array_reverse.c ft_array_shift.c					\
						ft_array_rotate.c ft_array_issorted.c				\
						ft_array_sinsert.c ft_array_dup.c					\
						ft_array_concat.c ft_array_merge.c					\
						ft_array_union.c ft_array_sunion.c					\
						ft_array_inter.c ft_array_sinter.c					\
						ft_array_sub.c ft_array_ssub.c						\
						ft_array_uniq.c	ft_array_suniq.c					\
						ft_array_get_length.c ft_array_get_size.c			\
						ft_array_int_resize.c

CLA						= ft_cla_init.c ft_cla_str_var.c ft_cla_int_var.c	\
						ft_cla_bool_var.c ft_cla_pos_var.c					\
						ft_cla_sanity_check.c ft_cla_get_config.c

STRING					= ft_string_new_fill.c ft_string_output.c			\
						  ft_string_new_cstr.c ft_string_destroy.c			\
						  ft_string_tocstring.c ft_string_append_cstr.c		\
						  ft_string_append.c ft_string_at.c					\
						  ft_string_length.c ft_string_size.c				\
						  ft_string_capacity.c ft_string_reserve.c


SRCS					= $(CORE) $(CSTRING) $(CTYPE) $(IO) $(STRCONV)		\
						$(INTCONV) $(UNICODE) $(VECTOR) $(CLA) $(ARRAY)		\
						$(STRING)

# ~~~~~~~~~~   OBJECTS   ~~~~~~~~~~

OBJ_DIR					= ./.obj
OBJS					= $(SRCS:%.c=$(OBJ_DIR)/%.o)

# ~~~~~~~~~~   RULES    ~~~~~~~~~~


all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@printf "\033[0;32m$(NAME) \033[0mcreated.\n"

clean:
	@rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

install:
	./install.sh

# Test the libft

norm:
	norminette ./src
	norminette ./include

test: $(NAME)
	@make re -C test
	@printf "\033[0;35mRunning tests\033[0m...\n"
	@./test/test.out

# Compilation rule for each C file.
$(OBJ_DIR)/%.o:%.c
	@$(CC) $(CFLAGS) -I$(INCLUDE_PATH) -g -c $< -o $@
	@printf "[\033[1;35mLIBFT\033[0m] \033[1;37mCC \033[0;33m$<\033[0m\n"

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

.PHONY: all clean fclean re test
