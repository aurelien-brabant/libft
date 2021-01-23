#!/bin/bash

# Criterion is pretty simple to use, however I wrote this script to make
# running the tests easier.

# Syntax: ./run.sh full or ./run.sh [ft_strdup, ft_calloc, ...]

# CONSTS
CC=clang
LIBPATH="../libft"
LIBINC="$LIBPATH/include"

RUN_ALL=false
SUITES=()

while [ $# -gt 0 ]
do
	key="$1"
	case $key in
		all)
		RUN_ALL=true
		break
		;;
		*)
		if [ -f "suite/${1}_suite.c" ]; then
			SUITES+=("$1_suite.c")
		else
			printf "\033[0;31mCould not find \033[0;34m$1_suite.c\033[0m.\n\n"
		fi
		shift
		;;
	esac
done

# Run all the suites. Suites must be prefixed by "ft_" and suffixed by "_suite".

if [ $RUN_ALL == "true" ]; then
	$CC -I$LIBINC -L$LIBPATH suite/ft_*_suite.c -Wno-format-security -lft -lcriterion -lbsd -D_GNU_SOURCE -o runner.out
	./runner.out
	rm -rf runner.out
	exit 0
fi

for suite in "${SUITES[@]}"
do
	$CC -I$LIBINC -L$LIBPATH suite/$suite -Wno-format-security -lft -lcriterion -lbsd -D_GNU_SOURCE -o runner.out
	./runner.out --verbose
	rm -rf runner.out
done
