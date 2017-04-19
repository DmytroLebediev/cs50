all: hash0

hash0: hash0.c distribution.c distribution.h
	clang -ggdb3 -O0 -std=c11 -Wall -Werror -Wextra -Wno-sign-compare -Wshadow -o hash0 hash0.c distribution.c -lm -lcs50

clean:
	rm -f *.o a.out core hash0