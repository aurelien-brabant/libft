# Makefile for criterion test suites

TARGET=test.out
CC=clang
CFLAGS= -Wno-format-security -D_GNU_SOURCE -I../include
LD_FLAGS=-lcriterion -lbsd -L.. -lft

SRCS	= $(wildcard ./suite/*suite.c)
OBJS	= $(SRCS:%.c=%.o)

all: $(TARGET)

$(TARGET): libft.a $(OBJS)
	@$(CC) -o $(TARGET) $(OBJS) $(LD_FLAGS)
	@printf "\033[0;32mtest.out \033[0mcreated!\n"

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(TARGET)

re: fclean all

libft.a:
	make -C ..

%.o: %.c
	@$(CC) $(CFLAGS) -g -c $< -o $@
	@printf "[\033[1;34mTESTER\033[0m] \033[1;37mCC \033[0;33m$<\033[0m\n"
