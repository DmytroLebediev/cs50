all: console1

console1: console1.c distribution.c distribution.h
	clang -ggdb3 -O0 -std=c11 -Wall -Werror -o console1 console1.c distribution.c -lm

clean:
	rm -f *.o a.out core console1