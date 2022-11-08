flags = -Wall -Werror -Wextra

all: s21_grep

rebuild: clean all

s21_grep: grep.o grep_no_args.o grep_args.o
	gcc $(flags) grep.o grep_no_args.o grep_args.o -o s21_grep

grep.o: grep.c
	gcc $(flags) -c grep.c -o grep.o

grep_args.o: grep_args.c
	gcc $(flags) -c grep_args.c -o grep_args.o

grep_no_args.o: grep_no_args.c
	gcc $(flags) -c grep_no_args.c -o grep_no_args.o

clean:
	rm -rf *.o
	rm -rf s21_grep